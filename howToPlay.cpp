#include "howToPlay.h"

void howToPlay::CreateTexture1(const char *address, SDL_Renderer *ren)
{
    Tex1 = TextureManager::Texture(address, ren);
}

void howToPlay::Render(SDL_Renderer *ren)
{
    animationTimer++;
    if(animationTimer < 32)
    {
        SDL_RenderCopyEx(ren, getTexture(), NULL, NULL, 0, NULL, SDL_FLIP_NONE);
    }
    else if (animationTimer >= 32 && animationTimer <= 64)
    {
        SDL_RenderCopyEx(ren, Tex1, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
    }

    if(animationTimer >= 64)
    {
        animationTimer = 0;
    }
}