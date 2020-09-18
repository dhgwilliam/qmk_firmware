#include QMK_KEYBOARD_H

LEADER_EXTERNS();

void matrix_scan_user(void) {
  #ifdef SSD1306OLED
    iota_gfx_task();
  #endif

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_G, KC_I) {
      SEND_STRING("/is:inbox\n");
    }

    SEQ_TWO_KEYS(KC_G, KC_G) {
      SEND_STRING("gfo&&gmf\n");
    }

    SEQ_TWO_KEYS(KC_DOT, KC_DOT) {
      SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) "a" SS_DELAY(15) "v" SS_UP(X_LGUI) SS_UP(X_LSFT));
    }

    SEQ_TWO_KEYS(KC_W, KC_O) {
      SEND_STRING(SS_LALT("1") SS_DELAY(100) SS_LGUI(SS_LSFT(SS_LALT(SS_LCTL("s")))));
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
  ENTR_SCLC_LALT,
  SPC_SCLC_LALT,
  SPC_A_LALT,
  F_J_HYPER
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
const uint16_t PROGMEM entr_sclc_lalt[] = {KC_ENTER, KC_SCLN, COMBO_END};
const uint16_t PROGMEM spc_sclc_lalt[] = {KC_SPC, KC_SCLN, COMBO_END};
const uint16_t PROGMEM spc_a_lalt[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM f_j_hyper[] = {KC_F, KC_J, COMBO_END};

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
  [ENTR_SCLC_LALT] = COMBO_ACTION(entr_sclc_lalt),
  [SPC_SCLC_LALT] = COMBO_ACTION(spc_sclc_lalt),
  [SPC_A_LALT]    = COMBO_ACTION(spc_a_lalt),
  [F_J_HYPER]    = COMBO_ACTION(f_j_hyper)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
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
        tap_code16(KC_TAB);
        tap_code16(KC_ENTER);
      }
      break;
    case ENTR_SCLC_LALT:
      if (pressed) {
        register_code(KC_LALT);
        layer_on(2);
      } else {
        unregister_code(KC_LALT);
        layer_off(2);
      }
      break;
    case SPC_SCLC_LALT:
      if (pressed) {
        register_code(KC_LALT);
        #ifdef REV6_CONFIG_H
          layer_on(4);
        #endif
      } else {
        unregister_code(KC_LALT);
        #ifdef REV6_CONFIG_H
          layer_off(4);
        #endif
      }
      break;
    case SPC_A_LALT:
      if (pressed) {
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
      }
      break;
    case F_J_HYPER:
      if (pressed) {
        register_code16(KC_HYPR);
      } else {
        unregister_code16(KC_HYPR);
      }
      break;
  }
};
