/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */

/* ---  Headers files inclusions   ------------------------------------------------------------- */
#include "stm32f1xx_hal.h"
#include "hal.h"
#include "al_adc.h"

/* ---  Macros definitions  -------------------------------------------------------------------- */

/*---  Private Data Declaration  --------------------------------------------------------------- */

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Private Function Declaration  ----------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */

/*---  Private Data Definition  ---------------------------------------------------------------- */

/*---  Public Data Definition  ----------------------------------------------------------------- */

/*---  Private Function Definition  ------------------------------------------------------------ */

/*---  Public Function Definition  ------------------------------------------------------------- */

/*---  Private Function Implementation  -------------------------------------------------------- */

/*---  Public Function Implementation  --------------------------------------------------------- */
void ADCConvertInit() {
    // Habilitar el reloj para el ADC1
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    // Configurar el canal de entrada del ADC (PA0)
    ADC1->SQR3 = 0;
    // Configurar la frecuencia de muestreo para una Fs de 20 kHz
    ADC1->SMPR2 = ADC_SMPR2_SMP0;
    // Habilitar el ADC
    ADC1->CR2 = ADC_CR2_ADON;
}
void ADC_StartConvert() {
    ADC1->CR2 |= ADC_CR2_ADON;
    while (!(ADC1->SR & ADC_SR_EOC))
        continue;
}
uint16_t ADC_GetValue() {
    return ADC1->DR;
}

/*---  End of File  ---------------------------------------------------------------------------- */