#include <glad/glad.h>
#include <SDL2/SDL.h>
#include "../util.h"
#include "../global.h"
#include "render.h"
#include "render_internal.h"

SDL_Window *render_init_window(u32 width, u32 height){
        // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ERROR_EXIT("Could not init SDL: %s\n", SDL_GetError());
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
        ERROR_EXIT("Failed to initialize window: %s", SDL_GetError());
    }

    // Load OpenGL
    SDL_GL_CreateContext(window);
    if(!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        ERROR_EXIT("Failed to load GL: %s", SDL_GetError());
        exit(1);
    }

    return window;
}

void render_init_quad(u32 *vao, u32 *vbo, u32 *ebo)
{
    // XYZ UV
    f32 vertices[] = {
        0.5, 0.5, 0, 0, 0,
        0.5, -0.5, 0, 0, 1,
        -0.5, -0.5, 0, 1, 1,
        -0.5, 0.5, 0, 1, 0
    };

    u32 indicies[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(*vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

    // XYZ
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), NULL);
    glEnableVertexAttribArray(0);

    // UV
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(3*sizeof(f32)));
    glad_glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}