/**
 * @file Test.c
 * @author Lu Xu(oliver_lew@outlook.com)
 * @brief test functions
 * @note if a function is declared as "int test...()", it will be collected by
 *       GenerateTest.py and regarded as a test function.
 * This testall() function will test all the functions in this project. The list
 * of the test functions are extracted from functions below in this file matching
 * the pattern "int test...()". Each test function will test one function for a
 * perticular algorithm, returning PASSED(0) or FAILED(1). At last, a report will
 * be printed after everything is finished.
 */

#include <stdio.h>
#include "Test.h"

/**
 * @brief Test all the functions in this project
 */
void testall()
{
    /* the "FUNC_COUNT" is defined in "Test.h", which is the number of test functions. */
    /* the "FUNC_ARRAY" is defined in "Test.h", which is an array of test functions.*/
    /* the "NAME_ARRAY" is defined in "Test.h", which is an array of test functions' names.*/
    int (*tests[FUNC_COUNT])() = FUNC_ARRAY;
    char *names[FUNC_COUNT] = NAME_ARRAY;
    int result[FUNC_COUNT];  /* record the test results */

    for(int i = 0; i < FUNC_COUNT; i++)
    {
        printf("===================================================\n");
        printf("* * * * * * * * * *testing No.%2d* * * * * * * * * *\n", i);
        printf("Function name: %s\n", names[i]);
        result[i] = tests[i]();
        printf("===================================================\n\n");
    }

	/* summary */
    for (int i = 0; i < FUNC_COUNT; i++)
    {
        printf("%s No.%02d %s\n", result[i] ? "*[failed]" : " [passed]", i, names[i]);
    }
}

int main()
{
    testall();
    return 0;
}
