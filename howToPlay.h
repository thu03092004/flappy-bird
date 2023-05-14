#pragma once

#include "Object.h"

class howToPlay : public Object
{
private:
    SDL_Texture* Tex1;
    int animationTimer;

public:
    void CreateTexture1(const char *address, SDL_Renderer *ren);
    void Render(SDL_Renderer *ren);
};
