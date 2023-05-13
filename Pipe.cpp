#include "Pipe.h"
#include <ctime>
#include <iostream>
 
Pipe::Pipe()
{
	pipeWidth = 80;
	space = 150;
	xPos[0] = xPos[1] = -480;
}
 
Pipe::Pipe(int xPipe)
{
	srand(time(NULL));
	xPos[xPipe] = xPipe * 280 + 480;
}

void Pipe::reset(int i)
{
    xPos[0] = xPos[1] = -480;
    setDest(xPos[i], 560 - p1h[i], pipeWidth, p1h[i]);
    return;
}
int Pipe::pipeRandHeight()
{
	return rand() * rand() % (330 - 100 + 1) + 100;
}
 
void Pipe::PipeUpdate1(int i, bool birdDie)
{
    if(i == 1){
        if (xPos[i] <= -pipeWidth)
        {
            p1h[i] = Pipe::pipeRandHeight();
            xPos[i] = 480;
        }
        else
        {
            if(!birdDie)
            xPos[i]--;
            setSrc(0, 0, 54, 250);
            setDest(xPos[i], 560 - p1h[i], pipeWidth, p1h[i]);
        }
    }
    else{
        if(xPos[1] == (480-pipeWidth)/2  ){
            p1h[i] = Pipe::pipeRandHeight();
            xPos[i] = 480;
        }
        else{
            if(!birdDie)
            xPos[i]--;
            setSrc(0, 0, 54, 250);
            setDest(xPos[i], 560 - p1h[i], pipeWidth, p1h[i]);
        }
    }
    return ;
}
 
void Pipe::PipeUpdate2(int i)
{
	p2h[i] = 560 - p1h[i] - space;
	setSrc(0, 0, 54, 250);
	setDest(xPos[i], 0, pipeWidth, p2h[i]);
}
 
int Pipe::getp1h(int i)
{
	return p1h[i];
}
 
int Pipe::getxPos(int i)
{
	return xPos[i];
}
 
void Pipe::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}