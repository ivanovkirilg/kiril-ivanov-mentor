/*
Напишете функции, с помощта на които да реализирате динамичен масив от елементи,
чиято големина може да се променя по време на изпълнение на програмата.
*/

#include <stdio.h>

#include "DynArray.h"

#define FATAL_ERROR 1

int main()
{
    struct DynArray numbers = {0};
    Error error = NO_ERROR;

    error = resize(&numbers, 5);

    if (error != NO_ERROR)
    {
        printf("Program encountered fatal error.\n");
        return FATAL_ERROR;
    }

    for (size_t i = 0; i < numbers.size; i++)
    {
        scanf(" %d", &numbers.data[i]);
    }

    error = resize(&numbers, 2);

    if (error != NO_ERROR)
    {
        printf("Program encountered fatal error.\n");
        return FATAL_ERROR;
    }

    for (size_t i = 0; i < numbers.size; i++)
    {
        printf("%d ", numbers.data[i]);
    }
}
