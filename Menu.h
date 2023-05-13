#pragma once
#include "Object.h"
#include <SDL_mixer.h>

class Menu : public Object
{
private:
    bool on_menu_state;
    bool on_end_state;
    SDL_Texture* end_state;
    // enum MenuOption { PLAY_AGAIN , QUIT };


public:
    Menu();
    bool is_on_menu_state();
    bool is_on_end_state();
    void update(bool &birdDie);
    void handleEvent(SDL_Event event, bool &gameState, Mix_Chunk* clickSound);
    void handle_end_menu_state_event(SDL_Event event, bool &gameState, Mix_Chunk* clickSound);
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void Start();
    // MenuOption handleMenuClick(SDL_Event event);
    void Render(SDL_Renderer *ren);
};