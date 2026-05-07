/**
 * @file sch_event_management.c
 * @author Mike Strangewood (michael.a.strangewood@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-04-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "sch.h"
#include "sch_config.h"
#include "sch_event_management.h"

/*--Functions----------------------------------------------------------------*/

/**
 * @brief Portable function. Defines the "process" of scheduling and arbitrating
 * the processes
 * 
 * @param sch_task
 */
uint8_t sch_event_management(void) {
  #if SCH_EVENTS_STATE == SCH_EVENTS_ON
    #if SCH_ARBITRATION_MODE == SCH_ARBITRATION_MODE_SYSTICK

    #elif SCH_ARBITRATION_MODE == SCH_ARBITRATION_MODE_MANUAL
      uint8_t priority = sch_find_most_significant_task(sch_preempt_tasks_ready_set);
        if (priority > 0) {
          sch_task_t* task_to_run = sch_task_registry[priority - 1];
          if (task_to_run != NULL) {
              sch_task_run(task_to_run, NULL);
          }
        }
    #endif
  #elif SCH_EVENTS_STATE == SCH_EVENTS_OFF
    return 0;
  #endif
  return 0;
}