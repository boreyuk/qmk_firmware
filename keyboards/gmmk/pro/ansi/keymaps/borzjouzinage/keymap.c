/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"

#define _LAYER0 0
#define _LAYER1 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      ESC      F1       F2       F3       F4       F5        F6       F7       F8       F9       F10      F11      F12      Prt           Rotary(Mute)
//      ~        1        2        3        4        5         6        7        8        9        0         -       (=)      BackSpc           Del
//      Tab      Q        W        E        R        T         Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G         H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V         B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                                SPACE                               Alt_R    FN       Ct_R     Left     Down     Right
    [_LAYER0] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_MPLY,
        KC_NUBS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PGUP,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_DEL,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_MNXT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
    
    [_LAYER1] = LAYOUT(
        KC_TRNS, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_PWR, KC_TRNS,
        KC_TRNS, BL_TOGG, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,
        KC_TRNS, BL_INC, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_END,
        KC_TRNS, BL_DEC, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,
        KC_TRNS, BL_STEP, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, KC_MPRV,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_RMOD, RGB_SPI) 
    
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
#endif  // ENCODER_ENABLE

#ifdef RGB_MATRIX_ENABLE
static void set_rgb_caps_leds_on(void);
static void set_rgb_caps_leds_off(void);
static void set_france_side_leds_on(void);
// static void set_side_leds_off(void);

void rgb_matrix_indicators_user()
{
    if (host_keyboard_led_state().caps_lock){
        set_rgb_caps_leds_on();
    } else {
        if(rgb_matrix_get_flags() == LED_FLAG_NONE){
            set_rgb_caps_leds_off();
        }
    }

    switch(get_highest_layer(layer_state)){
        case _LAYER0:
            set_france_side_leds_on();
            break;
        case _LAYER1:
            set_france_side_leds_on();
            rgb_matrix_set_color(LED_PRT, 255, 0, 0);
            rgb_matrix_set_color(LED_PGUP, 255, 255, 255);
            rgb_matrix_set_color(LED_PGDN, 255, 255, 255);
            rgb_matrix_set_color(LED_MPLY, 255, 255, 255);
            rgb_matrix_set_color(LED_DEL, 255, 255, 255);

            rgb_matrix_set_color(LED_2, 255, 255, 255);
            rgb_matrix_set_color(LED_W, 0, 255, 0);
            rgb_matrix_set_color(LED_S, 255, 0, 0);
            rgb_matrix_set_color(LED_X, 0, 0, 255);

            rgb_matrix_set_color(LED_N, 255, 255, 255);

            rgb_matrix_set_color(LED_LEFT, 255, 0, 0);
            rgb_matrix_set_color(LED_RIGHT, 0, 255, 0);
            rgb_matrix_set_color(LED_UP, 0, 0, 255);
            rgb_matrix_set_color(LED_DOWN, 0, 0, 255);
            break;
    }
}

static void set_rgb_caps_leds_on()
{
    rgb_matrix_set_color(LED_CAPS, 255, 0, 0);
    rgb_matrix_set_color(LED_TAB, 255, 0, 0);
    rgb_matrix_set_color(LED_GRV, 255, 0, 0);
    rgb_matrix_set_color(LED_LSFT, 255, 0, 0);
    rgb_matrix_set_color(LED_LCTL, 255, 0, 0);

    /*
    for(int i = 0; i<NB_LED_SIDE; i++){
        rgb_matrix_set_color(LED_SIDE_LEFT[i], 255, 0, 0);
        rgb_matrix_set_color(LED_SIDE_RIGHT[i], 255, 0, 0);
    }
    */
}

static void set_rgb_caps_leds_off()
{
    rgb_matrix_set_color(LED_CAPS, 0, 0, 0);
    rgb_matrix_set_color(LED_TAB, 0, 0, 0);
    rgb_matrix_set_color(LED_GRV, 0, 0, 0);
    rgb_matrix_set_color(LED_LSFT, 0, 0, 0);
    rgb_matrix_set_color(LED_LCTL, 0, 0, 0);
    /*
    for(int i = 0; i<NB_LED_SIDE; i++){
        rgb_matrix_set_color(LED_SIDE_LEFT[i], 0, 0, 0);
        rgb_matrix_set_color(LED_SIDE_RIGHT[i], 0, 0, 0);
    }
    */
}

static void set_france_side_leds_on()
{
    rgb_matrix_set_color(LED_SIDE_LEFT[0], 0, 0, 255);
    rgb_matrix_set_color(LED_SIDE_LEFT[1], 0, 0, 255);
    rgb_matrix_set_color(LED_SIDE_LEFT[2], 0, 0, 255);
    rgb_matrix_set_color(LED_SIDE_LEFT[3], 255, 255, 255);
    rgb_matrix_set_color(LED_SIDE_LEFT[4], 255, 255, 255);
    rgb_matrix_set_color(LED_SIDE_LEFT[5], 255, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[6], 255, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[7], 255, 0, 0);

    rgb_matrix_set_color(LED_SIDE_RIGHT[0], 255, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[1], 255, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[2], 255, 0, 0);

    rgb_matrix_set_color(LED_SIDE_RIGHT[3], 255, 255, 255);
    rgb_matrix_set_color(LED_SIDE_RIGHT[4], 255, 255, 255);

    rgb_matrix_set_color(LED_SIDE_RIGHT[5], 0, 0, 255);
    rgb_matrix_set_color(LED_SIDE_RIGHT[6], 0, 0, 255);
    rgb_matrix_set_color(LED_SIDE_RIGHT[7], 0, 0, 255);
}

/*
static void set_side_leds_off()
{
    rgb_matrix_set_color(LED_SIDE_LEFT[0], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[1], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[2], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[3], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[4], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[5], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[6], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_LEFT[7], 0, 0, 0);

    rgb_matrix_set_color(LED_SIDE_RIGHT[0], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[1], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[2], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[3], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[4], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[5], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[6], 0, 0, 0);
    rgb_matrix_set_color(LED_SIDE_RIGHT[7], 0, 0, 0);
}
*/

#endif
