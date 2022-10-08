#ifndef RADINA_KEHAYOVA_S04_HOMEWORKS_09_30_4_SORT
#define RADINA_KEHAYOVA_S04_HOMEWORKS_09_30_4_SORT

#include <stddef.h>

#define ARRAY_ELEMENT_FORMAT "%f"
typedef float arr_el_t;

enum sort_dir
{
    DIR_ASCENDING = 1,
    DIR_DESCENDING = -1
};

void set_sort_direction(int dir);
void sort_arr(arr_el_t* A, size_t n);
void print_array(arr_el_t arr[], size_t n);

#endif // RADINA_KEHAYOVA_S04_HOMEWORKS_09_30_4_SORT
