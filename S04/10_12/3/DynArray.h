#ifndef KIRIL_IVANOV_MENTOR_S04_10_12_DYN_ARRAY
#define KIRIL_IVANOV_MENTOR_S04_10_12_DYN_ARRAY

#include <stddef.h>

#include "ErrorCodes.h"

typedef int elem_t;

struct DynArray
{
    size_t size;
    elem_t *data;
};

Error resize(struct DynArray *self, size_t newSize);

#endif // KIRIL_IVANOV_MENTOR_S04_10_12_DYN_ARRAY
