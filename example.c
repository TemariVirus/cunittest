#include "cunittest.h"

// A test is declared like this
TEST add_numbers() {
    // All tests must start with START_TEST
    START_TEST("Add numbers");
    
    EXPECT(1 == 1);                    // Booleans
    EXPECT_INT_EQUAL(2, 1 + 1);        // Integers (always converted to long long)
    EXPECT_FLOAT_EQUAL(1.5, 1 + 0.5);  // Floating point (always converted to double)
    EXPECT_STRING_EQUAL("2", "1 + 1"); // Strings
    
    // When not skipping a test, it must end with END_TEST
    END_TEST();
}

TEST multiply_matices() {
    START_TEST("Multiply matrices");
    SKIP_TEST(); // Matrices come in the C3 DLC.
    
    END_TEST(); // This is optional but must come after SKIP_TEST
}

int main(void) {
    add_numbers();
    multiply_matices();

    print_test_summary();
    return 0;
}
