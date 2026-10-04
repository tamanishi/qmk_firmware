#pragma once

#include "../pinky.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#define LAYOUT( \
  K00, K01, K02, K03, K04, \
  K10, K11, K12, K13, K14, \
  K20, K21, K22 \
  ) \
  { \
    { K00, K01, K02, K03, K04}, \
    { K10, K11, K12, K13, K14}, \
    { K20, K21, K22 } \
  }

#define LAYOUT_kc( \
  K00, K01, K02, K03, K04, \
  K10, K11, K12, K13, K14, \
  K20, K21, K22 \
  ) \
  LAYOUT( \
    KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, \
    KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, \
    KC_##K20, KC_##K21, KC_##K22 \
  )
