#ifndef KIRIL_IVANOV_MENTOR_CALLBACKS_PROCESSOR_H
#define KIRIL_IVANOV_MENTOR_CALLBACKS_PROCESSOR_H

#include <stddef.h>

#include "Dispatcher.h"

void initLogger(struct Dispatcher *dispatcher);

void logData(const size_t size, char data[], void *fileProxy);

void filterPunctuation(const size_t size, char data[], void *unused);


#endif // KIRIL_IVANOV_MENTOR_CALLBACKS_PROCESSOR_H