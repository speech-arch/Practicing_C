#include <assert.h>
#include "test_suit.h"

// Run all available tests
void run_all(tTestSuite* test_suite) {
    assert(test_suite != NULL);

    // Initialize the test Suite
    testSuite_init(test_suite);

    // Run tests for PR1
    run_pr1(test_suite);
}
