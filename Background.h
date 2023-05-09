#pragma once

#include "Object.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 626;

class Background : public Object
{
private:
    int distance1 = 0;
    int distance2 = SCREEN_WIDTH;
public:
    void GroundUpdate1(bool birdDie);
    void GroundUpdate2(bool birdDie);
    void Render(SDL_Renderer* ren);
    void GroundRender(SDL_Renderer* ren);
};