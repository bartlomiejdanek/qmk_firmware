#include QMK_KEYBOARD_H
#include "xtonhasvim.h"

#define _______ KC_TRNS
#define X_____X KC_NO

enum layers {
  _QWERTY,
  _FUN,
  _MOVE,
  _CMD
};

enum layout_key_codes {
  IND_BRI = VIM_SAFE_RANGE,
  IND_DIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_BSPC, \
        KC_LCTL,   KC_A,    KC_S,    KC_D,    LT(_MOVE, KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FUN),  \
        X_____X, KC_LALT, KC_LGUI,               KC_SPC,                          KC_RALT,  VIM_START, MO(_FUN)),


    [_MOVE] = LAYOUT(
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X,
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, KC_HOME, KC_PGDN, KC_PGUP, KC_END, X_____X, X_____X, X_____X, X_____X,
        _______, X_____X, LGUI(KC_LBRC), LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), LGUI(KC_RBRC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, X_____X, X_____X, VIM_START,
        _______, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, _______,
        _______,   _______,               _______,                                                      _______,   _______,  _______,  _______),


    [_FUN] = LAYOUT(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  X_____X, KC_DEL, \
	       MAGIC_NO_GUI,   X_____X,  KC_UP,    RGB_TOG,  IND_BRI,  X_____X,  X_____X,   X_____X, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    X_____X,          KC_INS, \
	       MAGIC_UNNO_GUI,   KC_LEFT,  KC_DOWN,  KC_RIGHT, IND_DIM,  X_____X,  X_____X,   X_____X, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          FIREY_RETURN,          \
	       _______,   BL_INC,   BL_STEP,  BL_DEC,   X_____X,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN, _______, X_____X,  \
	       _______,   _______,  _______,            X_____X,                                                           _______,  _______, X_____X
    ),

    [_CMD] = LAYOUT(
        VIM_ESC, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X,
        X_____X, X_____X, VIM_W, VIM_E, X_____X, X_____X, VIM_Y, VIM_U, VIM_I, VIM_O, VIM_P, X_____X, X_____X, X_____X,
        _______,   VIM_A, VIM_S, VIM_D, X_____X, VIM_G, VIM_H, VIM_J, VIM_K, VIM_L, X_____X, X_____X, X_____X,
        VIM_SHIFT, X_____X, VIM_X, VIM_C, VIM_V, VIM_B, X_____X, X_____X, VIM_COMMA, VIM_PERIOD, X_____X, VIM_SHIFT,X_____X,
        _______, _______, _______,               _______,                          _______, _______,  TO(_QWERTY)
    )
};
