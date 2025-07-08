# SMF Display Module Tests

This directory contains unit tests for the SMF Display module using Zephyr's Twister test framework.

## Test Overview

The test suite validates core functionality of the display state machine including:

- Screen management and transitions
- State persistence during sleep/wake cycles  
- Calorie calculation algorithms
- Message queue operations
- Hardware interaction mocking

## Running Tests

### Prerequisites
- Zephyr SDK installed and configured
- West build tool available
- Python with required Zephyr dependencies

### Run with Twister (Recommended)

From the Zephyr workspace root:
```bash
# Run all SMF display tests
./scripts/twister -T tests/ -t smf_display.core

# Run with verbose output
./scripts/twister -T tests/ -t smf_display.core -v

# Run on specific platform
./scripts/twister -T tests/ -t smf_display.core -p qemu_x86

# Run with coverage report (if enabled)
./scripts/twister -T tests/ -t smf_display.core --coverage
```

From this test directory:
```bash
# Run tests using relative path to twister
../../scripts/twister -T . -t smf_display.core

# Run on native POSIX for faster execution
../../scripts/twister -T . -t smf_display.core -p native_posix
```

### Manual Build and Run

```bash
# Build for QEMU x86
west build -b qemu_x86

# Run tests
west build -t run
```

### Run on Native POSIX (Fastest)

```bash
# Build for native POSIX
west build -b native_posix

# Run directly
./build/zephyr/zephyr.exe
```

## Test Configuration

- **testcase.yaml**: Twister test configuration
- **prj.conf**: Zephyr project configuration  
- **CMakeLists.txt**: Build configuration
- **src/main.c**: Test entry point
- **src/mocks/**: Mock implementations for dependencies

## Expected Output

```
*** Booting Zephyr OS build zephyr-v3.x.x ***
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

## Test Coverage

The test suite includes 22 comprehensive tests covering:

1. **Screen Management** (5 tests)
   - Basic screen setting/getting
   - Boundary condition handling
   - Thread safety validation

2. **State Persistence** (4 tests)  
   - Save/restore functionality
   - State clearing
   - Error handling

3. **Calorie Calculation** (4 tests)
   - Mathematical accuracy
   - Proportionality testing
   - Edge cases

4. **Message Queue Operations** (5 tests)
   - Data integrity
   - Queue management
   - Overflow/underflow conditions

5. **Hardware Interaction** (3 tests)
   - Battery status detection
   - Inactivity timer
   - Sleep condition logic

6. **Data Validation** (2 tests)
   - Structure integrity
   - Reset functionality

## Troubleshooting

### Build Issues
- Ensure Zephyr environment is properly configured
- Check that all CONFIG options in prj.conf are supported
- Verify mock headers are accessible

### Test Failures  
- Check mock data matches expected values
- Verify calculation algorithms for expected precision
- Ensure test independence (no shared state between tests)

### Performance Issues
- Use native_posix platform for fastest execution
- Reduce timeout values if tests complete quickly
- Consider parallel execution with Twister's -j option

## Adding New Tests

1. Add test functions to `src/test_smf_display_core.c`
2. Use ZTEST macro: `ZTEST(smf_display_core, test_name)`
3. Update mock implementations as needed
4. Run tests to verify functionality

## Integration with CI/CD

This test suite is designed to integrate with automated testing:

```bash
# CI pipeline example
./scripts/twister -T tests/ -t smf_display.core --coverage --xml-out results.xml
```

The Twister framework provides JUnit XML output for integration with common CI systems.
