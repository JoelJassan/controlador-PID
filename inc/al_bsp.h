/*
 *
 * Copyright xxx/2023, Joel Jassan <joeljassan@hotmail.com>
 * All rights reserved.
 *
 */

#ifndef AL_BSP_H
#define AL_BSP_H

/*---  Includes  ------------------------------------------------------------------------------- */
#include "al_gpio.h"
//#include "chip.h"

/* ---  Macros definitions  -------------------------------------------------------------------- */

/* ---  Typedef  ------------------------------------------------------------------------------- */
//! Estructura de la placa que se usará
struct board_s {
    DigitalInput_t  boton;
    DigitalOutput_t led;
    DigitalOutput_t pwm;
};
//! Creacion de un tipo de dato que es un puntero a una estructura de la placa.
typedef struct board_s * board_t;

/*---  Public Data Declaration  ---------------------------------------------------------------- */

/*---  Public Function Declaration  ------------------------------------------------------------ */

/**
 * @brief Board Create
 * Se encarga de crear una placa. En un principio solo tendra 1 entrada digital y 1 salida digital
 * @return board_t Retorna el puntero de la estructura de la placa.
 */
board_t board_Create(void);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*---  End of File  ---------------------------------------------------------------------------- */
#endif