#include "DotGenerator.h"

#include <stdio.h>

#define DIGRAPH "digraph"
#define GRAPH "graph"

// Each graph parameter is passed separately so that this is agnostic
// toward your graph implementation, but you are encouraged to use a structure.
void generateDotFromAdjacencyMatrix(
    size_t numberOfVertices,
    bool   isDirected,
    char   **vertexNames,
    int    **adjacencyMatrix,
    FILE   *outFile)
{
    const char *graphIdentifier = isDirected ? "digraph" : "graph";
    const char *connector       = isDirected ? "->"      : "--";

    fprintf(outFile, "%s {\n", graphIdentifier);

    for (size_t i = 0; i < numberOfVertices; i++)
    {
        // An undirected graph has a symmetrical matrix [1]
        const size_t startIdx = isDirected ? 0 : i;

        for (size_t j = startIdx; j < numberOfVertices; j++)
        {
            if (adjacencyMatrix[i][j])
            {
                fprintf(outFile, "  %s %s %s\n",
                                 vertexNames[i],
                                 connector,
                                 vertexNames[j]);
            }
        }
    }

    fprintf(outFile, "}\n");
}

/*
[1]
Meaningful part of matrix for (unweighted):
 - directed graph
   0 0 1   l v v
   1 0 0   v l v   (Can be asymmetrical across diagonal)
   1 1 1   v v l

 - UNdirected graph
   0 1 1   l v v
   1 0 1   x l v   (Must be symmetrical across diagonal)
   1 1 0   x x l

   * v - meaningful, x - can be ignored, l - self-loop
*/