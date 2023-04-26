#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Event event;
    int quit = 0;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Carré blanc",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              2,
                              2,
                              SDL_WINDOW_SHOWN);

    surface = SDL_GetWindowSurface(window);

    // Dessiner un carré blanc de 2x2 pixels
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

    SDL_UpdateWindowSurface(window);

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}