#include "Processor.h"

#include <stdio.h>
#include <ctype.h>

#define LOG_FILE "log.txt"

///////////////////  LOGGER  ///////////////////

void deinitLogger(const size_t size, char data[], void *fileProxy);

void initLogger(struct Dispatcher *dispatcher)
{
    FILE *logFile = fopen(LOG_FILE, "w");

    subscribe(dispatcher, (struct Subscription) {logData, deinitLogger, logFile});
}

void deinitLogger(const size_t size, char data[], void *fileProxy)
{
    (void) size, (void) data; // Unused

    FILE *file = fileProxy;
    fclose(file);
}

void logData(const size_t size, char data[], void *fileProxy)
{
    (void) size; // Unused

    FILE *file = fileProxy;

    fprintf(file, "LOGGING: %s", data);
}

///////////////////  FILTER  ///////////////////

void filterPunctuation(const size_t size, char data[], void *userData)
{
    (void) userData; // Unused

    for (size_t i = 0; i < size && data[i] != '\0'; i++)
    {
        if (!ispunct(data[i]))
        {
            putchar(data[i]);
        }
    }
}
