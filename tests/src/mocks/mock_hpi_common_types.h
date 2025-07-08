#ifndef MOCK_HPI_COMMON_TYPES_H
#define MOCK_HPI_COMMON_TYPES_H

#include <stdint.h>
#include <stdbool.h>

// Screen definitions
#define SCR_HOME 0
#define SCR_HR 1
#define SCR_SPO2 2
#define SCR_TEMP 3
#define SCR_BPT 4
#define SCR_ECG 5
#define SCR_TODAY 6
#define SCR_SPL_BOOT 7
#define SCR_SPL_RAW_PPG 8
#define SCR_SPL_ECG_SCR2 9
#define SCR_SPL_FI_SENS_WEAR 10
#define SCR_SPL_FI_SENS_CHECK 11
#define SCR_SPL_BPT_MEASURE 12
#define SCR_SPL_BPT_CAL_COMPLETE 13
#define SCR_SPL_ECG_COMPLETE 14
#define SCR_SPL_PLOT_HRV 15
#define SCR_SPL_SPO2_SCR2 16
#define SCR_SPL_SPO2_MEASURE 17
#define SCR_SPL_SPO2_COMPLETE 18
#define SCR_SPL_SPO2_TIMEOUT 19
#define SCR_SPL_LOW_BATTERY 20
#define SCR_SPL_SPO2_SELECT 21
#define SCR_SPL_BPT_CAL_PROGRESS 22
#define SCR_SPL_BPT_FAILED 23
#define SCR_SPL_BPT_EST_COMPLETE 24
#define SCR_SPL_BPT_CAL_REQUIRED 25
#define SCR_SPL_BLE 26
#define SCR_SPL_SETTINGS 27
#define SCR_SPL_HR_SCR2 28
#define SCR_SPL_PLOT_ECG 29
#define SCR_LIST_START 0
#define SCR_LIST_END 30

// Scroll direction enum
enum scroll_dir {
    SCROLL_NONE = 0,
    SCROLL_LEFT,
    SCROLL_RIGHT,
    SCROLL_UP,
    SCROLL_DOWN
};

// Display refresh intervals
#define HPI_DISP_TIME_REFR_INT 1000
#define HPI_DISP_BATT_REFR_INT 5000
#define HPI_DISP_TEMP_REFRESH_INT 2000
#define HPI_DISP_TRENDS_REFRESH_INT 3000
#define HPI_DISP_TODAY_REFRESH_INT 1000
#define HPI_DISP_SETTINGS_REFRESH_INT 1000

// Data structures
struct hpi_ecg_bioz_sensor_data_t {
    int16_t ecg_samples[32];
    uint8_t ecg_num_samples;
    bool ecg_lead_off;
    int16_t bioz_sample;
    uint8_t bioz_num_samples;
    bool bioz_lead_off;
};

struct hpi_ppg_wr_data_t {
    uint16_t hr;
    uint8_t spo2;
    uint8_t spo2_state;
    uint8_t spo2_valid_percent_complete;
    int32_t ppg_samples[16];
    uint8_t ppg_num_samples;
};

struct hpi_ppg_fi_data_t {
    uint8_t bpt_progress;
    uint8_t spo2_valid_percent_complete;
    uint8_t spo2_state;
    uint8_t spo2;
    uint16_t hr;
    int32_t ppg_samples[16];
    uint8_t ppg_num_samples;
};

struct hpi_computed_hrv_t {
    uint16_t rmssd;
    uint16_t sdnn;
    uint16_t pnn50;
    int64_t timestamp;
};

struct hpi_boot_msg_t {
    char msg[64];
    bool status;
    bool show_status;
};

struct hpi_batt_status_t {
    uint8_t batt_level;
    bool batt_charging;
};

struct hpi_hr_t {
    uint16_t hr;
    int64_t timestamp;
};

struct hpi_spo2_point_t {
    uint8_t spo2;
    int64_t timestamp;
};

struct hpi_steps_t {
    uint32_t steps;
    uint32_t steps_walk;
    uint32_t steps_run;
};

struct hpi_temp_t {
    float temp_f;
    int64_t timestamp;
};

struct hpi_bpt_t {
    uint16_t sys;
    uint16_t dia;
    uint8_t status;
    uint8_t progress;
};

struct hpi_ecg_status_t {
    uint16_t hr;
    int progress_timer;
};

#endif /* MOCK_HPI_COMMON_TYPES_H */
