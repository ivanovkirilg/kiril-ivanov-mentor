/*
ДОМАШНО Задача 3. Напишете програма, която калкулира разликата на
два времеви периода, изразени във векове, години, месеци, дни, ----hours?----
минути, секудни. Принтирайте изходните периоди и резултата.
*/
#include <stdio.h>

#define NR_OF_FIELDS 7

const int INTERVALS[NR_OF_FIELDS] = { 60, 60, 24, 30, 12, 100, 0 };

typedef union
{
    struct
    {
        int seconds;
        int minutes;
        int hours;
        int days;
        int months;
        int years;
        int centuries;
    };

    int fields[NR_OF_FIELDS];
} Period;

Period comparePeriods(Period, Period);

int main()
{
    Period first = {
        .centuries = 12,
        .years     = 3,
        .months    = 5,
        .days      = 7,
        .hours     = 9,
        .minutes   = 0,
        .seconds   = 7
    };

    Period second = {
        .centuries = 3,
        .years     = 12,
        .months    = 3,
        .days      = 4,
        .hours     = 6,
        .minutes   = 8,
        .seconds   = 0
    };

    Period result = comparePeriods(first, second);

    printf("periods comparison result:\n"
           "%d centuries\n%d years\n%d months\n%d days\n"
           "%d hours\n%d minutes\n%d seconds\n",
           result.centuries, result.years, result.months, result.days,
           result.hours, result.minutes, result.seconds);

    return 0;
}

Period comparePeriods(Period a, Period b)
{
    Period result;

    for (size_t i = 0; i < NR_OF_FIELDS; i++)
    {
        if ((i < NR_OF_FIELDS - 1) && (a.fields[i] < b.fields[i]))
        {
            a.fields[i + 1]--;
            a.fields[i] += INTERVALS[i];
        }
        result.fields[i] = a.fields[i] - b.fields[i];
    }

    return result;
}
