#include "Sort.h"

#include <stdio.h>
#include <string.h>

void sort_array(
        void *arr,
        size_t elem_size,
        size_t elem_count,
        compare_func compare)
{
    if (arr == NULL)
    {
        fprintf(stderr, "%s failed. Array is null.\n", __func__);
        return;
    }
    if (compare == NULL)
    {
        fprintf(stderr, "%s failed. Compare function is null.\n", __func__);
        return;
    }
    if (elem_size == 0 || elem_count == 0)
    {
        fprintf(stderr, "%s failed. Zero element size/count.\n", __func__);
        return;
    }

    for (size_t i = 0; i < elem_count; i++)
    {
        for (size_t j = i + 1; j < elem_count ; j++)
        {
            void *lhs = arr + (i * elem_size);
            void *rhs = arr + (j * elem_size);

            if (compare(lhs, rhs) < 0)
            {
                unsigned char temp[elem_size]; // Uninitialized
                memcpy(temp, rhs, elem_size);
                memcpy(rhs, lhs, elem_size);
                memcpy(lhs, temp, elem_size);
            }
        }
    }
}
