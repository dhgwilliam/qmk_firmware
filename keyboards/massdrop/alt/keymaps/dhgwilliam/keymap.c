#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  \
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME, \
        CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_HYPR,       KC_LALT, KC_LGUI,                            KC_SPC,                    KC_LEAD, MO(1),            KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            KC_MPLY,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_L) {
      SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI) SS_DELAY(50)"lock\n");
    }

    SEQ_TWO_KEYS(KC_Z, KC_O) {
      SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPC) SS_UP(X_LGUI) SS_DELAY(50)"zoom\n");
    }

    SEQ_TWO_KEYS(KC_G, KC_I) {
      SEND_STRING("/is:inbox\n");
    }

    SEQ_TWO_KEYS(KC_G, KC_G) {
      SEND_STRING("gfo&&gmf\n");
    }
  }
}

enum combo_events {
  WE_ESC,
  SD_BSP,
  DF_TAB,
  XC_DASH,
  CV_ENTR,
  UI_ESC,
  OP_BSLS,
  NM_QUOTE,
  HJ_LT,
  JK_COLN,
  KL_GT,
  MC_USCR,
  NEXT_CHANNEL,
  SPC_SCLC_LALT,
  SPC_A_LALT
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM next_channel[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM spc_sclc_lalt[] = {KC_SPC, KC_SCLN, COMBO_END};
const uint16_t PROGMEM spc_a_lalt[] = {KC_SPC, KC_A, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WE_ESC]        = COMBO_ACTION(we_combo),
  [SD_BSP]        = COMBO_ACTION(sd_combo),
  [DF_TAB]        = COMBO_ACTION(df_combo),
  [XC_DASH]       = COMBO_ACTION(xc_combo),
  [CV_ENTR]       = COMBO_ACTION(cv_combo),
  [UI_ESC]        = COMBO_ACTION(ui_combo),
  [OP_BSLS]       = COMBO_ACTION(op_combo),
  [HJ_LT]         = COMBO_ACTION(hj_combo),
  [JK_COLN]       = COMBO_ACTION(jk_combo),
  [KL_GT]         = COMBO_ACTION(kl_combo),
  [NM_QUOTE]      = COMBO_ACTION(nm_combo),
  [MC_USCR]       = COMBO_ACTION(mc_combo),
  [NEXT_CHANNEL]  = COMBO_ACTION(next_channel),
  [SPC_SCLC_LALT] = COMBO_ACTION(spc_sclc_lalt),
  [SPC_A_LALT]    = COMBO_ACTION(spc_a_lalt)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case WE_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case SD_BSP:
      if (pressed) {
        tap_code16(KC_BSPC);
      }
      break;
    case DF_TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case XC_DASH:
      if (pressed) {
        tap_code16(KC_MINS);
      }
      break;
    case CV_ENTR:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
    case UI_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
    case OP_BSLS:
      if (pressed) {
        tap_code16(KC_BSLS);
      }
      break;
    case NM_QUOTE:
      if (pressed) {
        tap_code16(KC_QUOT);
      }
      break;
    case HJ_LT:
      if (pressed) {
        tap_code16(LSFT(KC_COMM));
      }
      break;
    case JK_COLN:
      if (pressed) {
        tap_code16(LSFT(KC_SCLN));
      }
      break;
    case KL_GT:
      if (pressed) {
        tap_code16(LSFT(KC_DOT));
      }
      break;
    case MC_USCR:
      if (pressed) {
        tap_code16(LSFT(KC_MINS));
      }
      break;
    case NEXT_CHANNEL:
      if (pressed) {
        tap_code16(LGUI(KC_K));
        SEND_STRING(SS_DELAY(100));
        tap_code16(KC_ENTER);
      }
      break;
    case SPC_SCLC_LALT:
      if (pressed) {
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      break;
    case SPC_A_LALT:
      if (pressed) {
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      break;
  }
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
