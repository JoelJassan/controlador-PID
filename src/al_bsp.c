/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */

/* ---  Headers files inclusions   ------------------------------------------------------------- */
#include <string.h>
#include "al_gpio.h"
#include "al_bsp.h"
#include "al_adc.h"
#include "al_bluepill.h"

/* ---  Macros definitions  -------------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */
static struct board_s board = {0};

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Private Function Declaration  ----------------------------------------------------------- */
static void config_relojext_init(void);

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */
static void config_relojext_init(void) {
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY))
        continue;
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_HSE;
    while (!((RCC->CFGR & RCC_CFGR_SWS_Msk) == RCC_CFGR_SWS_0))
        continue;
    RCC->CFGR &= ~(1 << 7);
    RCC->CFGR &= ~(1 << 10);
    RCC->CFGR &= ~(1 << 13);
    SystemCoreClockUpdate();
}

/*---  Public Function Definition  ------------------------------------------------------------- */
board_t board_Create(void) {

    /*  Configuracion de pines*/
    config_relojext_init();
    ADCConvertInit();
    // SysTick_Config(SystemCoreClock / 1000);
    /*  Entradas  */
    board.boton = DigitalInput_Create(KEY_F2_PORT, KEY_F2_PIN, false);
    /*  Salidas  */
    board.pwm = DigitalOutput_Create(PWM_PUERTO, PWM_PIN);
    board.led = DigitalOutput_Create(LED_PUERTO, LED_PIN);
    return &board;
}

/*---  Private Function Implementation  -------------------------------------------------------- */

/*---  Public Function Implementation  --------------------------------------------------------- */

/**  doxygen end group definition */
/*---  End of File  ---------------------------------------------------------------------------- */