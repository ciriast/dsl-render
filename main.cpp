#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = nullptr;

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **app_state, int argc, char *argv[]) {
    SDL_SetAppMetadata("Example Renderer clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (window = SDL_CreateWindow("examples/renderer/clear", 640, 480, SDL_WINDOW_RESIZABLE); window == nullptr) {
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse, input, keypress, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *app_state, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *app_state) {
    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown */
void SDL_AppQuit(void *app_state, SDL_AppResult result) {
    /* SDL will clean up the window for us. */
}
