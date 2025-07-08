# Example: Running SMF Display Tests with Twister

## Quick Start Example

This example shows how to run the SMF Display module tests using Zephyr's Twister framework.

### Step 1: Navigate to Zephyr Workspace
```bash
cd path/to/your/zephyr/workspace
```

### Step 2: Run Tests with Twister
```bash
# Run the SMF display tests
./scripts/twister -T app/tests/ -t smf_display.core

# Run with verbose output for debugging
./scripts/twister -T app/tests/ -t smf_display.core -v

# Run on native POSIX for faster execution
./scripts/twister -T app/tests/ -t smf_display.core -p native_posix
```

### Step 3: View Results
```
Device testing on qemu_x86
Finished in 3.2 seconds

INFO    - JOBS: 1 PASS: 1 FAIL: 0 SKIP: 0 
INFO    - 1 test configurations selected, 1 tests being run
INFO    - Adding tasks to the queue...
INFO    - Added initial list of jobs to queue
INFO    - Total complete:     1/   1  100%  skipped:    0, failed:    0
INFO    - In 3.2 seconds
```

### Expected Test Output
```
*** Booting Zephyr OS build ***
Running TESTSUITE smf_display_core
===================================================================
START - test_screen_management_basic
 PASS - test_screen_management_basic in 0.001 seconds
START - test_screen_management_boundaries  
 PASS - test_screen_management_boundaries in 0.001 seconds
START - test_state_persistence_save_restore
 PASS - test_state_persistence_save_restore in 0.002 seconds
START - test_state_persistence_clear
 PASS - test_state_persistence_clear in 0.001 seconds
START - test_state_persistence_no_saved_state
 PASS - test_state_persistence_no_saved_state in 0.001 seconds
START - test_calorie_calculation_zero_steps
 PASS - test_calorie_calculation_zero_steps in 0.001 seconds
START - test_calorie_calculation_basic
 PASS - test_calorie_calculation_basic in 0.001 seconds
START - test_calorie_calculation_proportional
 PASS - test_calorie_calculation_proportional in 0.001 seconds
START - test_calorie_calculation_large_values
 PASS - test_calorie_calculation_large_values in 0.001 seconds
START - test_message_queue_ecg_basic
 PASS - test_message_queue_ecg_basic in 0.001 seconds
START - test_message_queue_ppg_basic
 PASS - test_message_queue_ppg_basic in 0.001 seconds
START - test_message_queue_boot_msg
 PASS - test_message_queue_boot_msg in 0.001 seconds
START - test_message_queue_overflow
 PASS - test_message_queue_overflow in 0.001 seconds
START - test_message_queue_empty
 PASS - test_message_queue_empty in 0.001 seconds
START - test_hardware_battery_status
 PASS - test_hardware_battery_status in 0.001 seconds
START - test_inactivity_timer
 PASS - test_inactivity_timer in 0.001 seconds
START - test_sleep_conditions
 PASS - test_sleep_conditions in 0.002 seconds
START - test_reset_functionality
 PASS - test_reset_functionality in 0.001 seconds
START - test_data_structure_integrity
 PASS - test_data_structure_integrity in 0.001 seconds
===================================================================
TESTSUITE smf_display_core succeeded

PROJECT EXECUTION SUCCESSFUL
```

### Alternative: Manual Build and Run
```bash
# Navigate to test directory
cd app/tests/

# Build for QEMU
west build -b qemu_x86

# Run tests
west build -t run
```

### Alternative: Native POSIX (Fastest)
```bash
cd app/tests/
west build -b native_posix
./build/zephyr/zephyr.exe
```

## Integration with CI/CD Pipeline

### Jenkins Example
```groovy
pipeline {
    agent any
    stages {
        stage('Test') {
            steps {
                sh './scripts/twister -T app/tests/ -t smf_display.core --xml-out test-results.xml'
            }
            post {
                always {
                    junit 'test-results.xml'
                }
            }
        }
    }
}
```

### GitHub Actions Example
```yaml
name: SMF Display Tests
on: [push, pull_request]
jobs:
  test:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    - name: Setup Zephyr
      run: |
        # Setup Zephyr environment
    - name: Run Tests
      run: |
        ./scripts/twister -T app/tests/ -t smf_display.core
```

This example demonstrates the complete workflow for running the SMF Display module tests using Twister.
