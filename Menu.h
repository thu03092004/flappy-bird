#pragma once
#include "Object.h"

class Menu : public Object
{
private:
    bool on_menu_state;
    bool on_end_state;
    SDL_Texture* end_state;

public:
    Menu();
    bool is_on_menu_state();
    bool is_on_end_state();
    void update(bool &birdDie);
    void handleEvent1(SDL_Event event, bool &gameState);
    void handleEvent2(SDL_Event event, bool &gameState, bool &birdDie, bool &newGame);
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void Render(SDL_Renderer *ren);
};