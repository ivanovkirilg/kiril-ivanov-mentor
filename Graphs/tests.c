#include "DotGenerator.h"

int main()
{
    char *vertices[] = {
        "Alpha", "Bravo", "Charlie", "Delta"
    };

    int undirA[] = { 0, 1, 1, 0 };
    int undirB[] = { 1, 0, 0, 1 };
    int undirC[] = { 1, 0, 0, 0 };
    int undirD[] = { 0, 1, 0, 0 };
    int *undirMatrix[] = {
        undirA, undirB, undirC, undirD
    };

    int dirA[] = { 0, 1, 0, 0 };
    int dirB[] = { 0, 0, 1, 1 };
    int dirC[] = { 0, 0, 1, 1 };
    int dirD[] = { 1, 0, 0, 0 };
    int *dirMatrix[] = {
        dirA, dirB, dirC, dirD
    };

    FILE *undirFile = fopen("./out/undirected.gv", "w");
    FILE *dirFile = fopen("./out/directed.gv", "w");

    generateDotFromAdjacencyMatrix(4, false, vertices, undirMatrix, undirFile);

    generateDotFromAdjacencyMatrix(4, true, vertices, dirMatrix, dirFile);

    fclose(undirFile);
    fclose(dirFile);

    return 0;
}
