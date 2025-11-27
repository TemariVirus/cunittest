#include <stdio.h>
#include <stdlib.h>
#include "cunittest.h"

// A test is declared like this
TEST add_numbers(void) {
    // All tests must start with START_TEST
    START_TEST("Add numbers");
    
    int* numbers = malloc(10 * sizeof(int));
    
    EXPECT(1 == 1);                    // Booleans
    EXPECT_INT_EQUAL(2, 1 + 1);        // Integers (always converted to long long)
    EXPECT_FLOAT_EQUAL(1.5, 1 + 0.5);  // Floating point (always converted to double)
    EXPECT_STRING_EQUAL("2", "1 + 1"); // Strings
    
    // When any EXPECT macro is used, it must end with END_TEST
    END_TEST(
        // This is called whenever an EXPECT fails or everything passes.
        // Use it to clean up after the test.
        free(numbers);
    );
}

TEST multiply_matices(void) {
    START_TEST("Multiply matrices");
    // SKIP_TEST ends the test immediately, and no clean up is performed.
    SKIP_TEST(); // Matrices come in the C3 DLC.
    
    // This is optional because we didn't use any EXPECT macros.
    END_TEST();
}

int main(void) {
    add_numbers();
    multiply_matices();

    print_test_summary();
    return 0;
}
