#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Window
{
    public:
        Window(const char* title, int width, int height);
        ~Window();
        
        SDL_Texture* loadTexture(const char* path);
        void clear();
        void render(Entity** entities, int amount);
        void display();
        int findRefresh();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif