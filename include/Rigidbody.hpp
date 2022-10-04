#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Component.hpp"
#include "Entity.hpp"

// TODO::Figure out a way of mapping components to elements of the Entity array using a table
struct Rigidbody : Component
{
    public:
        Rigidbody(Entity* host, float gravityScale=9.81f); // Controls the size of the hitbox

        Vector2 velocity;
        const float gravityScale;
        float gravity; // Gravity force accumulated, only to be changed by main.cpp or where the physics functions are placed otherwise
};

#endif