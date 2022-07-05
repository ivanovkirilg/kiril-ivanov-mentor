#include "Graph.h"

int main()
{
    char *vertices[] = {
        "Alpha", "Bravo", "Charlie", "Delta"
    };

    int undirMatrix[] = {
        // A  B  C  D
           0, 1, 1, 0, // A
           1, 0, 0, 1, // B
           1, 0, 0, 0, // C
           0, 1, 0, 0  // D
    };
    int dirMatrix[] = {
        // A  B  C  D
           0, 1, 0, 0, // A
           1, 0, 1, 1, // B
           0, 0, 1, 0, // C
           1, 1, 0, 0  // D
    };

    struct Graph undirGraph = {
        .nrOfVertices = 4,
        .directed = false,
        .vertices = vertices,
        .adjMat = undirMatrix
    };
    struct Graph dirGraph = {
        .nrOfVertices = 4,
        .directed = true,
        .vertices = vertices,
        .adjMat = dirMatrix
    };

    FILE *undirFile = fopen("./out/undirected.gv", "w");
    FILE *dirFile = fopen("./out/directed.gv", "w");

    generateDotFromAdjMatrix(&undirGraph, undirFile);

    generateDotFromAdjMatrix(&dirGraph, dirFile);

    fclose(undirFile);
    fclose(dirFile);

    return 0;
}
