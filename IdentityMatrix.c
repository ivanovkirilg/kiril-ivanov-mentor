#include <stdio.h>
#include <stdbool.h>

void display_matrix(int rows, int cols, const int matrix[rows][cols]);
void test_id_matrix(const int (*matrix)[5], bool is_rect, bool expected);

bool is_identity_matrix(int rows, int cols, const int matrix[rows][cols])
{
    return false;
}

int main()
{
    // Compile with -Wall (or just -Wunused-variable) to make sure all are tested.
    int id_matrix[5][5] = {
        { 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1 },
    };

    int id_matrix_rect[4][5] = {
        { 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
    };

    int non_id_matrix_1[5][5] = {
        { 1, 0, 0, 1, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 1 },
    };

    int non_id_matrix_2[5][5] = {
        { 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0 },
    };

    int non_id_matrix_rect[4][5] = {
        { 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 1 },
    };

    int (*matrices[])[5] = { id_matrix, id_matrix_rect, non_id_matrix_1, non_id_matrix_2, non_id_matrix_rect };
    bool is_rect[]       = { false,     true,           false,           false,           true };
    bool is_id[]         = { true,      true,           false,           false,           false };

    const int nr_of_matrices = sizeof(matrices)/sizeof(matrices[0]);

    for (int i = 0; i < nr_of_matrices; i++)
    {
        test_id_matrix(matrices[i], is_rect[i], is_id[i]);
    }

    return 0;
}

void test_id_matrix(const int (*matrix)[5], bool is_rect, bool expected)
{
    const int rows = (is_rect) ? 4 : 5;

    if (is_identity_matrix(rows, 5, matrix) == expected)
    {
        printf("Pass.\n");
    }
    else
    {
        printf("FAIL.\n");
    }
}

void display_matrix(int rows, int cols, const int matrix[rows][cols])
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%10d", matrix[i][j]);
        }

        putchar('\n');
    }
}
