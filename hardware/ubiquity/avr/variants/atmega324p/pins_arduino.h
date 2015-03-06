/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            20
#define NUM_ANALOG_INPUTS           6
#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 14 : -1)

#if defined(__AVR_ATmega8__)
#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 10 || (p) == 11)
#else
//#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10 || (p) == 11)
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 22 || (p) == 23)
#endif

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 21;
static const uint8_t SCL = 20;
//static const uint8_t SDA = 18;
//static const uint8_t SCL = 19;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 20;
static const uint8_t A7 = 21;

static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;
static const uint8_t D8 = 8;
static const uint8_t D9 = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;

static const uint8_t PWM0 = 3;
static const uint8_t PWM1 = 5;
static const uint8_t PWM2 = 6;
static const uint8_t PWM3 = 9;
static const uint8_t PWM4 = 22; //10;
static const uint8_t PWM5 = 23; //11;

static const uint8_t TK_I0 = 14;	// = A0
static const uint8_t TK_I1 = 15;	// = A1
static const uint8_t TK_I2 = 16;	// = A2
static const uint8_t TK_I3 = 17;	// = A3
static const uint8_t TK_I4 = 18;	// = A4
static const uint8_t TK_I5 = 19;	// = A5
static const uint8_t TK_O0 = 3;		// = PWM0
static const uint8_t TK_O1 = 5;		// = PWM1
static const uint8_t TK_O2 = 6;		// = PWM2
static const uint8_t TK_O3 = 9;		// = PWM3
static const uint8_t TK_O4 = 10; 	// = PWM4
static const uint8_t TK_O5 = 11;	// = PWM5

static const uint16_t NG_X0 = (0 << 8) | 0;
static const uint16_t NG_Y0 = (1 << 8) | 0;
static const uint16_t NG_A0 = (2 << 8) | 0;
static const uint16_t NG_X1 = (0 << 8) | 1;
static const uint16_t NG_Y1 = (1 << 8) | 1;
static const uint16_t NG_A1 = (2 << 8) | 1;
static const uint16_t NG_X2 = (0 << 8) | 2;
static const uint16_t NG_Y2 = (1 << 8) | 2;
static const uint16_t NG_A2 = (2 << 8) | 2;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
//
// (PWM+ indicates the additional PWM pins on the ATmega168.)

// ATMEL ATMEGA1280 / ARDUINO
//
// 0-7 PE0-PE7   works
// 8-13 PB0-PB5  works
// 14-21 PA0-PA7 works 
// 22-29 PH0-PH7 works
// 30-35 PG5-PG0 works
// 36-43 PC7-PC0 works
// 44-51 PJ7-PJ0 works
// 52-59 PL7-PL0 works
// 60-67 PD7-PD0 works
// A0-A7 PF0-PF7
// A8-A15 PK0-PK7


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, /* 0 */
	PD,
	PB,
	PD,
	PB,
	PB,
	PB,
	PA,
	PA, /* 8 */
	PD,
	PB,
	PB,
	PB,
	PB,
	PA, /* 14 */
	PA,
	PA,
	PA,
	PA,
	PA,
	PC,
	PC,
	PB,
	PD, /* 23 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), /* 0 */
	_BV(1),
	_BV(2),
	_BV(6),
	_BV(0),
	_BV(1),
	_BV(3),
	_BV(6),
	_BV(7), /* 8 */
	_BV(5),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 14 C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(0),
	_BV(1),
	_BV(4), // _BV(6), /* 22 */
	_BV(7), // _BV(7), /* 23 */
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER, // 1
	NOT_ON_TIMER, // 2

	// on the ATmega168, digital pin 3 has hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER, // 3
#else
	TIMER2B,      // 3
#endif

	NOT_ON_TIMER, // 4
	// on the ATmega168, digital pins 5 and 6 have hardware pwm

#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER, // 5
	NOT_ON_TIMER, // 6
#else
	TIMER1B,	// TIMER0B, // 5
	TIMER0A,	// TIMER0A, // 6
#endif

	NOT_ON_TIMER,   // 7
	NOT_ON_TIMER,   /* 8 - port B */
	TIMER1A,        // 9
	NOT_ON_TIMER,   //TIMER1B, // 10

#if defined(__AVR_ATmega8__)
	TIMER2,         // 11
#else
	NOT_ON_TIMER, //TIMER2A, // 11
#endif

	NOT_ON_TIMER,	// 12
	NOT_ON_TIMER,	// 13
	NOT_ON_TIMER, /* 14 - port C */
	NOT_ON_TIMER,   // 15
	NOT_ON_TIMER,	// 16
	NOT_ON_TIMER,	//17
	NOT_ON_TIMER, /* 18 */
	NOT_ON_TIMER,	// 19
	NOT_ON_TIMER,	// 20
	NOT_ON_TIMER,	// 21
	TIMER0B, // NOT_ON_TIMER, // 22
	TIMER2A, // NOT_ON_TIMER, // 23
};

#endif

#endif
