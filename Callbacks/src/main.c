#include "Dispatcher.h"
#include "Producer.h"
#include "Processor.h"

#include <stddef.h>
#include <stdio.h>

int main()
{
    const size_t SIZE = 1024;
    struct Dispatcher dispatcher = {0};

    initDispatcher(&dispatcher, SIZE);

    initLogger(&dispatcher);

    subscribe(&dispatcher, (struct Subscription) {filterPunctuation, NULL, NULL});

    while (produceData(dispatcher.dataSize, dispatcher.data))
    {
        dispatchData(&dispatcher);
    }

    deinitDispatcher(&dispatcher);
}
