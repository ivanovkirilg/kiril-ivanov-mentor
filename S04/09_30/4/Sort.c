#include "Sort.h"

#include <stdio.h>

typedef void (* sort_func_t) (arr_el_t* arr, size_t n);

static void sort_arr_ascending(arr_el_t* arr, size_t n);
static void sort_arr_descending(arr_el_t* arr, size_t n);

static sort_func_t sort_arr_direction = NULL;

void set_sort_direction(int dir)
{
    if (dir == DIR_ASCENDING) {
        sort_arr_direction = sort_arr_ascending;
    }
    else if (dir == DIR_DESCENDING) {
        sort_arr_direction = sort_arr_descending;
    }
    else
    {
        fprintf(stderr, "Invalid sorting direction %d!\n", dir);
    }
}

void sort_arr(arr_el_t* A, size_t n){
    if (sort_arr_direction != NULL)
    {
        sort_arr_direction(A, n);
    }
    else
    {
        fprintf(stderr, "Sorting direction not set!\n");
    }
}

void print_array(arr_el_t arr[], size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf(ARRAY_ELEMENT_FORMAT " ", arr[i]);
    }
    printf("\n");
}

static void sort_arr_ascending(arr_el_t* arr, size_t n){
    arr_el_t temp = 0;
    for(size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n ; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

static void sort_arr_descending(arr_el_t* arr, size_t n){
    arr_el_t temp = 0;
    for(size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
