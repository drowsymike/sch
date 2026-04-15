#ifndef SCH_EVENT_MANAGEMENT_H
#define SCH_EVENT_MANAGEMENT_H

#include "sch_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t sig;
} sch_event_header;

typedef struct {
    sch_event_header event_header;
    int16_t first_data;
    int16_t second_data;
} sch_event;

void sch_event_management(sch_task_t* sch_task);

#ifdef __cplusplus
}
#endif

#endif