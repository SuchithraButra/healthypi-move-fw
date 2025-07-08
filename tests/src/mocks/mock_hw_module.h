#ifndef MOCK_HW_MODULE_H
#define MOCK_HW_MODULE_H

#include <stdbool.h>

// Mock hardware functions
static inline bool hw_is_low_battery(void) {
    extern bool mock_low_battery;
    return mock_low_battery;
}

static inline void hw_pwr_display_enable(bool enable) {
    // Mock implementation - do nothing
}

#endif /* MOCK_HW_MODULE_H */
