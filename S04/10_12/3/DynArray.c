#include "DynArray.h"

#include <stdio.h>
#include <stdlib.h>

Error DynArr_resize(struct DynArray *self, size_t newSize)
{
    Error err = NO_ERROR;
    CHECK_NULL_PARAM(self, err);

    if (!err)
    {
        self->data = realloc(self->data, newSize * sizeof(elem_t));

        if (self->data == NULL)
        {
            fprintf(stderr, "%s: allocation failed.\n", __func__);
            self->size = 0;
            err = ALLOCATION_ERROR;
        }
        else
        {
            self->size = newSize;
        }
    }

    return err;
}
