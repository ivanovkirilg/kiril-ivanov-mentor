#include "Producer.h"

#include <stdbool.h>
#include <stdio.h>

bool produceData(const size_t size, char outData[])
{
    return NULL != fgets(outData, size, stdin);
}
