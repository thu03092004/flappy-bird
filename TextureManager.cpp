#include "TextureManager.h"

SDL_Texture* TextureManager::Texture(const char* filelocation, SDL_Renderer* ren)
{
    SDL_Surface* surface = IMG_Load(filelocation);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    
    return tex;
}