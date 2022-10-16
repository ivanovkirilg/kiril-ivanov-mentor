#ifndef ERROR_HANDLER
#define ERROR_HANDLER

typedef enum Error
{
    NO_ERROR = 0,
    ALLOCATION_ERROR,
    PARAMETER_ERROR,
    SYSTEM_ERROR,
    INPUT_ERROR,
    // ...
} Error;

#define CHECK_NULL_PARAM(param, errorVar)                             \
    if ((param) == NULL) {                                            \
        fprintf(stderr, "%s: received %s=NULL.\n", __func__, #param); \
        (errorVar) = PARAMETER_ERROR;                                 \
    }

#endif // ERROR_HANDLER
