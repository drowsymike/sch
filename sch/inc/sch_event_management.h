/**
 * @file sch_event_management.h
 * @author Mike Strangewood (michael.a.strangewood@gmail.com)
 * @brief This file contains any solutions for implementing the communication 
 * between processes (or between a process and something outside)
 * @version 0.1
 * @date 2026-04-07
 * 
 */

/**
 * @note: In commentaries I'll name communcation between processes by the name
 * "P2P", and communication between a process and environment by the "P2E" name
 *
 */

#ifndef SCH_EVENT_MANAGEMENT_H
#define SCH_EVENT_MANAGEMENT_H

#include "sch_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#if SCH_EVENTS_STATE == SCH_EVENTS_ON

  /*--Structures---------------------------------------------------------------*/
  
  /**
   * @brief Structure for defining the header of packet (a particle) of 
   * communication between processes
   * 
   */
  typedef struct {
      uint16_t sig;
  } sch_event_header;

  /**
   * @brief Structure for defining for the package of communication intself
   * 
   */
  typedef struct {
      sch_event_header event_header;
      int16_t first_data;
      int16_t second_data;
  } sch_event;

  /*--Functions----------------------------------------------------------------*/

  /**
   * @brief Portable function. Defines the "process" of scheduling and arbitrating
   * the processes
   * 
   * @param sch_task
   */
  uint8_t sch_event_management(void);

  #ifdef __cplusplus
  }
  #endif

#endif

#endif