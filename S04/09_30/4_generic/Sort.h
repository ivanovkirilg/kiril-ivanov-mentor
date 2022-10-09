#ifndef SORT
#define SORT

#include <stddef.h>

typedef int (*compare_func)(const void *lhs, const void *rhs);

void sort_array(
        void *arr,
        size_t elem_size,
        size_t elem_count,
        compare_func compare);

#endif // SORT
