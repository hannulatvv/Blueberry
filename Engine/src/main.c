#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    };
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    // Create SDL window
    SDL_Window *window = SDL_CreateWindow(
        "Blueberry",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_OPENGL
        );

    // Check if window was created succesfully
    if(!window)
    {
        printf("Failed to initialize window: %s", SDL_GetError());
        exit(1);
    }

    // Load OpenGL
    SDL_GL_CreateContext(window);
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("Failed to load GL: %s", SDL_GetError());
        exit(1);
    }

    // Main Loop
    bool ShouldQuit = false;
    while(!ShouldQuit)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                ShouldQuit = true;
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}