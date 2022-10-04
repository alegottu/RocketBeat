#include "Entity.hpp"
#include "Math.hpp"
#include "Collider.hpp"

Collider::Collider(Entity* host, Vector2 pos, Vector2 size)
    : Component(host), pos(pos), size(size)
{
}

Collider::Collider(Vector2 pos, Vector2 size)
    : Component(NULL), pos(pos), size(size)
{
}