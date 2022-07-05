#ifndef KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H
#define KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H

#include <stdbool.h>
#include <stdio.h>

struct Graph
{
    size_t nrOfVertices;
    char **vertices;
    int   *adjMat;
    bool   directed;
};

void generateDotFromAdjMatrix(const struct Graph *adjMatrix,
                              FILE *outFile);

#endif // KIRIL_IVANOV_MENTOR_GRAPHS_GRAPH_H