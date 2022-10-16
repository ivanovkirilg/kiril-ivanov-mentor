/*
Напишете функции, с помощта на които да реализирате динамичен масив от елементи,
чиято големина може да се променя по време на изпълнение на програмата.
*/

#include <stdio.h>

#include "DynArray.h"

int main()
{
    Error error = NO_ERROR;
    struct DynArray numbers = {0};

    error = DynArr_resize(&numbers, 5);

    for (size_t i = 0; (i < numbers.size) && (!error); i++)
    {
        int res = scanf(" %d", &numbers.data[i]);

        if (res == 0) // Nothing was successfully read
        {
            error = INPUT_ERROR;
        }
    }

    if (!error)
    {
        error = DynArr_resize(&numbers, 2);
    }

    if (!error)
    {
        for (size_t i = 0; i < numbers.size; i++)
        {
            printf("%d ", numbers.data[i]);
        }
    }

    if (error)
    {
        printf("Program encountered fatal error.\n");
        return SYSTEM_ERROR;
    }

    return NO_ERROR;
}
