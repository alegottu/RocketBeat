#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

const int MAX_ENTITIES = 16;

// Renderable entity
struct Entity
{
    public:
        Entity(Vector2 pos, Vector2 size, SDL_Texture* texture=NULL);
        Entity(Vector2 size, SDL_Texture* texture=NULL);

        void move(int x, int y);
        void moveTo(int x, int y);
        void moveToX(int x);
        void moveToY(int y);
        const SDL_Rect* getSpace() const;

        SDL_Texture* const texture;

    private:
        SDL_Rect space;
};
// Make a static version of an array for this struct, this makes the common case fast, but otherwise consider having a dirty flag per each

// TODO::Make sure entities cannot cross the boundaries of the screen

#endif