/*
20.05.2022
Задача 6*. Дом Напишете програма, която печата броя на уникалните редове в бинарна
матрица, съставена само от единици и нули.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_unique_rows_naive(int rows, int cols, const int matrix[rows][cols]);

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
        count_unique_rows_naive(sizeof(matrix)/sizeof(matrix[0]), 6, matrix)
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
    // printf("%d\n", count_unique_rows_naive(50000, 32, matrix));
}

bool rows_equal(int size, const int left[size], const int right[size])
{
    for (int i = 0; i < size; i++)
    {
        if (left[i] != right[i])
        {
            return false;
        }
    }

    return true;
}

int count_unique_rows_naive(int rows, int cols, const int matrix[rows][cols])
{
    int nr_of_unique_rows = rows;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rows_equal(cols, matrix[i], matrix[j]))
            {
                nr_of_unique_rows--;
                printf("Found duplicate row %d=%d.\n", i, j);
                break;
            }
        }
    }

    return nr_of_unique_rows;
}
