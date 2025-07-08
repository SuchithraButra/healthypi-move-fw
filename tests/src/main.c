/*
 * Main test entry point for SMF Display Module Tests
 * Compatible with Zephyr Twister test framework
 */

#include <zephyr/ztest.h>

// Include the actual test implementation
#include "test_smf_display_core.c"

// Test main function - required by Twister
void test_main(void)
{
    ztest_run_test_suites(NULL);
}
