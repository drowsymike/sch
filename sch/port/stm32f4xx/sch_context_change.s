.thumb
.cpu cortex-m4

.equ __sch_scs_base, (0xE000E000UL)
.equ __sch_icsr_offset, (0xD04)
.equ __sch_icsr, (__sch_scs_base + __sch_icsr_offset)
.equ __sch_icsr_pendvset, (1 << 28)

.section .text.PendSV_Handler
.global PendSV_Handler
.type PendSV_Handler, %function

@ -----------------------------------------------------------------------------

PendSV_Handler:
    push {lr}
    ldr r0, =sch_system_tasks_ready_set
    ldr r0, [r0
    bl sch_find_most_significant_task
    cbz r0, .exit_pendsv
    sub r0, r0, #1
    bl sch_call_dispatch[cite: 17]
.exit_pendsv:
    pop {pc}

@ -----------------------------------------------------------------------------

.section .data
.global sch_context_change_interrupt_check
.align 2
sch_context_change_interrupt_check:
    .byte 1
    .align 2

@ -----------------------------------------------------------------------------

.section .text.sch_context_change

.type sch_call_dispatch, %function
.global sch_call_dispatch
sch_call_dispatch:
    @ Copying the R-registers. Must be founded out how to do that!
    @ mrs r0, psp
    @ stmdb r0!, {r4-r11}
    @ msr psp, r0
    ldr r1, =sch_task_registry
    lsl r0, r0, #2
    add r0, r1, r0
    ldr r0, [r0]
    ldr r3, [r0]
    blx r3
    bx lr

.type sch_context_change, %function
.global sch_context_change
sch_context_change:
    ldr r0, =__sch_icsr
    ldr r1, =__sch_icsr_pendvset
    str r1, [r0]
    bx lr

.type sch_context_change_interrupt_handler, %function
.global sch_context_change_interrupt_handler
sch_context_change_interrupt_handler:
    ldr r0, =sch_context_change_interrupt_check
    mov r1, #0
    str r1, [r0]
    bx lr
