/**
 * @file sch_config.h
 * @author Mike Strangewood (michael.a.strangewood@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-23
 * 
 */

#ifndef SCH_CONFIG_H
#define SCH_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief the SCH_MAX_QUANTITY_OF_TASKS macros 
 *   defines the max quantity of tasks
 */
#define SCH_MAX_QUANTITY_OF_TASKS 3

/**
 * @brief mode of SCH arbitration. There're options:
 *   Manual (SCH_ARBITRATION_MODE_MANUAL)
 *   Systick (SCH_ARBITRATION_MODE_SYSTICK)
 * 
 */
#define SCH_ARBITRATION_MODE SCH_ARBITRATION_MODE_MANUAL

#ifdef __cplusplus
}
#endif

#endif