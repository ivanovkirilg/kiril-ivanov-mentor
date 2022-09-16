#ifndef KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H
#define KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H

#include <stdbool.h>
#include <stdio.h>

void generateDotFromAdjacencyMatrix(
    size_t numberOfVertices,
    bool isDirected,
    char **vertexNames,
    int **adjacencyMatrix,
    FILE *outFile);

#endif // KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H