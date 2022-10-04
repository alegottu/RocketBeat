#include "Rigidbody.hpp"
#include "Entity.hpp"

Rigidbody::Rigidbody(Entity* host, float gravityScale)
    : Component(host), velocity(Vector2()), gravityScale(gravityScale)
{
}