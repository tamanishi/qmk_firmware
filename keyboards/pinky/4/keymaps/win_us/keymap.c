/* Copyright 2018 'Masayuki Sunahara'
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

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    LADJUST,
    RADJUST,
    ARROW
};

#define KC_LADJ LADJUST
#define KC_RADJ RADJUST

#define KC_EIS KC_F13
#define KC_KNA KC_F14
#define KC_CTL_ES CTL_T(KC_EIS)
#define KC_CTL_KN CTL_T(KC_KNA)

#define CTL_TAB CTL_T(KC_TAB)
#define LT_SPC LT(_ARROW, KC_SPC)
#define LT_LBRC LT(_ADJUST, KC_LBRC)
#define LT_RBRC LT(_ADJUST, KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_4x7_4(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_LPRN,    KC_RPRN, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LCBR,    KC_RCBR, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_LBRC,    KC_RBRC, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , LT_LBRC,    LT_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT,
                                   KC_LALT, KC_LGUI,KC_CTL_ES, LT_SPC,    LT_SPC ,KC_CTL_KN,KC_RGUI, KC_RALT
    ),
    [_LOWER] = LAYOUT_split_4x7_4(
        KC_GRV , _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_split_4x7_4(
        KC_GRV , _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_split_4x7_4(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,    _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_DEL,
        _______, KC_F11 , KC_F12 , _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS,KC_EQUAL, _______,
        _______, _______, KC_PSCR, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ARROW] = LAYOUT_split_4x7_4(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_UP  , _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______, _______,    _______, KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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
        case LADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        case RADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}
