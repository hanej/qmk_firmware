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
#include "gashole.h"

// clang-format off

// Custom keys
enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_MISSION_CONTROL = USER00,
#else
    KC_MISSION_CONTROL = SAFE_RANGE,
#endif
    KC_SPOTLIGHT,
    KC_DICTATION,
    KC_LAUNCHPAD,
    KC_HOMELOCK
};

// MacOS consumer keys
#define KC_MCTL KC_MISSION_CONTROL
#define KC_SPOT KC_SPOTLIGHT
#define KC_DICT KC_DICTATION
#define KC_LPAD KC_LAUNCHPAD

// Tap Dance
#ifdef TAP_DANCE_ENABLE
    #define TD_F1 KC_BRID
    #define TD_F2 KC_BRIU
    #define TD_F3 KC_MCTL
    #define TD_F4 KC_LPAD
    #define TD_F5 KC_SPOT
    #define TD_F6 KC_DICT
    #define TD_F7 KC_MRWD
    #define TD_F8 KC_MPLY
    #define TD_F9 KC_MFFD
    #define TD_F10 KC_MUTE
    #define TD_F11 KC_VOLD
    #define TD_F12 KC_VOLU

    enum {
        TD_ESC_CAPS,
        /*
        TD_F1,
        TD_F2,
        TD_F3,
        TD_F4,
        TD_F5,
        TD_F6,
        TD_F7,
        TD_F8,
        TD_F9,
        TD_F10,
        TD_F11,
        TD_F12
        */
    };

    qk_tap_dance_action_t tap_dance_actions[] = {
        // Tap dance for Escape, twice for Caps Lock
        [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        /*
        [TD_F1] = ACTION_TAP_DANCE_DOUBLE(KC_BRID, KC_F1),
        [TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_BRIU, KC_F2),
        [TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_MCTL, KC_F3),
        [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_LPAD, KC_F4),
        [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_SPOT, KC_F5),
        [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_DICT, KC_F6),
        [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_MRWD, KC_F7),
        [TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_F8),
        [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_MFFD, KC_F9),
        [TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_F10),
        [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_F11),
        [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_VOLU, KC_F12),
        */
    };
#else
    #define TD_ESC_CAPS KC_ESC
    #define TD_F1 KC_BRID
    #define TD_F2 KC_BRIU
    #define TD_F3 KC_MCTL
    #define TD_F4 KC_LPAD
    #define TD_F5 KC_SPOT
    #define TD_F6 KC_DICT
    #define TD_F7 KC_MRWD
    #define TD_F8 KC_MPLY
    #define TD_F9 KC_MFFD
    #define TD_F10 KC_MUTE
    #define TD_F11 KC_VOLD
    #define TD_F12 KC_VOLU
#endif // TAP_DANCE_ENABLE

// Combos
#ifdef COMBO_ENABLE
    enum combo_events {
        SPACE_TAB,
        CTL_SHIFT,
        CTL_CMD_SHIFT,
        COMBO_LENGTH
    };
    uint16_t COMBO_LEN = COMBO_LENGTH; // Store the max number of combos

    const uint16_t PROGMEM tab_space[] = {KC_SPACE, KC_TAB, COMBO_END};
    const uint16_t PROGMEM ctl_shift[] = {KC_LCTL, KC_LSFT, COMBO_END};
    const uint16_t PROGMEM ctl_cmd_shift[] = {KC_LCTL, KC_LGUI, KC_LSFT, COMBO_END};

    combo_t key_combos[] = {
        [SPACE_TAB] = COMBO_ACTION(tab_space),
        [CTL_SHIFT] = COMBO(ctl_shift, MO(FN)),
        [CTL_CMD_SHIFT] = COMBO(ctl_cmd_shift, MO(MACROS)),
    };
#else
    #define SPACE_TAB KC_SPACE
#endif // COMBO_ENABLE

// Tapping Term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
/*
    #ifdef TAP_DANCE_ENABLE
        switch (keycode) {
            case TD(TD_F11):
            case TD(TD_F12):
                return 150;
            default:
                return TAPPING_TERM;
        }
    #else
*/
        switch (keycode) {
            case TD_F11:
            case TD_F12:
                return 150;
            default:
                return TAPPING_TERM;
        }
//    #endif // TAP_DANCE_ENABLE
}

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Esc    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | PrScr  |        | Mute   |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | `~     | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BackSp |        | Home   |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      |        | PgUp   |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+        +--------+
    //    | Caps   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | Enter           |        | PgDn   |
    //    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+
    //    | Shift           | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | Shift           + Up     + End    |
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+
    //    | Ctrl   | Alt    | Super  |                            Space                             | Alt    | MO(1)  | Ctrl   | Left   | Down   | Right  |
    //    +--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------+

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

    /*
    [_NA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX, 
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX 
    ),
    */

    [BASE] = LAYOUT(
        //KC_ESC,           TD(TD_F1),  TD(TD_F2), TD(TD_F3), TD(TD_F4), TD(TD_F5), TD(TD_F6), TD(TD_F7), TD(TD_F8), TD(TD_F9), TD(TD_F10), TD(TD_F11), TD(TD_F12), KC_DEL,           KC_MPLY,
        KC_ESC,           TD_F1,      TD_F2,     TD_F3,     TD_F4,     TD_F5,     TD_F6,     TD_F7,     TD_F8,     TD_F9,     TD_F10,     TD_F11,     TD_F12,     KC_DEL,           KC_MPLY,
        KC_GRV,           KC_1,       KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,          TD_F13,
        KC_TAB,           KC_Q,       KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,          KC_F14,
        TD(TD_ESC_CAPS),  KC_A,       KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,    KC_QUOT,                KC_ENT,           KC_F15,
        KC_LSFT,                      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,     KC_SLSH,                KC_RSFT, KC_UP,   KC_F16,
        KC_LCTL,          KC_LALT,    KC_LGUI,                                    KC_SPC,                                     MO(FN),     KC_RGUI,    KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [FN] = LAYOUT(
        _______,          KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,        KC_F12,    KC_F13,           _______,
        _______,          KC_F14,     KC_F15,    KC_F16,    KC_F17,    KC_F18,    KC_F19,    KC_F20,    KC_F21,    KC_F22,    KC_F23,    KC_F24,        _______,   _______,          _______,
        _______,          _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,          _______,
        KC_CAPS,          _______,    _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,   _______,                  _______,          _______,
        _______,                      _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                  _______, KC_PGUP, _______,
        _______,          _______,    _______,                                    _______,                                    _______,   MO(RGBMOUSE),  _______,   KC_HOME, KC_PGDN, KC_END
    ),

    [RGBMOUSE] = LAYOUT(
        XXXXXXX,   RGB_TOG, RGB_M_P,      RGB_M_B,    RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_SAD, RGB_SAI, XXXXXXX,           XXXXXXX,
        TO(BASE),  TO(FN),  TO(RGBMOUSE), TO(MACROS), XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,             RGB_VAI,
        XXXXXXX,   KC_BTN1, KC_MS_U,      KC_BTN3,    KC_BTN2, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           RGB_VAD,
        XXXXXXX,   KC_MS_L, KC_MS_D,      KC_MS_R,    XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           RGB_HUI,
        KC_ACL0,            KC_ACL1,      KC_ACL2,    XXXXXXX, XXXXXXX,  XXXXXXX,  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD,  RGB_HUD,
        XXXXXXX,   XXXXXXX, XXXXXXX,                                     XXXXXXX,                             _______, _______, XXXXXXX, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [MACROS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DYN_REC_START1,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DYN_REC_START2,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          DYN_MACRO_PLAY1,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, DYN_MACRO_PLAY2,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE

// Combos
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case SPACE_TAB:
            if (pressed) {
                SEND_STRING("    ");
            }
            break;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t kc_lock_timer;

    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_SPOTLIGHT:
            if (record->event.pressed) {
                host_consumer_send(0x221);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_DICTATION:
            if (record->event.pressed) {
                host_consumer_send(0xCF);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_F13:
            if (record->event.pressed) {
                kc_lock_timer = timer_read();
                register_code(KC_F13);
            } else {
                unregister_code(KC_F13);
                if (timer_elapsed(kc_lock_timer) > 1000) {
                    SEND_STRING(SS_LCTRL(SS_LGUI("q"))); // Send shortcut to lock computer
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED);
        rgb_matrix_set_color(LED_L5, RGB_RED);
        rgb_matrix_set_color(LED_L6, RGB_RED);
        rgb_matrix_set_color(LED_L7, RGB_RED);
    } else {
        rgb_matrix_set_color(LED_CAPS, 0, 0, 0);
    }
}
