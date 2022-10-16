#ifndef KIRIL_IVANOV_MENTOR_S04_10_07_DATE_UTILS
#define KIRIL_IVANOV_MENTOR_S04_10_07_DATE_UTILS

#include <stdbool.h>

struct Date
{
    unsigned short int day:   5;
    unsigned short int month: 4;
    unsigned short int year: 14;
};

enum DateValidation
{
    DATE_VALID,
    DAY_INVALID,
    MONTH_INVALID,
    YEAR_INVALID
};

enum Month
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,

    MONTH_COUNT,

    MIN_MONTH = JANUARY,
    MAX_MONTH = DECEMBER,
};

void printDate(const struct Date *date);

bool isLeapYear(int year);
enum DateValidation isValidDate(const struct Date *date);


#endif // KIRIL_IVANOV_MENTOR_S04_10_07_DATE_UTILS
