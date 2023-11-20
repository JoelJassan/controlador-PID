/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */



#ifndef AL_ADC_H
#define AL_ADC_H

/*---  Includes  ------------------------------------------------------------------------------- */
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "hal.h"

/* ---  Macros definitions  -------------------------------------------------------------------- */

/* ---  Typedef  ------------------------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */
void     ADCConvertInit();
void     ADC_StartConvert();
uint16_t ADC_GetValue();

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*---  End of File  ---------------------------------------------------------------------------- */
#endif
