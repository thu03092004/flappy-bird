#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::GroundRender(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::GroundUpdate1(bool birdDie)
{
    if(distance1 <= -SCREEN_WIDTH)
    {
        distance1 = SCREEN_WIDTH;
    }
    else
    {
        if(!birdDie)
        distance1--;
        setSrc(0, 0, 600, 200);
        setDest(distance1, 560, 482, 66);
    }
}

void Background::GroundUpdate2(bool birdDie)
{
    if(distance2 <= -SCREEN_WIDTH)
    {
        distance2 = SCREEN_WIDTH;
    }
    else
    {
        if(!birdDie)
        distance2--;
        setSrc(0, 0, 600, 200);
        setDest(distance2, 560, 482, 66);
    }
}