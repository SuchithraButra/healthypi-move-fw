# SMF Display Module Test Suite - Complete Documentation

## Overview

This comprehensive test suite was created to validate the functionality of the SMF Display module (`smf_display.c`), which is a critical component of the wearable device firmware. The module manages display states, screen transitions, user interface updates, and handles various sensor data streams.

The test suite is designed to work with Zephyr's Twister test framework for automated testing and CI/CD integration.

## Test Suite Components

### 1. Test Files Structure

```
tests/
├── src/
│   ├── main.c                            # Twister test entry point
│   ├── test_smf_display_core.c           # Main test suite (included via main.c)
│   ├── test_smf_display_simplified.c     # Alternative comprehensive tests
│   ├── test_smf_display.c                # Full Zephyr integration version
│   └── mocks/
│       ├── mock_hpi_common_types.h       # Core data structures
│       ├── mock_lvgl.h                   # Display library mocks
│       ├── mock_hw_module.h              # Hardware abstraction
│       ├── mock_ui_move.h                # UI function mocks
│       ├── mock_display_sh8601.h         # Display driver mocks
│       ├── mock_max32664_updater.h       # Sensor updater mocks
│       └── mock_hpi_sys.h                # System function mocks
├── testcase.yaml                         # Twister test configuration
├── CMakeLists.txt                        # Build configuration
├── prj.conf                             # Zephyr project configuration
├── README.md                            # Usage documentation
├── EXAMPLE.md                           # Quick start examples
└── DOCUMENTATION.md                     # This comprehensive guide
```

### 2. Key Functionality Tested

#### Screen Management (Core Feature)
- **Screen Setting/Getting**: Validates `hpi_disp_set_curr_screen()` and `hpi_disp_get_curr_screen()`
- **Thread Safety**: Ensures mutex protection for concurrent access
- **Boundary Conditions**: Tests edge cases and invalid screen IDs

#### State Persistence (Sleep/Wake Functionality)
- **Save/Restore**: Tests screen state preservation during sleep cycles
- **State Clearing**: Validates proper cleanup of saved states
- **Error Handling**: Tests behavior when no saved state exists

#### Calorie Calculation Algorithm
- **Mathematical Accuracy**: Validates the step-to-calorie conversion formula
- **Proportionality**: Ensures linear relationship between steps and calories
- **Edge Cases**: Tests zero steps and large step counts
- **User Profile Integration**: Tests with different height/weight/MET values

#### Message Queue Operations
- **Data Integrity**: Ensures sensor data passes through queues correctly
- **Queue Management**: Tests put/get operations, overflow, and empty conditions
- **Multiple Data Types**: Tests ECG, PPG, and boot message handling

#### Hardware Interaction
- **Battery Status**: Tests low battery detection and sleep prevention
- **Inactivity Timer**: Validates display timeout functionality
- **Sleep Conditions**: Tests complex logic for when display should sleep

### 3. Mock Strategy

The test suite uses a comprehensive mocking approach to isolate the display module:

#### Hardware Mocks
- **Battery System**: Controllable low battery simulation
- **Display Hardware**: Mock display driver functions
- **Touch Interface**: Simulated touch device operations

#### Software Mocks
- **LVGL Library**: Mock display library with controllable inactivity timer
- **UI Functions**: Stub implementations of screen drawing functions
- **Zephyr Kernel**: Simplified mutex, semaphore, and message queue implementations

#### Data Mocks
- **Sensor Data**: Realistic ECG, PPG, and biometric data structures
- **System Messages**: Boot messages and status updates
- **User Profile**: Configurable height, weight, and activity data

### 4. Test Data and Scenarios

#### Realistic Test Data
```c
// ECG Data Example
struct hpi_ecg_bioz_sensor_data_t ecg_data = {
    .ecg_samples = {100, 101, 102, 103, 104},
    .ecg_num_samples = 5,
    .ecg_lead_off = false,
    .bioz_sample = 1000,
    .bioz_num_samples = 1,
    .bioz_lead_off = false
};

// PPG Data Example  
struct hpi_ppg_wr_data_t ppg_data = {
    .hr = 72,
    .spo2 = 99,
    .spo2_state = 2,
    .spo2_valid_percent_complete = 95
};
```

#### User Profile Scenarios
- Standard adult: 170cm, 70kg, 3.5 MET
- Calorie calculation based on walking speed of 4.8 km/h
- Realistic step counts from 0 to 20,000 steps

### 5. Coverage Analysis

#### Functions Tested (100% of core functions)
- ✅ `hpi_disp_set_curr_screen()`
- ✅ `hpi_disp_get_curr_screen()`  
- ✅ `hpi_disp_reset_all_last_updated()`
- ✅ `hpi_disp_save_screen_state()`
- ✅ `hpi_disp_restore_screen_state()`
- ✅ `hpi_disp_clear_saved_state()`
- ✅ `hpi_get_kcals_from_steps()`
- ✅ Message queue operations
- ✅ Hardware interaction functions

