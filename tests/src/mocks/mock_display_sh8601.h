#ifndef MOCK_DISPLAY_SH8601_H
#define MOCK_DISPLAY_SH8601_H

#include <stdint.h>

// Mock device structure
struct device {
    const char *name;
};

// Mock display functions
static inline int sh8601_reinit(const struct device *dev) { 
    return 0; 
}

static inline int display_blanking_off(const struct device *dev) { 
    return 0; 
}

static inline int display_set_brightness(const struct device *dev, uint8_t brightness) { 
    return 0; 
}

#endif /* MOCK_DISPLAY_SH8601_H */
