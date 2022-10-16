#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stddef.h>
#include <stdbool.h>

#include "ErrorHandler.h"

typedef int elem_t;

struct DynArray
{
    size_t size;
    elem_t *data;
};

/// \brief Reallocates the storage to fit `newSize' elements
/// \note TODO: Zero-initializes any newly added elements
Error DynArr_resize(struct DynArray *self, size_t newSize);

/// \brief TODO: Tells if the array currently contains any elements
bool DynArr_isEmpty(const struct DynArray *self);

/// \brief TODO: Extends the array with a copy of `newElement' at the end
Error DynArr_append(struct DynArray *self, elem_t newElement);

/// \brief TODO: Adds a copy of `newElement' at the provided `index'
Error DynArr_insert(struct DynArray *self, elem_t newElement, size_t index);

/// \brief TODO: Removes the element currently at the provided `index'
/// \note Shifts all following elements left
Error DynArr_remove(struct DynArray *self, size_t index);

/// \brief TODO: Clears the contents of the array
/// \note The array remains valid, although empty
void DynArr_clear(struct DynArray *self);

#endif // DYNAMIC_ARRAY
