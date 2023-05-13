#pragma once
#include "Object.h"

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
    void handleEvent(SDL_Event event, bool &gameState);
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    // MenuOption handleMenuClick(SDL_Event event);
    void Render(SDL_Renderer *ren);
};