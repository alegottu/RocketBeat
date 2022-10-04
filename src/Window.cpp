#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Window.hpp"
#include "Entity.hpp"

Window::Window(const char* p_title, int p_w, int p_h)
    : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Window couldn't be created. Error: " << SDL_GetError() << std::endl;
    }
    // SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    // SDL_RENDERER_ACCELERATED means the GPU is utilized if one is available.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Renderer couldn't be created. Error: " << SDL_GetError() << std::endl;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture* Window::loadTexture(const char* path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL)
    {
        std::cout << "Texture couldn't be loaded. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Window::clear()
{
    SDL_RenderClear(renderer);
}

void Window::render(Entity** entities, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        Entity* current = entities[i];
        SDL_RenderCopy(renderer, current->texture, NULL, current->getSpace());
    }
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

int Window::findRefresh()
{
    SDL_DisplayMode mode;   
    SDL_GetDisplayMode(SDL_GetWindowDisplayIndex(window), 0, &mode);
    return mode.refresh_rate;
}