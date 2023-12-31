/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */

#ifndef AL_PWM_H
#define AL_PWM_H

/*---  Includes  ------------------------------------------------------------------------------- */
#include <stdint.h>

/* ---  Macros definitions  -------------------------------------------------------------------- */
/*
El reloj interno del micro esta a 8MHz y el periodo del PWM se calcula como:
T_PWM = (1+ARR) * T_CLK
Lo que significa que el ARR debe ser igual a: ARR = (T_PWM / T_CLK) - 1
Si F_PWM = 200KHz entonces ARR = 39
*/
#define PWM_PERIOD 39

/* ---  Typedef  ------------------------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */
void PWM_Init();
void PWM_ChangeDuty(uint32_t duty);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*---  End of File  ---------------------------------------------------------------------------- */
#endif