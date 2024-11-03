// Copyright 2024 Hari Ganti
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// TODO: Make LT macro for all layers, so INS and PDOT can still trigger media controls

// Home row mod parameters
#define HRM_ROW       1
#define HRM_LALT_COL  2
#define HRM_LCTL_COL  3
#define HRM_LSFT_COL  4
#define HRM_LGUI_COL  5
#define HRM_RGUI_COL  6
#define HRM_RSFT_COL  7
#define HRM_RCTL_COL  8
#define HRM_RALT_COL  9

// Layers
#define LAYER_DEFAULT     0
#define LAYER_SYMBOLS     1
#define LAYER_NUMPAD      2
#define LAYER_NAVIGATION  3
#define LAYER_MEDIA       4

#define LSYM  TT(LAYER_SYMBOLS)
#define LNUM  TT(LAYER_NUMPAD)
#define LNAV  TT(LAYER_NAVIGATION)
#define LMED  LT(LAYER_MEDIA, KC_SPC)

// Pseudo Layers (Mostly used for the timing functionality of tap vs hold)
#define SHML  LT(0, HRML)
#define SHMR  LT(0, HRMR)
#define THTL  LT(0, TLCK)
#define THED  LT(0, EDEF)

// Window Actions
#define FCON  G(KC_TAB)
#define RCON  G(S(KC_TAB))
#define FTAB  C(KC_TAB)
#define RTAB  C(S(KC_TAB))
#define TFCS  G(KC_A)
#define GAPS  G(KC_F)
#define FLOT  S(KC_F1)
#define ROTL  S(KC_F2)
#define ROTR  S(KC_F3)
#define DIST  S(KC_F4)
#define SRNK  S(KC_F5)
#define GROW  S(KC_F6)

// System Actions
#define MICM  S(KC_MUTE)
#define MICU  S(KC_VOLU)
#define MICD  S(KC_VOLD)

// Custom Keys
enum user_keycodes {
  HRML = SAFE_RANGE,  // Home row mods - left
  HRMR,               // Home row mods - right
  SFLK,               // Shift lock
  TLCK,               // Tap terminal, hold lock
  EDEF,               // Tap file explorer, hold LAYER_DEFAULT
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┼───
 * │    0,0    │  0,1  │  0,2  │  0,3  │  0,4  │  0,5  │  0,6  │  0,7  │  0,8  │  0,9  │  0,10 │  0,11 │  0,12 │   3,12    │ 1
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┼───
 * │     1,0     │  1,1  │  1,2  │  1,3  │  1,4  │  1,5  │  1,6  │  1,7  │  1,8  │  1,9  │  1,10 │  1,11 │       1,12      │ 2
 * ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┼───
 * │      2,0      │  2,1  │  2,2  │  2,3  │  2,4  │  2,5  │  2,6  │  2,7  │  2,8  │  2,9  │  2,10 │  2,11 │  2,12 │  3,11 │ 3
 * ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┼───
 * │  3,0  │  3,1  │  3,2  │   3,3   │      3,4      │      3,5      │      3,6      │     3,7     │  3,8  │  3,9  │  3,10 │ 4
 * ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┼───
 * │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 */
  [LAYER_DEFAULT]     = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
    LNAV,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS,  KC_UP,    KC_DEL,
    THTL,     THED,     LNUM,     LSYM,     SHML,     SHMR,     LMED,     KC_ESC,   KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [LAYER_SYMBOLS]     = LAYOUT(
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_UP,    KC_DEL,
    KC_TRNS,  KC_TRNS,  SFLK,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS,   KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [LAYER_NUMPAD]      = LAYOUT(
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P7,    KC_P8,    KC_P9,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P4,    KC_P5,    KC_P6,    KC_NO,    KC_NO,    KC_ENT,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_P1,    KC_P2,    KC_P3,    KC_NO,    KC_NO,    KC_UP,    KC_DEL,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_P0,    KC_PDOT,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),
  [LAYER_NAVIGATION]  = LAYOUT(
    KC_TRNS,  RCON,     FCON,     SRNK,     DIST,     GROW,     KC_NO,    KC_PGUP,  KC_UP,    KC_PGDN,  KC_NO,    KC_NO,    KC_NO,    KC_BSPC,
    KC_TRNS,  RTAB,     FTAB,     ROTL,     FLOT,     ROTR,     KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   KC_NO,    KC_ENT,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PGUP,  KC_DEL,
    KC_TRNS,  KC_TRNS,  TFCS,     GAPS,     KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END
  ),
  [LAYER_MEDIA]       = LAYOUT(
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_NO,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PSCR,
    KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_VOLD,  KC_VOLU,  KC_MUTE,  MICM,     KC_BRIU,  KC_NO,
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    MICD,     KC_BRID,  MICU
  )
};

// Set layer status LED
layer_state_t layer_state_set_user(layer_state_t state) {
  if(get_highest_layer(state)) {
    backlight_enable();
  } else {
    backlight_disable();
  }

  return state;
}

// Implement custom keycode functions
static bool shiftLock     = false;
static bool HRMLModEnable = false;
static bool HRMRModEnable = false;

// bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process regular keycodes
  switch(keycode) {
  case SHML:
    if(record->tap.count && record->event.pressed) {
      tap_code(KC_SPC);
    } else if(record->event.pressed) {
      HRMLModEnable = true;
    } else {
      HRMLModEnable = false;
      clear_mods();
    }

    return false;

  case SHMR:
    if(record->tap.count && record->event.pressed) {
      tap_code(KC_SPC);
    } else if(record->event.pressed) {
      HRMRModEnable = true;
    } else {
      HRMRModEnable = false;
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
  }

  // Home Row Mods - Enables home row mods using a held mod enable key
  if(!record->tap.count && record->event.key.row == HRM_ROW) {
    if(HRMLModEnable) {
      // Left Alt
      if(record->event.key.col == HRM_LALT_COL) {
        if(record->event.pressed) {
          register_code(KC_LALT);
        } else {
          unregister_code(KC_LALT);
        }

        return false;
      }

      // Left GUI (Super)
      if(record->event.key.col == HRM_LGUI_COL) {
        if(record->event.pressed) {
          register_code(KC_LGUI);
        } else {
          unregister_code(KC_LGUI);
        }

        return false;
      }

      // Left Control
      if(record->event.key.col == HRM_LCTL_COL) {
        if(record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }

        return false;
      }

      // Left Shift
      if(record->event.key.col == HRM_LSFT_COL) {
        if(record->event.pressed) {
          register_code(KC_LSFT);
        } else {
          unregister_code(KC_LSFT);
        }

        return false;
      }
    } else if(HRMRModEnable) {
      // Right Shift
      if(record->event.key.col == HRM_RSFT_COL) {
        if(record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }

        return false;
      }

      // Right Control
      if(record->event.key.col == HRM_RCTL_COL) {
        if(record->event.pressed) {
          register_code(KC_RCTL);
        } else {
          unregister_code(KC_RCTL);
        }

        return false;
      }

      // Right GUI (Super)
      if(record->event.key.col == HRM_RGUI_COL) {
        if(record->event.pressed) {
          register_code(KC_RGUI);
        } else {
          unregister_code(KC_RGUI);
        }

        return false;
      }

      // Right Alt
      if(record->event.key.col == HRM_RALT_COL) {
        if(record->event.pressed) {
          register_code(KC_RALT);
        } else {
          unregister_code(KC_RALT);
        }

        return false;
      }
    }
  }

  return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return;
// }
