#ifndef MOCK_HPI_SYS_H
#define MOCK_HPI_SYS_H

#include <stdint.h>
#include <stdbool.h>

// Mock Zephyr kernel structures
struct k_sem {
    int count;
    int limit;
};

struct k_msgq {
    char *buffer;
    size_t msg_size;
    uint32_t max_msgs;
};

struct device {
    const char *name;
};

// Mock LVGL object
typedef struct {
    int dummy;
} lv_obj_t;

// Mock system functions - empty implementations for testing
static inline void hpi_display_sleep_on(void) { }

// Mock semaphore operations
static inline int k_sem_take(struct k_sem *sem, int timeout) { 
    return -1; // EBUSY - not available
}

static inline void k_sem_give(struct k_sem *sem) { 
    // Mock implementation
}

static inline int k_msgq_get(struct k_msgq *msgq, void *data, int timeout) {
    return -1; // No messages
}

static inline int k_msgq_put(struct k_msgq *msgq, const void *data, int timeout) {
    return 0; // Success
}

// Mock device functions
static inline int device_init(const struct device *dev) { 
    return 0; 
}

static inline bool device_is_ready(const struct device *dev) { 
    return true; 
}

// Mock external variables (declare but don't define - will be defined in test)
extern struct k_sem sem_disp_smf_start;
extern struct k_sem sem_disp_boot_complete;
extern struct k_sem sem_boot_update_req;
extern struct k_sem sem_crown_key_pressed;
extern struct k_sem sem_ecg_lead_on;
extern struct k_sem sem_ecg_lead_off;
extern struct k_sem sem_stop_one_shot_spo2;
extern struct k_sem sem_spo2_complete;
extern struct k_sem sem_bpt_sensor_found;
extern struct k_sem sem_ecg_complete_reset;

extern struct k_msgq q_ecg_bioz_sample;
extern struct k_msgq q_ppg_wrist_sample;

extern const struct device *display_dev;
extern const struct device *touch_dev;
extern lv_obj_t *scr_bpt;

#endif /* MOCK_HPI_SYS_H */
