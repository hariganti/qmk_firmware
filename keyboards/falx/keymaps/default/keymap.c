// Copyright 2024 Hari Ganti
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// TODO: Make LT macro for all layers, so INS and PDOT can still trigger media controls
// TODO: Tap dance for the numpad for zero or space on a single press
// TODO: Combo SHML + SHMR = Shift Lock
// TODO: Caps Word implementation, maybe on (3,3) with shift lock on the same key with numpad layer?
// TODO: Separate left and right HRM since it disrupts press and hold on nav layer arrow keys when using HRM for a modifier

// Custom Keys
enum user_keycodes {
  UK_SFLK = SAFE_RANGE, // Shift lock
  UK_TLCK,              // Tap terminal, hold lock, TODO: chord CTRL
  UK_EDEF,              // Tap file explorer, hold LAYER_DEFAULT
  UK_FTAB,              // Tab forward
  UK_ROTL,              // Rotate left (CCW)
  UK_FLOT,              // Toggle floating
  UK_ROTR               // Rotate right (CW)
};

// Layers
#define LAYER_DEFAULT     0
#define LAYER_NUMPAD      1
#define LAYER_NAVIGATION  2
#define LAYER_MEDIA       3

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Spacing, positioning, and coordinates of all keys for use in formatting the keymap
 *
 * │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │    0,0    │  0,1  │  0,2  │  0,3  │  0,4  │  0,5  │  0,6  │  0,7  │  0,8  │  0,9  │  0,10 │  0,11 │  0,12 │   3,12    │ 1
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │     1,0     │  1,1  │  1,2  │  1,3  │  1,4  │  1,5  │  1,6  │  1,7  │  1,8  │  1,9  │  1,10 │  1,11 │       1,12      │ 2
 * ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
 * │      2,0      │  2,1  │  2,2  │  2,3  │  2,4  │  2,5  │  2,6  │  2,7  │  2,8  │  2,9  │  2,10 │  2,11 │  2,12 │  3,11 │ 3
 * ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
 * │  3,0  │  3,1  │  3,2  │   3,3   │      3,4      │      3,5      │      3,6      │     3,7     │  3,8  │  3,9  │  3,10 │ 4
 * ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
 * │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 */

  #define LSYM  TT(LAYER_SYMBOLS)
  #define LNUM  TT(LAYER_NUMPAD)
  #define LNAV  TT(LAYER_NAVIGATION)
  #define LMED  LT(LAYER_MEDIA, KC_ESC)
  #define THTL  LT(0, UK_TLCK)
  #define THED  LT(0, UK_EDEF)
  #define HRAS  LALT_T(KC_S)
  #define HRCD  LCTL_T(KC_D)
  #define HRSF  LSFT_T(KC_F)
  #define HRGG  LGUI_T(KC_G)
  #define HRGH  RGUI_T(KC_H)
  #define HRSJ  RSFT_T(KC_J)
  #define HRCK  RCTL_T(KC_K)
  #define HRAL  RALT_T(KC_L)

  // Default layer - Basis for regular typing
  [LAYER_DEFAULT] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC,KC_RBRC,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         LNAV,      KC_A,   HRAS,  HRCD,   HRSF,   HRGG,   HRGH,   HRSJ,   HRCK,   HRAL,  KC_SCLN,KC_QUOT,      KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
     THTL,   THED,   KC_NO,   KC_NO,   LT(0, KC_SPC),  LT(0, KC_SPC),      LNUM,           LMED,    KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define HRAF5   LALT_T(KC_F5)
  #define HRCF8   LCTL_T(KC_F8)
  #define HRSF11  LSFT_T(KC_F11)
  #define HRGNO   LGUI_T(KC_NO)
  #define HRGGRV  RGUI_T(KC_GRV)
  #define HRS4    RSFT_T(KC_4)
  #define HRC5    RCTL_T(KC_5)
  #define HRA6    RALT_T(KC_6)

  // Numpad layer - Puts a numpad on the RHS of the keyboard
  [LAYER_NUMPAD] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   KC_F1,  KC_F4,  KC_F7,  KC_F10, KC_NO, KC_PAST, KC_7,   KC_8,   KC_9,  KC_PPLS, KC_NO,  KC_NO,   KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,    KC_F2,  HRAF5,  HRCF8, HRSF11,  HRGNO, HRGGRV,  HRS4,   HRC5,   HRA6,  KC_MINS, KC_0,        KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_F3,  KC_F6,  KC_F9,  KC_F12, KC_NO,  KC_EQL, KC_1,   KC_2,   KC_3,  KC_SLSH, KC_NO,  KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,UK_SFLK, KC_INS,      KC_TRNS,        KC_TRNS,       KC_TRNS,        KC_PDOT,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define RCON    G(S(KC_TAB))
  #define FCON    G(KC_TAB)
  #define RTAB    C(S(KC_TAB))
  #define SRNK    S(KC_F5)
  #define DIST    S(KC_F4)
  #define GROW    S(KC_F6)
  #define HRAFTAB LALT_T(UK_FTAB)
  #define HRCROTL LCTL_T(UK_ROTL)
  #define HRSFLOT LSFT_T(UK_FLOT)
  #define HRGROTR LGUI_T(UK_ROTR)
  #define HRGHOME RGUI_T(KC_HOME)
  #define HRSLEFT RSFT_T(KC_LEFT)
  #define HRCDOWN RCTL_T(KC_DOWN)
  #define HRARGHT RALT_T(KC_RGHT)

  // Navigation layer - Used for navigating text, tabs, windows, and workspaces, along with some QOL shortcuts
  //
  [LAYER_NAVIGATION] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   RCON,   FCON,   SRNK,   DIST,   GROW,   KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO,  KC_NO,  KC_NO,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,    RTAB,  HRAFTAB,HRCROTL,HRSFLOT,HRGROTR,HRGHOME,HRSLEFT,HRCDOWN,HRARGHT, KC_END, KC_NO,       KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    C(KC_Z),C(KC_X),C(KC_C),C(KC_V),C(KC_Y), KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_PGUP, KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,G(KC_A), G(KC_F),     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_HOME,KC_PGDN, KC_END
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define MIKM S(KC_MUTE)
  #define MIKU S(KC_VOLU)
  #define MIKD S(KC_VOLD)

  // Media layer - Primarily volume and track actions
  [LAYER_MEDIA] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_MPLY,KC_MPRV,KC_MNXT,   KC_NO,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         KC_NO,    KC_NO, KC_LALT,KC_LCTL,KC_LSFT,KC_LGUI, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_PSCR,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_MUTE, MIKM,  KC_VOLU, KC_NO,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, KC_NO,   KC_NO,      KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,    MIKD,  KC_VOLD, MIKU
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  )
};

