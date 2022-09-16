/*
20.05.2022
Задача 6*. Дом Напишете програма, която печата броя на уникалните редове в бинарна
матрица, съставена само от единици и нули.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int count_unique_rows(int rows, int cols, const int matrix[rows][cols]);

int main()
{
    int matrix[][6] = {
        { 0, 1, 0, 1, 0, 1 }, // 1
        { 0, 1, 0, 1, 0, 0 }, // 2
        { 0, 1, 0, 1, 0, 1 }, // repeat
        { 0, 0, 0, 0, 0, 0 }, // 3
        { 1, 1, 1, 1, 1, 1 }, // 4
        { 0, 0, 0, 0, 0, 0 }, // repeat
        { 0, 1, 0, 1, 0, 1 }, // repeat
    };

    printf("Found %d unique rows.\n",
        count_unique_rows(sizeof(matrix)/sizeof(matrix[0]), 6, matrix)
    );

    // == Performance test ==

    // srand(2);
    // int (*matrix)[32] = malloc(sizeof(int) * 50000 * 32);
    // for (int i = 0; i < 50000; i++)
    // {
    //     for (int j = 0; j < 32; j++)
    //     {
    //         matrix[i][j] = rand() % 2;
    //     }
    // }
    // printf("%d\n", count_unique_rows(50000, 32, matrix));
}

// Precondition: the matrix is binary
int count_unique_rows(int rows, int cols, const int matrix[rows][cols])
{
    if (cols > 64)
    {
        printf("ERROR: Function not implemented for more than 64 columns.\n");
        return -1;
    }

    int nr_of_unique_rows = rows;
    uint64_t *cached_rows = calloc(rows, sizeof(uint64_t));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cached_rows[i] ^= (uint64_t) (matrix[i][j]) << j;
        }

        for (int j = 0; j < i; j++)
        {
            if (cached_rows[i] == cached_rows[j])
            {
                nr_of_unique_rows--;
                printf("Found duplicate row %d=%d: %.16lx.\n",
                       i, j, cached_rows[i]);
                break;
            }
        }
    }

    free(cached_rows);

    return nr_of_unique_rows;
}
