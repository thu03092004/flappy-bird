#include "GameLoop.h"

GameLoop* g = new GameLoop();

int main(int argc, char* argv[])
{
    const int FPS = 100; // frames per second - số lần khung hình hiển thị trong 1 giây
    const int frameDelay = 1000 / FPS; // khoảng thời gian giữa 2 khung hình liên tiếp

    uint32_t frameStart; // giữ lại thời điểm bắt đầu của 1 khung hình mới
    int frameTime; // giữ thời gian đã trôi qua cho 1 khung hình

    g->Initialize();
    while(g->getGameState())
    {
        frameStart = SDL_GetTicks();

        g->Event();
        g->Update();
        g->Render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    g->Close();
    return 0;
}