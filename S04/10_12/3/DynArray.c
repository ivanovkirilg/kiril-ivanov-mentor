#include "DynArray.h"

#include <stdio.h>
#include <stdlib.h>

Error resize(struct DynArray *self, size_t newSize)
{
    self->data = realloc(self->data, newSize * sizeof(elem_t));

    if (self->data == NULL)
    {
        fprintf(stderr, "%s: allocation failed.\n", __func__);
        self->size = 0;
        return ALLOCATION_ERROR;
    }

    self->size = newSize;
    return NO_ERROR;
}
