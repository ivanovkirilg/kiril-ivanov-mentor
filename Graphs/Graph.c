#include "Graph.h"

#include <stdio.h>

#define DIGRAPH "digraph"
#define GRAPH "graph"

inline static int at(const struct Graph *graph, size_t row, size_t col)
{
    return graph->adjMat[row * graph->nrOfVertices + col];
}

void generateDotFromAdjMatrix(const struct Graph *graph,
                              FILE *outFile)
{
    fprintf(outFile, "%s {\n", graph->directed ? DIGRAPH : GRAPH );

    for (size_t i = 0; i < graph->nrOfVertices; i++)
    {
        // Only care about half the matrix for an undirected graph [1]
        const size_t startIdx = graph->directed ? 0 : i;

        for (size_t j = startIdx; j < graph->nrOfVertices; j++)
        {
            if (at(graph, i, j))
            {
                fprintf(outFile, "  %s %s %s\n",
                                 graph->vertices[i],
                                 graph->directed ? "->" : "--",
                                 graph->vertices[j]);
            }
        }
    }

    fprintf(outFile, "}\n");
}

/*
[1]
Meaningful part of matrix for:
 - directed graph
   0 0 1  v v v
   1 0 0  v v v   (Can be asymmetrical across diagonal)
   1 1 1  v v v

 - UNdirected graph
   0 1 1  v v v
   1 0 1  x v v   (Must be symmetrical across diagonal)
   1 1 0  x x v
*/