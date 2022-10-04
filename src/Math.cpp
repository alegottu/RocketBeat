#include <iostream>
#include <SDL2/SDL.h>
#include "Math.hpp"

Vector2::Vector2()
    : x(0), y(0)
{
}

Vector2::Vector2(int x, int y)
    : x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator+(const SDL_Rect& other) const
{
    return Vector2(x + other.x, y + other.y);
}

void Vector2::print() const
{
    std::cout << x << ", " << y << std::endl;
}