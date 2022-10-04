#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <algorithm>
#include "Window.hpp"
#include "Entity.hpp"
#include "Rigidbody.hpp"
#include "Physics.hpp"
#include "Collider.hpp"

inline float timeSinceStart()
{
    return SDL_GetTicks() * 0.001f;
}

// If you make the physics functions within main, you can simply make the index for each 
// component match each other and use them at any point.
int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    // This project only uses PNG format for images
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    // SDL setup
    Window window("RocketBeat v0.1", WINDOW_WIDTH, WINDOW_HEIGHT);
    bool running = true;
    SDL_Event event;
    
    // Entity initialization
    Entity* entities[MAX_ENTITIES];
    int entityCount = 1;
    Rigidbody* rigidbodies[MAX_ENTITIES];
    int rigidbodyCount = 1;
    Collider* colliders[MAX_ENTITIES];
    int colliderCount = 2;

    Vector2 pyroSize = Vector2(231, 177);
    entities[0] = new Entity(pyroSize, window.loadTexture("res/gfx/pyro.png"));
    rigidbodies[0] = new Rigidbody(entities[0]);
    colliders[0] = new Collider(entities[0], pyroSize, Vector2());
    colliders[1] = new Collider(Vector2(0, WINDOW_HEIGHT), Vector2(WINDOW_WIDTH 1));

    // Timestep setup
    float accumulator = 0;
    float currentTime = timeSinceStart();

    while (running)
    {
        int startTicks = SDL_GetTicks();

        float newTime = timeSinceStart();
        float frameDuration = std::min(newTime - currentTime, 0.25f);
        currentTime = newTime;
        accumulator += frameDuration;

        while (accumulator >= Physics::deltaTime)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
            }

            accumulator -= Physics::deltaTime;

            Physics::fall(rigidbodies, rigidbodyCount);
            Physics::handleCollision(colliders, colliderCount);
        }

        const float alpha = accumulator / Physics::deltaTime;
        // TODO::Setup linear interpolation guess through position

        window.clear();
        window.render(entities, entityCount);
        window.display();

        // V-sync setup
        int frameTicks = SDL_GetTicks() - startTicks;
        int minTicks = 1000 / window.findRefresh();

        if (frameTicks < minTicks)
        {
            SDL_Delay(minTicks - frameTicks);
        }
    }

    delete colliders[0];
    delete colliders[1];
    delete rigidbodies[0];
    delete entities[0];

    return 0;
}