/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */

/* ---  Headers files inclusions   ------------------------------------------------------------- */
#include "al_gpio.h"
#include "al_bsp.h"
#include "al_bluepill.h"
#include "al_adc.h"

#include <string.h>

/* ---  Macros definitions  -------------------------------------------------------------------- */
#define REFRESH_TIME 1000 //! Cuenta del Systick

/*---  Private Data Declaration  --------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */
static board_t board;

/*---  Private Function Declaration  ----------------------------------------------------------- */
// void SisTick_Init(uint16_t time);

/*---  Public Function Declaration  ------------------------------------------------------------ */

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------- */
int main(void) {
    int contador = 0;
    int divisor  = 50000;

    board        = board_Create();

    // SisTick_Init(REFRESH_TIME);

    while (true) {
        contador = (contador + 1) % divisor;
        if (contador > divisor / 2)
            DigitalOutput_Desactivate(board->led);
        else
            DigitalOutput_Activate(board->led);
    }

    // while (true) {
    //     ADC_StartConvert();
    //     uint16_t adcValue = ADC_GetValue();
    //     if (adcValue > 2048) {
    //         DigitalOutput_Activate(board->led);
    //     } else {
    //         DigitalOutput_Desactivate(board->led);
    //     }
    // }
}

// void SysTick_Handler(void) {
//     static uint16_t contador = 0;
//     //
//     contador = (contador + 1) % 1000;
//     if (contador > 500)
//         DigitalOutput_Activate(board->led);
//     else
//         DigitalOutput_Desactivate(board->led);
// }

/*---  Private Function Implementation  -------------------------------------------------------- */

/*---  Public Function Implementation  --------------------------------------------------------- */

/**  doxygen end group definition */
/*---  End of File  ---------------------------------------------------------------------------- */