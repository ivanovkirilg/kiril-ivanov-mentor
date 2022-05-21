/*
20.05.2022
Задача 2. Дом Напишете програма, която събира две матрици (4х4) и записва
резултата в трета такава със същия размер. Събирането на матриците става като
намерим сумата на съответстващите елементи в тях. Данните за изходните матрици
трябва да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата.
*/

#include <stdio.h>

#define MATRIX_SIZE 4

void add_matrices(int size, const int left[][size], const int right[][size],
                  int output[][size], int start_row);

void display_matrix(int size, const int matrix[][size]);

int main()
{
    int left_matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        { 1, 3, 5, 7 },
        { -2, -4, -8, -16},
        { 3, 900, 60, 21 },
        { 4, 0, -4, 0 }
    };

    int right_matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        { -2, -4, -8, -16},
        { 1, 3, 5, 7 },
        { 4, 0, -4, 0 },
        { 3, 900, 60, 21 }
    };

    int output_matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

    add_matrices(MATRIX_SIZE, left_matrix, right_matrix, output_matrix, 0);

    display_matrix(MATRIX_SIZE, left_matrix);
    printf("\n+\n");
    display_matrix(MATRIX_SIZE, right_matrix);
    printf("\n=\n");
    display_matrix(MATRIX_SIZE, output_matrix);

    return 0;
}

void add_matrices(int size, const int left[][size], const int right[][size],
                  int output[][size], int start_row)
{
    for (int i = 0; i < size; i++)
    {
        output[start_row][i] = left[start_row][i] + right[start_row][i];
    }

    start_row++;

    if (start_row < size)
    {
        add_matrices(size, left, right, output, start_row);
    }
}

void display_matrix(int size, const int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%10d", matrix[i][j]);
        }

        putchar('\n');
    }
}
