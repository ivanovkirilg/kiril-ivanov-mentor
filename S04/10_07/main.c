/*
    Задача 4. Напишете тип за дата, използвайки битови полета. Направете
    функция, която извежда дата, използвайки новия тип. Направете функция,
    която валидира датата.
*/

// The test.c file also has a main() function.
// This main is built by default, unless -DTEST_BUILD is passed to the compiler.
#ifndef TEST_BUILD

#include <stdio.h>
#include "DateUtils.h"

unsigned short readUshort(const char *prompt);


int main()
{
    printf("Enter a date between years 1900 and 9999:\n");

    struct Date date = {
        .day   = readUshort("Day: "),
        .month = readUshort("Month: "),
        .year  = readUshort("Year: ")
    };

    printDate(&date);

    enum DateValidation validDate = validateDate(&date);

    printf(  (validDate == DAY_INVALID)   ? "Day is invalid.\n"
           : (validDate == MONTH_INVALID) ? "Month is invalid.\n"
           : (validDate == YEAR_INVALID)  ? "Year is invalid.\n"
           :                                "Date is valid.\n");

    printf("size of date is %zu B\n", sizeof(date));

    return 0;
}


unsigned short readUshort(const char *prompt)
{
    if (prompt) { puts(prompt); }

    unsigned short input = 0;
    scanf("%hu", &input);

    return input;
}

#endif // TEST_BUILD
