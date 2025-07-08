#ifndef MOCK_UI_MOVE_H
#define MOCK_UI_MOVE_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "mock_hpi_common_types.h"

// Mock UI functions
static inline void draw_scr_splash(void) { }
static inline void draw_scr_boot(void) { }
static inline void draw_scr_progress(const char *title, const char *subtitle) { }
static inline void scr_boot_add_status(const char *msg, bool status, bool show_status) { }
static inline void display_init_styles(void) { }
static inline void ui_home_time_display_update(struct tm time) { }
static inline void ui_hr_button_update(uint16_t hr) { }
static inline void ui_steps_button_update(uint32_t steps) { }
static inline void hpi_disp_home_update_batt_level(uint8_t level, bool charging) { }
static inline void hpi_disp_settings_update_batt_level(uint8_t level, bool charging) { }
static inline void hpi_scr_home_update_time_date(struct tm time) { }
static inline void hpi_disp_scr_update_progress(int progress, const char *msg) { }
static inline void hpi_temp_disp_update_temp_f(double temp, int64_t timestamp) { }
static inline void hpi_disp_hr_update_hr(uint16_t hr, int64_t timestamp) { }
static inline void hpi_scr_today_update_all(uint32_t steps, uint16_t kcals, uint16_t active_time) { }
static inline void hpi_disp_settings_update_time_date(struct tm time) { }
static inline void hpi_ecg_disp_draw_plotECG(int16_t *samples, uint8_t num_samples, bool lead_off) { }
static inline void hpi_ecg_disp_update_hr(uint16_t hr) { }
static inline void hpi_ecg_disp_update_timer(int timer) { }
static inline void scr_ecg_lead_on_off_handler(bool on) { }
static inline void hpi_disp_bpt_draw_plotPPG(struct hpi_ppg_fi_data_t data) { }
static inline void hpi_disp_bpt_update_progress(uint8_t progress) { }
static inline void hpi_disp_spo2_plot_fi_ppg(struct hpi_ppg_fi_data_t data) { }
static inline void hpi_disp_spo2_update_progress(uint8_t percent, uint8_t state, uint8_t spo2, uint16_t hr) { }
static inline void hpi_disp_spo2_plot_wrist_ppg(struct hpi_ppg_wr_data_t data) { }
static inline int hpi_disp_set_brightness(int brightness) { return 0; }
static inline int hpi_disp_get_brightness(void) { return 50; }

// Mock screen loading functions
static inline void hpi_load_screen(int screen, enum scroll_dir dir) { }
static inline void hpi_load_scr_spl(int screen, enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }

// Mock gesture handlers
static inline void gesture_down_scr_ecg_2(void) { }
static inline void gesture_down_scr_fi_sens_wear(void) { }
static inline void gesture_down_scr_fi_sens_check(void) { }
static inline void gesture_down_scr_bpt_measure(void) { }
static inline void gesture_down_scr_bpt_cal_complete(void) { }
static inline void gesture_down_scr_ecg_complete(void) { }
static inline void gesture_down_scr_spo2_scr2(void) { }
static inline void gesture_down_scr_spo2_measure(void) { }
static inline void gesture_down_scr_spl_spo2_complete(void) { }
static inline void gesture_down_scr_spl_spo2_timeout(void) { }
static inline void gesture_down_scr_spl_low_battery(void) { }
static inline void gesture_down_scr_spo2_select(void) { }
static inline void gesture_down_scr_bpt_cal_progress(void) { }
static inline void gesture_down_scr_bpt_cal_failed(void) { }
static inline void gesture_down_scr_bpt_est_complete(void) { }
static inline void gesture_down_scr_bpt_cal_required(void) { }
static inline void gesture_down_scr_settings(void) { }

// Mock screen drawing functions
static inline void draw_scr_spl_raw_ppg(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_ecg_scr2(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_fi_sens_wear(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_fi_sens_check(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_measure(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_cal_complete(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_ecg_complete(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_hrv(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spo2_scr2(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spo2_measure(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spl_spo2_complete(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spl_spo2_timeout(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spl_low_battery(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_spo2_select(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_cal_progress(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_cal_failed(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_est_complete(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_bpt_cal_required(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_ble(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }
static inline void draw_scr_settings(enum scroll_dir dir, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) { }

#endif /* MOCK_UI_MOVE_H */
