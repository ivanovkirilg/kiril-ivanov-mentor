#ifdef TEST_BUILD

#include <stdio.h>
#include "DateUtils.h"

int g_testsRun = 0;

void test_printDate()
{
    // NULL pointer
    {
        printDate(NULL);
    }

    // Zero-initialized date
    {
        struct Date date = {0};
        printDate(&date);
    }

    // Min and Max (declared) dates
    {
        struct Date min = { .day = 1, .month = 1, .year = 1900 };
        struct Date max = { .day = 31, .month = 12, .year = 9999 };
        printDate(&min);
        printDate(&max);
    }

    // Invalid date
    {
        struct Date date = { .day = 30, .month = 2, .year = 2000 };
        printDate(&date);
    }

    g_testsRun++;
}

int test_validateDate()
{
    int fails = 0;
    // NULL pointer
    {
        validateDate(NULL);
    }

    // Zero-initialized date
    {
        struct Date date = {0};
        const enum DateValidation result = validateDate(&date);

        if (result == DATE_VALID)
            fails++;
    }

    // Min and Max (declared) dates
    {
        struct Date min = { .day = 1, .month = 1, .year = 1900 };
        struct Date max = { .day = 31, .month = 12, .year = 9999 };
        const enum DateValidation min_result = validateDate(&min);
        const enum DateValidation max_result = validateDate(&max);

        if (min_result != DATE_VALID)
            fails++;

        if (max_result != DATE_VALID)
            fails++;
    }

    // Invalid generic dates
    {
        struct Date invalidDay   = { .day = 0,  .month = 1,  .year = 2000 };
        struct Date invalidMonth = { .day = 15, .month = 15, .year = 2000 };
        struct Date invalidYear  = { .day = 15, .month = 1,  .year = 0    };
        const enum DateValidation resultDay = validateDate(&invalidDay);
        const enum DateValidation resultMonth = validateDate(&invalidMonth);
        const enum DateValidation resultYear = validateDate(&invalidYear);
    
        if (resultDay   != DAY_INVALID)
            fails++;
        if (resultMonth != MONTH_INVALID)
            fails++;
        if (resultYear  != YEAR_INVALID)
            fails++;
    }

    // Invalid Feb dates
    {
        struct Date date29 = { .day = 29, .month = 2, .year = 1999 };
        struct Date date30 = { .day = 30, .month = 2, .year = 1999 };
        struct Date date31 = { .day = 31, .month = 2, .year = 1999 };
        const enum DateValidation result29 = validateDate(&date29);
        const enum DateValidation result30 = validateDate(&date30);
        const enum DateValidation result31 = validateDate(&date31);
    
        if (result29 != DAY_INVALID)
            fails++;
        if (result30 != DAY_INVALID)
            fails++;
        if (result31 != DAY_INVALID)
            fails++;
    }

    g_testsRun++;
    return fails;
}

int main()
{
    int fails = 0;

    test_printDate();

    fails += test_validateDate();

    // FIXME: Test not written
    // fails += test_isLeapYear();

    if (fails)
    {
        printf("Failed %d expectations.\n", fails);
    }
    else
    {
        printf("Passed %d tests.\n", g_testsRun);
    }

    return 0;
}


#endif // TEST_BUILD
