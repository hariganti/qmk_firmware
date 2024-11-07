// Copyright 2024 Hari Ganti
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define Y(kc) LALT_T(kc)
#define U(kc) LCTL_T(kc)
#define I(kc) LSFT_T(kc)
#define O(kc) LGUI_T(kc)
#define H(kc) RGUI_T(kc)
#define J(kc) RSFT_T(kc)
#define K(kc) RCTL_T(kc)
#define L(kc) RALT_T(kc)

// TODO: Make LT macro for all layers, so INS and PDOT can still trigger media controls
// TODO: Consider moving merging the symbol and numpad layers into one and using the 3,6 key to toggle it
//        0 would need to move to the semicolon (where it is on the symbol layer, currently, but maybe not with single tap vs double?)
//        Otherwise, that space mod could be for the symbol layer itself
// TODO: SHML + SHMR = Shift Lock

// Custom Keys
enum user_keycodes {
  HRML = SAFE_RANGE,  // Home row mods - left
  HRMR,               // Home row mods - right
  SFLK,               // Shift lock
  TLCK,               // Tap terminal, hold lock, TODO: chord CTRL
  EDEF,               // Tap file explorer, hold LAYER_DEFAULT
};

// Layers
#define LAYER_DEFAULT     0
#define LAYER_SYMBOLS     1
#define LAYER_NUMPAD      2
#define LAYER_NAVIGATION  3
#define LAYER_MEDIA       4

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
  #define LMED  LT(LAYER_MEDIA, KC_SPC)
  #define SHML  LT(0, HRML)
  #define SHMR  LT(0, HRMR)
  #define THTL  LT(0, TLCK)
  #define THED  LT(0, EDEF)

  // Default layer - Basis for regular typing
  [LAYER_DEFAULT]     = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC,KC_RBRC,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         LNAV,      KC_A, Y(KC_S),U(KC_D),I(KC_F),O(KC_G),H(KC_H),J(KC_J),K(KC_K),L(KC_L),KC_SCLN,KC_QUOT,      KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
     THTL,   THED,   LNUM,    LSYM,         SHML,           SHMR,           LMED,         KC_ESC,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  // Symbol layer - Adds the number and F-key rows
  [LAYER_SYMBOLS]     = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
        KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINS,      KC_EQL,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, SFLK,   KC_TRNS,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_INS,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  // Numpad layer - Puts a numpad on the RHS of the keyboard
  // TODO: Add a tap dance for the desired math symbol on the numpad (=, +, -, *, /) on H
  [LAYER_NUMPAD]      = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   KC_NO,  KC_F1,  KC_F4,  KC_F7,  KC_F10, KC_GRV, KC_7,   KC_8,   KC_9,  KC_EQL,  KC_NO,  KC_NO,   KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
        KC_NO,     KC_NO,  KC_F2,  KC_F5,  KC_F8,  KC_F11,KC_PDOT, KC_4,   KC_5,   KC_6,   KC_0,   KC_NO,       KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_NO,  KC_F3,  KC_F6,  KC_F9,  KC_F12,KC_PSLS, KC_1,   KC_2,   KC_3,  KC_MINS, KC_NO,  KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_NO,       KC_TRNS,        KC_TRNS,         KC_0,        KC_PDOT,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define FCON  G(KC_TAB)
  #define RCON  G(S(KC_TAB))
  #define FTAB  C(KC_TAB)
  #define RTAB  C(S(KC_TAB))
  #define FLOT  S(KC_F1)
  #define ROTL  S(KC_F2)
  #define ROTR  S(KC_F3)
  #define DIST  S(KC_F4)
  #define SRNK  S(KC_F5)
  #define GROW  S(KC_F6)

  // Navigation layer - Used for navigating text, tabs, windows, and workspaces, along with some QOL shortcuts
  [LAYER_NAVIGATION]  = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   RCON,   FCON,   SRNK,   DIST,   GROW,   KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO,  KC_NO,  KC_NO,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,    RTAB,   FTAB,   ROTL,   FLOT,   ROTR,  KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END, KC_NO,       KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    C(KC_Z),C(KC_X),C(KC_C),C(KC_V),C(KC_Y), KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_PGUP, KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,G(KC_A), G(KC_F),     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_HOME,KC_PGDN, KC_END
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define MICM  S(KC_MUTE)
  #define MICU  S(KC_VOLU)
  #define MICD  S(KC_VOLD)

  // Media layer - Primarily volume and track actions
  [LAYER_MEDIA]       = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_MPLY,KC_MPRV,KC_MNXT,   KC_NO,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_PSCR,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_VOLD,KC_VOLU,KC_MUTE, MICM,   MICU,   KC_NO,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, KC_NO,  KC_NO,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,    KC_BRID, MICD,  KC_BRIU
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  )
};

#define DEFAULT_TAPPING_TERM 10

// Custom state variables
static bool     shiftLock     = false;
static bool     HRMModEnable  = false;
static uint16_t tappingTerm   = DEFAULT_TAPPING_TERM;

// Set layer status LED
layer_state_t layer_state_set_user(layer_state_t state) {
  if(get_highest_layer(state)) {
    backlight_enable();
  } else {
    backlight_disable();
  }

  return state;
}

// Define the tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      return tappingTerm;

    default:
      return TAPPING_TERM;
  }
}

// Implement custom keycode functions

// bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process regular keycodes
  switch(keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    if(!HRMModEnable) {
      if(record->event.pressed) {
        register_code(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
      } else {
        unregister_code(QK_MOD_TAP_GET_TAP_KEYCODE(keycode));
      }

      return false;
    }

    break;

  case SHML:
    if(record->tap.count && record->event.pressed) {
      tap_code(KC_SPC);
    } else if(record->event.pressed) {
      HRMModEnable  = true;
      tappingTerm   = 200;
    } else {
      HRMModEnable  = false;
      tappingTerm   = DEFAULT_TAPPING_TERM;
      clear_mods();
    }

    return false;

  case SHMR:
    if(record->tap.count && record->event.pressed) {
      tap_code(KC_SPC);
    } else if(record->event.pressed) {
      HRMModEnable  = true;
      tappingTerm   = 200;
    } else {
      HRMModEnable  = false;
      tappingTerm   = DEFAULT_TAPPING_TERM;
      clear_mods();
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

  case SFLK:
    if(record->event.pressed) shiftLock = !shiftLock;
    if(shiftLock) {
      register_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }

    return false;

  case MICM:
    if(record->event.pressed) {
      register_code(KC_LSFT);
    } else {
      register_code(KC_MUTE);
      unregister_code(KC_MUTE);
      unregister_code(KC_LSFT);
    }
    return false;

  case MICU:
    if(record->event.pressed) {
      register_code(KC_LSFT);
    } else {
      register_code(KC_VOLU);
      unregister_code(KC_MUTE);
      unregister_code(KC_LSFT);
    }
    return false;

  case MICD:
    if(record->event.pressed) {
      register_code(KC_LSFT);
    } else {
      register_code(KC_VOLD);
      unregister_code(KC_MUTE);
      unregister_code(KC_LSFT);
    }
    return false;
  }

  return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return;
// }
