
#include QMK_KEYBOARD_H
#include "xtonhasvim.h"
#include "fancylighting.h"

#define _______ KC_TRNS

enum layers {
  _QWERTY,
  _FUN,
  _COLORS,
  _CMD,
  _QWERTYWIN,
  _BLANK,
  _QWERTYWIN2
};

extern uint8_t vim_cmd_layer(void) { return _CMD; }

enum layout_key_codes {
  IND_BRI = VIM_SAFE_RANGE,
  IND_DIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[_QWERTY] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,           KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    LT(_CMD, KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FUN),
	         KC_LALT, KC_LGUI,                        KC_SPC,                               KC_RALT, MO(_COLORS)),

[_FUN] = LAYOUT_60_hhkb(
	KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
	KC_CAPS, IND_DIM, _______, IND_BRI, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______,
	_______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
	_______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______, _______,
	         DF(_QWERTY), DF(_QWERTYWIN),                            _______,                            _______, _______),

[_COLORS] = LAYOUT_60_hhkb(
	_______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  _______, _______,
	_______, _______, _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	         _______, _______,                            _______,                            _______, _______),

[_CMD] = LAYOUT_60_hhkb(
  VIM_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, VIM_W,     VIM_E, _______, _______,   VIM_Y,   VIM_U,   VIM_I,   VIM_O,   VIM_P, _______, _______, _______,
  _______,   VIM_A, VIM_S,     VIM_D, _______,   VIM_G,   VIM_H,   VIM_J,   VIM_K,   VIM_L, _______, _______, _______,
  VIM_SHIFT, _______, VIM_X,   VIM_C,   VIM_V,   VIM_B, _______, _______, VIM_COMMA, VIM_PERIOD, _______, VIM_SHIFT, _______,
          _______, _______,                            _______,                            _______, _______),

[_QWERTYWIN] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,           KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    LT(_CMD, KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FUN),
	         KC_LCTL, KC_LALT,                        KC_SPC,                               KC_RALT, MO(_COLORS)),

// A blank - just use it as a template
[_BLANK] = LAYOUT_60_hhkb(
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	         _______, _______,                            _______,                            _______, _______),

[_QWERTYWIN2] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,           KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    LT(_CMD, KC_F), KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FUN),
	         KC_LCTL, KC_LALT,                        KC_SPC,                               KC_RALT, MO(_COLORS))
};
