#include <SDL2/SDL.h>
#include "Rigidbody.hpp"
#include "Collider.hpp"
#include "Physics.hpp"
#include "Math.hpp"

void Physics::handleCollision(Collider** colliders, int amount)
{
    for (int i=0; i < amount - 1; ++i)
    {
        for (int j=i; j < amount - 1; ++j)
        {
            Collider* current = colliders[j];
            Collider* test = colliders[j+1]; 

            const Vector2 currentMin = current->pos + *current->host->getSpace();
            const Vector2 currentMax = currentMin + current->size;
            const Vector2 testMin = test->pos + *current->host->getSpace();
            const Vector2 testMax = testMin + test->size;

            // Because no pair should be tested twice, you can safely move the current entity
            // if needed, as the non-static entities come earliest in the array
            if (currentMax.x <= testMin.x && currentMin.x >= testMax.x)
            {
                continue;
            }

            if (currentMax.y <= testMin.y && currentMin.y >= testMax.y)
            {   
                continue;
            }

            // Stop the velocity of the corresponding rigidbody, (use a Component table)
            // ideally by excluding this rigidbody from falling until another force acts upon it
            // otherwise the common case is still fast by making the velocity 0
            // and therefore the calculations simpler for fall()
        }
    }
}

void Physics::fall(Rigidbody** bodies, int amount)
{
    for (int i=0; i < amount; ++i)
    {   
        Rigidbody* current = bodies[i];
        current->gravity += current->gravityScale * deltaTime; // Y axis is inverted
        current->velocity.y = current->gravity; // More to be added once there are other forces
        current->host->move(0, current->velocity.y);
    }
}