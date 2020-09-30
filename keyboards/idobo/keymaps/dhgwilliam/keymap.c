#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

#define _QWERTY 0
#define _NUMBER 1
#define _SYMBOL 2
#define _META   3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ortho_5x15(
      ALL_T(KC_GRV)  , KC_1    , KC_2          , KC_3    , KC_4    , KC_5   , KC_PGDN     , KC_UP   , KC_PGUP     , KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS         ,
      KC_TAB         , KC_Q    , KC_W          , KC_E    , KC_R    , KC_T   , KC_LEFT     , KC_DOWN , KC_RGHT     , KC_Y   , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC         ,
      LCTL_T(KC_ESC) , KC_A    , KC_S          , KC_D    , KC_F    , KC_G   , KC_LGUI     , KC_MPLY , KC_RGUI     , KC_H   , KC_J    , KC_K    , KC_L    , KC_SCLN , RCTL_T(KC_QUOT) ,
      KC_LSFT        , KC_Z    , KC_X          , KC_C    , KC_V    , KC_B   , KC_LALT     , KC_HOME , KC_RALT     , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , RSFT_T(KC_ENT)  ,
      KC_LEAD        , KC_CAPS , LALT(KC_LSFT) , KC_LALT , KC_LGUI , KC_SPC , MO(_SYMBOL) , KC_END  , MO(_NUMBER) , KC_SPC , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , MO(_META)
      ),
	[_SYMBOL] = LAYOUT_ortho_5x15(
      KC_NO , KC_EXLM , KC_AT , KC_HASH , KC_DLR , KC_PERC , KC_NO , KC_NO , KC_NO     , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,
      KC_NO , KC_EXLM , KC_AT , KC_HASH , KC_DLR , KC_PERC , KC_NO , KC_NO , KC_NO     , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL  ,
      KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO  , KC_NO   , KC_NO , KC_NO , KC_NO     , KC_NO   , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE ,
      KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO  , KC_NO   , KC_NO , KC_NO , KC_NO     , KC_NO   , KC_TILD , KC_PIPE , KC_HOME , KC_END  , KC_NO   ,
      KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO  , KC_NO   , KC_NO , KC_NO , MO(_META) , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_TRNS
      ),
	[_NUMBER] = LAYOUT_ortho_5x15(
      KC_GRV , KC_1  , KC_2  , KC_3  , KC_4   , KC_5   , KC_PGDN   , KC_UP , KC_PGUP , KC_6  , KC_7    , KC_8   , KC_9    , KC_0    , KC_BSLS ,
      KC_GRV , KC_1  , KC_2  , KC_3  , KC_4   , KC_5   , KC_PGDN   , KC_UP , KC_PGUP , KC_6  , KC_7    , KC_8   , KC_9    , KC_0    , KC_DEL  ,
      KC_NO  , KC_F1 , KC_F2 , KC_F3 , KC_F4  , KC_F5  , KC_F6     , KC_NO , KC_NO   , KC_NO , KC_MINS , KC_EQL , KC_LBRC , KC_RBRC , KC_BSLS ,
      KC_NO  , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12    , KC_NO , KC_NO   , KC_NO , KC_NO   , KC_NO  , KC_PGUP , KC_PGDN , KC_NO   ,
      KC_NO  , KC_NO , KC_NO , KC_NO , KC_NO  , KC_NO  , MO(_META) , KC_NO , KC_TRNS , KC_NO , KC_NO   , KC_NO  , KC_NO   , KC_NO   , KC_TRNS
      )      ,
	[_META] = LAYOUT_ortho_5x15(
      KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , RESET   ,
      KC_NO , KC_NO , KC_NO , KC_NO   , KC_MS_U , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO   ,
      KC_NO , KC_NO , KC_NO , KC_MS_L , KC_MS_D , KC_MS_R , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_MPLY ,
      KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_MRWD , KC_MFFD , KC_NO , KC_NO   ,
      KC_NO , KC_NO , KC_NO , KC_MS_L , KC_MS_R , KC_NO   , KC_TRNS , KC_NO , KC_TRNS , KC_WBAK , KC_VOLD , KC_VOLU , KC_MUTE , KC_NO , KC_NO
      )
};
