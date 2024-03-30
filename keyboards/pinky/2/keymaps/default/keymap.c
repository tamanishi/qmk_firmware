/* Copyright 2019 'Masayuki Sunahara'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  DEFAULT = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

#define ________ KC_TRNS
#define XXXXXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJ  ADJUST

// There is no default actually.
// Customize as much as you like.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
  //,-------------------------------------------------.
        KC_ESC,  KC_HOME,    KC_UP,   KC_END,  KC_PGUP,\
  //|---------+---------+---------+---------+---------|
        KC_ESC,  KC_LEFT,  KC_DOWN, KC_RIGHT,  KC_PGDN,\
  //|---------+---------+---------+---------+---------|
                          KC_RAISE, KC_LOWER,   KC_ADJ \
                      //`-----------------------------'
  ),
  [_LOWER] = LAYOUT(
  //,-------------------------------------------------.
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
                          ________, ________, ________ \
                      //`-----------------------------'
  ),
  [_RAISE] = LAYOUT(
  //,-------------------------------------------------.
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
                          ________, ________, ________ \
                      //`-----------------------------'
  ),
  [_ADJUST] = LAYOUT(
  //,-------------------------------------------------.
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
      ________, ________, ________, ________, ________,\
  //|---------+---------+---------+---------+---------|
                          ________, ________, ________ \
                      //`-----------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // set_timelog();
  }

  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_ADJUST);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    default:
      break;
  }
  return true;
}

