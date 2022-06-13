#include <stdlib.h>

struct Entity
{
    int id;
    char name[64];
};

struct Scene
{
    int timeOfDay;
    size_t nrOfEntities;
    struct Entity **entities;
};

struct Entity *createEntityPtr()
{
    struct Entity *newEntity = malloc(sizeof(struct Entity));
    /* init */
    return newEntity;
}

// deinitScene() must be called after a successful loadScene() to free memory
struct Scene loadScene()
{
    struct Scene scene = { .nrOfEntities = 15 };

    scene.entities = malloc(scene.nrOfEntities * sizeof(struct Entity *));

    for (size_t i = 0; i < scene.nrOfEntities; i++)
    {
        scene.entities[i] = createEntityPtr();
    }

    return scene;
}

void deinitScene(struct Scene *scene)
{
    for (size_t i = 0; i < scene->nrOfEntities; i++)
    {
        free(scene->entities[i]);
    }

    free(scene->entities);
}

int main()
{
    struct Scene currentScene = loadScene();

    /* do stuff */

    deinitScene(&currentScene);
}
