# Structure of source files

`inc/sch.h` - main the list of contents (system's headers)
`inc/sch_common.h` - a header what inites the keywords within the system. Some technical things
`inc/sch_config.h` - the config what'll configure the system. Defines the quantity of tasks and the mode of arbitration
`inc/sch_context_change.h` - the header what creates the header of functions what will be implemented by the Assenbly or C code within the `port/`-files. These functions intended to switch the context
`inc/sch_event_management.h` - the basic functional for event-driven interaction - the ability to transmit the data between the tasks
`inc/sch_task_management.h` - the header what creates the header of functions what will be implemented by the Assenbly or C code within the `port/`-files. These functions intended to help to do the task management

`port/{platform}/sch_assertion.c` - implements the functions from the `sch_common.h`-file
`port/{platform}/sch_context_change.c` - implements the functions from the `sch_context_change.h`-file
`port/{platform}/sch_context_change.s` - implements the functions from the `sch_context_change.h`-file in Assembly
`port/{platform}/sch_event_management.c` - implements the functions from the `sch_event_management.h`-file in Assembly
`port/{platform}/sch_find_most_significant_task.s` - inplements the function of finding the most significant task by Assembly

# Simple example of creating the task:
```

void sch_task_dispatch(sch_task_t* task);
void sch_task_init(sch_task_t* task);

void main() {
  sch_task_t first_task;
  sch_task_create(&first_task, -3, 0, sch_task_dispatch, sch_task_init);
  sch_task_activate(&first_task);

}

void sch_task_dispatch(sch_task_t* task) {
  //something to do
}

void sch_task_init(sch_task_t* task) {
  //something to do
}

```

The `sch_task_create` attaches the task's parts to the main object to make it easy to call. For example, the typical dispatch function: `sch_task_dispatch` as the main task's function - that func describes what task will actually do. You can see the arguments of the function in the `sch/src/sch.c` file.
Also the `sch_task_init` function will use by the user as the start of the task. But keep in mind that the init function will call at the moment of creating the task itself.