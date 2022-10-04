#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"
#include "Math.hpp"
#include "Window.hpp"

Entity::Entity(Vector2 pos, Vector2 size, SDL_Texture* texture)
    : texture(texture)
{
    space = SDL_Rect{pos.x, pos.y, size.x, size.y};
}

Entity::Entity(Vector2 size, SDL_Texture* texture)
    : texture(texture)
{
    // scale position along with size, if a multiplier exists
    space = SDL_Rect{0, 0, size.x, size.y};
}

void Entity::move(int x, int y)
{
    space.x += x;
    space.y += y;
}

void Entity::moveTo(int x, int y)
{
    space.x = x;
    space.y = y;
}

// Test if multiple move functions is better than simply fetching the space in junction with moveTo
void Entity::moveToX(int x)
{
    space.x = x;
}

void Entity::moveToY(int y)
{
    space.y = y;
}

const SDL_Rect* Entity::getSpace() const
{
    return &space;
}