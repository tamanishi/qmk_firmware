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

#define CTL_TAB CTL_T(KC_TAB)
#define KC_KNA KC_LNG1
#define KC_EIS KC_LNG2
#define LT_SPC LT(_ARROW, KC_SPC)
#define CMD_EISU LCMD_T(KC_EIS)
#define CMD_KANA RCMD_T(KC_KNA)
#define ADJ_LBR LT(_ADJUST, KC_LBRC)
#define ADJ_RBR LT(_ADJUST, KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x7_4(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LPRN,    KC_RPRN, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        CTL_TAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_LCBR,    KC_RCBR, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , ADJ_LBR,    ADJ_RBR, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT,
                                   KC_LALT, MO(_LOWER),CMD_EISU,LT_SPC ,  LT_SPC ,CMD_KANA,MO(_RAISE), KC_RALT
    ),
    [_LOWER] = LAYOUT_split_3x7_4(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_split_3x7_4(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_split_3x7_4(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_VOLU,    KC_VOLU, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, KC_F11 , KC_F12 , _______, _______, _______, KC_VOLD,    KC_VOLD, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_MUTE, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_ARROW] = LAYOUT_split_3x7_4(
        _______, _______, KC_UP  , _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_UP  , _______,
        _______, KC_LEFT, KC_DOWN,KC_RIGHT,KC_RIGHT, _______, _______,    _______, KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, KC_LEFT, _______,    _______, KC_DOWN, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    )
};
