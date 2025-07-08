#ifndef MOCK_LVGL_H
#define MOCK_LVGL_H

#include <stdint.h>
#include <stdbool.h>

// Mock LVGL types and constants
typedef struct {
    int dummy;
} lv_obj_t;

typedef struct {
    int dummy;
} lv_event_t;

typedef enum {
    LV_EVENT_GESTURE,
    LV_EVENT_CLICKED
} lv_event_code_t;

typedef struct {
    int dummy;
} lv_indev_t;

typedef enum {
    LV_DIR_LEFT,
    LV_DIR_RIGHT,
    LV_DIR_TOP,
    LV_DIR_BOTTOM
} lv_dir_t;

// Mock LVGL functions
static inline uint32_t lv_disp_get_inactive_time(void *disp) { 
    extern int mock_inactivity_time;
    return mock_inactivity_time; 
}

static inline void lv_disp_trig_activity(void *disp) { 
    extern int mock_inactivity_time;
    mock_inactivity_time = 0; 
}

static inline lv_event_code_t lv_event_get_code(lv_event_t *e) { 
    return LV_EVENT_CLICKED; 
}

static inline lv_obj_t *lv_event_get_target(lv_event_t *e) { 
    return NULL; 
}

static inline lv_indev_t *lv_indev_get_act(void) { 
    return NULL; 
}

static inline lv_dir_t lv_indev_get_gesture_dir(lv_indev_t *indev) { 
    return LV_DIR_LEFT; 
}

static inline void lv_indev_wait_release(lv_indev_t *indev) { }

static inline int lv_task_handler(void) { 
    return 0; 
}

#endif /* MOCK_LVGL_H */
