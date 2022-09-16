#include <stdlib.h>

struct Entity
{
    int id;
    char name[64];
};

struct Entity createEntity()
{
    struct Entity newEntity = {0};
    /* init */
    return newEntity;
}

void initEntityPtr(struct Entity *newEntity)
{
    /* init */
}

struct Entity *createEntityPtr()
{
    struct Entity *newEntity = malloc(sizeof(struct Entity));
    /* init */
    return newEntity;
}

int main()
{
    struct Entity ent = createEntity();
    struct Entity ent1 = {0};
    initEntityPtr(&ent1);

    struct Entity *entPtr = createEntityPtr();
    free(entPtr);
}
