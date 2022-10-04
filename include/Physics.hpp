#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Rigidbody.hpp"
#include "Collider.hpp"

namespace Physics
{
    void handleCollision(Collider** colliders, int amount);
    void fall(Rigidbody** bodies, int amount);

    const float deltaTime = 0.01f;
}

#endif