#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "Component.hpp"
#include "Math.hpp"
#include "Entity.hpp"

struct Collider : Component
{
    public:
        Collider(Entity* host, Vector2 pos, Vector2 size);
        Collider(Vector2 pos, Vector2 size);
        
        const Vector2 pos; // Position is relative to the host
        const Vector2 size;
};

#endif