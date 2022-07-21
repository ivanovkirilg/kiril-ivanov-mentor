#include <Dispatcher.h>

#include <stdio.h>
#include <stdlib.h>

void initDispatcher(struct Dispatcher *self, const size_t size)
{
    *self = (struct Dispatcher) {0};

    self->dataSize = size;

    self->data = malloc(size);
}

void dispatchData(struct Dispatcher *self)
{
    for (size_t i = 0; i < self->nrOfSubscriptions; i++)
    {
        self->subscriptions[i].onNewData(
            self->dataSize, self->data, self->subscriptions[i].userData);
    }
}

void subscribe(struct Dispatcher *self, struct Subscription newSubscription)
{
    if (self->nrOfSubscriptions < MAX_SUBSCRIPTIONS)
    {
        self->subscriptions[self->nrOfSubscriptions] = newSubscription;
        self->nrOfSubscriptions++;
    }

    fprintf(stderr, "ERROR: Exceeding max subscriptions %lu!\n", MAX_SUBSCRIPTIONS);
}

void deinitDispatcher(struct Dispatcher *self)
{
    for (size_t i = 0; i < self->nrOfSubscriptions; i++)
    {
        if (self->subscriptions[i].onEndOfData)
        {
            self->subscriptions[i].onEndOfData(
                self->dataSize, self->data, self->subscriptions[i].userData);
        }
    }

    free(self->data);
    self->dataSize = 0;
    self->nrOfSubscriptions = 0;
}
