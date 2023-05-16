#pragma once

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Background.h"
#include "Player.h"
#include "Pipe.h"
#include "Menu.h"
#include "TextObject.h"
#include "howToPlay.h"

class GameLoop
{
private:
    Menu menu;
    Player p; // bird
    Background b; // background
    Background g1, g2; // đất
    Pipe p1_[2], p2_[2]; // cột
    TextObject t;
    TextObject tBest;
    howToPlay hoicham;


    const int SCREEN_WIDTH = 480;
    const int SCREEN_HEIGHT = 626;

    bool GameState;
    
    bool birdDie = false;

    SDL_Window* window;
    SDL_Event event;
    SDL_Renderer* renderer;

    //music
    Mix_Music* backgroundSound;
    Mix_Chunk* wingSound;
    Mix_Chunk* scoreSound;
    Mix_Chunk* dieSound;
    Mix_Chunk* clickSound;

    //score
    int fontSize = 60;
    int bestScore;
    int score = 0;
    TTF_Font* scoreFont;
    TTF_Font* yourScoreFont;

    //color 
    SDL_Color white = {250, 250, 250, 250};
    SDL_Color black = {0, 0, 0, 250};

public:
    GameLoop();
    ~GameLoop();
    void Initialize();
    bool getGameState();
    void NewGame();
    void Event();
    void Update();
    // xử lý va chạm
    bool checkCollision(const SDL_Rect &a,const SDL_Rect &b );
    void CollisionDetection();
    // xử lý điểm số
    bool checkScore(const SDL_Rect &a,const SDL_Rect &b );
    void Score();
    void Render();
    void Close();
};