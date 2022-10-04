#ifndef MATH_HPP
#define MATH_HPP

#include <SDL2/SDL.h>

struct Vector2
{
    public:
        Vector2();
        Vector2(int x, int y);

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator+(const SDL_Rect& other) const;
        void print() const;

        int x, y;
};

#endif