#include "sch.h"
#include "sch_config.h"
#include "sch_event_management.h"

/*
  todo:
  i know you do read this hehe
  
*/

void sch_event_management(sch_task_t* sch_task) {
  #if SCH_ARBITRATION_MODE == SCH_ARBITRATION_MODE_SYSTICK

  #elif SCH_ARBITRATION_MODE == SCH_ARBITRATION_MODE_MANUAL
    switch (sch_task -> priority) {
      case 1:
      //other cases
    }
  #endif
}