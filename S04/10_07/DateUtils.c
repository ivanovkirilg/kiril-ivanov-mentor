#include "DateUtils.h"

#include <stdio.h>

void printDate(const struct Date *date)
{
    if (date == NULL)
    {
        fprintf(stderr, "%s: NULL pointer received.\n", __func__);
        return;
    }

    printf("Date is %2d/%d/%d\n", date->day, date->month, date->year);
}

bool isLeapYear(int year)
{
    bool isLeapYear = false;

    // Thank you Ognyan!
    isLeapYear =   (year % 400 == 0)
                || ((year % 4 == 0) && (year % 100 != 0));

    return isLeapYear;
}

enum DateValidation validateDate(const struct Date *date)
{
    if (date == NULL)
    {
        fprintf(stderr, "%s: NULL pointer received.\n", __func__);
        return -1;  // FIXME: Better to have a constant for this.
                    //  Or perhaps return a combined mask of errors, so
                    //  00/0/0000 is DAY_INVALID | MONTH_INVALID | YEAR_INVALID
    }

    const unsigned short int MAX_DAYS[] = {
        [JANUARY]   = 31,
        [FEBRUARY]  = isLeapYear(date->year) ?
                      29 : 28,
        [MARCH]     = 31,
        [APRIL]     = 30,
        [MAY]       = 31,
        [JUNE]      = 30,
        [JULY]      = 31,
        [AUGUST]    = 31,
        [SEPTEMBER] = 30,
        [OCTOBER]   = 31,
        [NOVEMBER]  = 30,
        [DECEMBER]  = 31
    };

    if (date->year < 1900 || date->year > 9999)
    {
        return YEAR_INVALID;
    }

    if (date->month < MIN_MONTH || date->month > MAX_MONTH)
    {
        return MONTH_INVALID;
    }

    if ((date->day < 1) || (date->day > MAX_DAYS[date->month]))
    {
        return DAY_INVALID;
    }

    return DATE_VALID;
}

// An alternative to the array in validateDate
unsigned short getMaxDay(unsigned short month, unsigned short year)
{
    switch (month)
    {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;

        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;

        case FEBRUARY:
            return ( isLeapYear(year) ) ? 29 : 28;

        default:
            return 0;
    }
}