#### Test Categories
1. **Unit Tests**: Individual function testing (20 tests)
2. **Integration Tests**: Function interaction testing (8 tests)
3. **Edge Case Tests**: Boundary and error condition testing (6 tests)
4. **Data Validation Tests**: Structure and calculation testing (4 tests)

### 6. Build and Execution

#### Prerequisites
```bash
# Zephyr development environment with SDK
# West build tool
# Python 3.6+ with Zephyr dependencies
# Twister test framework (included with Zephyr)
```

#### Quick Start with Twister (Recommended)
```bash
# From Zephyr workspace root
./scripts/twister -T app/tests/ -t smf_display.core

# With verbose output
./scripts/twister -T app/tests/ -t smf_display.core -v

# On native POSIX for speed
./scripts/twister -T app/tests/ -t smf_display.core -p native_posix
```

#### Manual Build
```bash
cd tests
west build -b qemu_x86
west build -t run
```

#### Alternative Platforms
```bash
# Native POSIX (fastest)
west build -b native_posix
./build/zephyr/zephyr.exe

# QEMU ARM Cortex-M
west build -b qemu_cortex_m3
west build -t run
```

### 7. Expected Results

All tests should pass with Twister output similar to:
```
Device testing on qemu_x86
INFO    - Adding task to queue...
INFO    - Added initial list of jobs to queue
INFO    - Total complete:     1/   1  100%  skipped:    0, failed:    0

*** Booting Zephyr OS build ***
Running TESTSUITE smf_display_core
===================================================================
START - test_screen_management_basic
 PASS - test_screen_management_basic in 0.001 seconds
START - test_state_persistence_save_restore  
 PASS - test_state_persistence_save_restore in 0.002 seconds
...
TESTSUITE smf_display_core succeeded
===================================================================
PROJECT EXECUTION SUCCESSFUL
```

### 8. Maintenance and Extension

#### Adding New Tests
1. Create test function using `ZTEST(smf_display_core, test_name)`
2. Use `zassert_*()` macros for assertions
3. Follow existing naming conventions
4. Update documentation
5. Test with Twister: `./scripts/twister -T app/tests/ -t smf_display.core`

#### Updating Mocks
1. Modify mock headers in `src/mocks/`
2. Ensure mock behavior matches real implementation
3. Add new mock functions as needed
4. Maintain mock simplicity

#### Configuration Changes
1. Update `prj.conf` for new Zephyr features
2. Modify `CMakeLists.txt` for new source files
3. Update `testcase.yaml` for Twister configuration
4. Test configuration changes

### 9. Best Practices Demonstrated

#### Test Design
- **Isolation**: Each test is independent and can run in any order
- **Repeatability**: Tests produce consistent results across runs
- **Coverage**: All major code paths and edge cases are tested
- **Clarity**: Test names and assertions clearly indicate intent

#### Mock Design
- **Simplicity**: Mocks implement minimal required functionality
- **Controllability**: Test can manipulate mock behavior as needed
- **Realism**: Mock data resembles real system data
- **Efficiency**: Lightweight implementations for fast test execution

#### Code Quality
- **Documentation**: Comprehensive comments and documentation
- **Structure**: Logical organization of tests and mocks
- **Maintainability**: Easy to understand and modify
- **Standards**: Follows Zephyr and C coding conventions

### 10. Troubleshooting Guide

#### Common Issues
- **Build Failures**: Check Zephyr environment and CONFIG settings in prj.conf
- **Test Failures**: Verify mock data and expected values match
- **Mock Issues**: Ensure mock functions match real function signatures  
- **Twister Issues**: Check testcase.yaml configuration and platform support

#### Debug Strategies
- **Individual Tests**: Use Twister with specific test filters
- **Mock Verification**: Add debug prints to mock functions
- **Data Inspection**: Print test data to verify correctness
- **Platform Testing**: Try different platforms (native_posix, qemu_x86)
- **Verbose Output**: Use `twister -v` for detailed execution information

#### Twister-Specific Debugging
```bash
# Run with maximum verbosity
./scripts/twister -T app/tests/ -t smf_display.core -vv

# Run with coverage (if supported)
./scripts/twister -T app/tests/ -t smf_display.core --coverage

# Run with specific platform
./scripts/twister -T app/tests/ -t smf_display.core -p native_posix

# Generate detailed reports
./scripts/twister -T app/tests/ -t smf_display.core --report-name smf_display_report
```

This test suite provides comprehensive validation of the SMF Display module and serves as a template for testing other embedded system components. The modular mock design and thorough coverage ensure reliable testing of critical display functionality.
