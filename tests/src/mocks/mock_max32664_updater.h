#ifndef MOCK_MAX32664_UPDATER_H
#define MOCK_MAX32664_UPDATER_H

// MAX32664 updater status definitions
#define MAX32664_UPDATER_STATUS_IDLE 0
#define MAX32664_UPDATER_STATUS_IN_PROGRESS 1
#define MAX32664_UPDATER_STATUS_SUCCESS 2
#define MAX32664_UPDATER_STATUS_FAILED 3

// Function pointer type for progress callback
typedef void (*max32664_progress_callback_t)(int progress, int status);

// Mock MAX32664 updater functions
static inline void max32664_set_progress_callback(max32664_progress_callback_t callback) {
    // Mock implementation - store callback if needed
}

#endif /* MOCK_MAX32664_UPDATER_H */
