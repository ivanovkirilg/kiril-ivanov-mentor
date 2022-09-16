#ifndef KIRIL_IVANOV_MENTOR_CALLBACKS_DISPATCHER_H
#define KIRIL_IVANOV_MENTOR_CALLBACKS_DISPATCHER_H

#include <stddef.h>

#define MAX_SUBSCRIPTIONS 15UL

typedef void (*Callback)(const size_t size, char data[size], void *userData);

struct Subscription
{
    Callback onNewData;
    Callback onEndOfData;
    void *userData;
};

struct Dispatcher
{
    struct Subscription subscriptions[MAX_SUBSCRIPTIONS];
    size_t nrOfSubscriptions;
    size_t dataSize;
    char *data;
};

void initDispatcher(struct Dispatcher *self, const size_t size);

void subscribe(struct Dispatcher *self, struct Subscription newSubscription);

void dispatchData(struct Dispatcher *self);

void deinitDispatcher(struct Dispatcher *self);

#endif // KIRIL_IVANOV_MENTOR_CALLBACKS_DISPATCHER_H