// Custom state variables
static bool shiftLock     = false;
static bool HRMModEnable  = false;

// Set layer status LED
layer_state_t layer_state_set_user(layer_state_t state) {
  if(get_highest_layer(state)) {
    backlight_enable();
  } else {
    backlight_disable();
  }

  return state;
}

#define MIN_TAPPING_TERM 5

// Define the tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      return HRMModEnable ? TAPPING_TERM : MIN_TAPPING_TERM;

    default:
      return TAPPING_TERM;
  }
}

// Implement custom keycode functions

// bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return true;
// }

#define FTAB C(KC_TAB)
#define ROTL S(KC_F2)
#define FLOT S(KC_F1)
#define ROTR S(KC_F3)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process regular keycodes
  switch(keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      switch(keycode) {
        case HRAFTAB:
          if((!HRMModEnable || record->tap.count) && record->event.pressed) {
            tap_code16(FTAB);
            return false;
          }

          break;

        case HRCROTL:
          if((!HRMModEnable || record->tap.count) && record->event.pressed) {
            tap_code16(ROTL);
            return false;
          }

          break;

        case HRSFLOT:
          if((!HRMModEnable || record->tap.count) && record->event.pressed) {
            tap_code16(FLOT);
            return false;
          }

          break;

        case HRGROTR:
          if((!HRMModEnable || record->tap.count) && record->event.pressed) {
            tap_code16(ROTR);
            return false;
          }

          break;

        default:
          if((!HRMModEnable || record->tap.count) && record->event.pressed) {
            register_code(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
            return false;
          } else if(!record->event.pressed) {
            unregister_code(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
          }

          break;
      }

      break;

    case LT(0, KC_SPC):
      if(record->tap.count && record->event.pressed) {
        tap_code(KC_SPC);
      } else if(record->event.pressed) {
        HRMModEnable = true;
      } else {
        HRMModEnable = false;
      }

      return false;

    case THTL:
      if(record->tap.count && record->event.pressed) {
        tap_code16(G(KC_SPC));
      } else if(record->event.pressed) {
        tap_code16(G(KC_L));
      }

      return false;

    case THED:
      if(record->tap.count && record->event.pressed) {
        tap_code16(G(KC_E));
      } else if(record->event.pressed) {
        layer_clear();
      }

      return false;

    case UK_SFLK:
      if(record->event.pressed) shiftLock = !shiftLock;
      if(shiftLock) {
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
      }

      return false;

    case MIKM:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_MUTE);
        unregister_code(KC_MUTE);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKU:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKD:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
        unregister_code(KC_LSFT);
      }
      return false;
    }

  return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return;
// }
