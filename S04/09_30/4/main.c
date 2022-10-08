/*Напишете функция void sort_arr(void *A, int n, int dir, ftype fp),където А е обикновен масив от цели числа, n - размера на масива, dir - посоката, 
в която да бъде сортиран масива, и ftype - указател към функция,която приема масив, неговия размер и в каква посока да бъде сортиран входния масив. 
ftype трябва да сортира масива във възходящ или низходящ ред в зависимост от третия параметър на функцията. Принтирайте изходния и резултатни масиви.*/

#include <stddef.h>

#include "Sort.h"

#define SIZE_OF_ARRAY 5

int main() {
    arr_el_t arr[SIZE_OF_ARRAY] = {1.5, 6.2, 1.2, 1.9, 9};
    print_array(arr, SIZE_OF_ARRAY);

    enum sort_dir directions[] = {
        DIR_DESCENDING,
        DIR_ASCENDING
    };

    const int dir_count = sizeof(directions)/sizeof(directions[0]);
    for (int dir_idx = 0; dir_idx < dir_count; dir_idx++)
    {
        set_sort_direction(directions[dir_idx]);
        sort_arr(arr, SIZE_OF_ARRAY);
        print_array(arr, SIZE_OF_ARRAY);
    }
}
