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
#include "TextObject.h"

class GameLoop
{
private:
    Player p; // bird
    Background b; // background
    Background g1, g2; // đất
    Pipe p1_[2], p2_[2]; // cột
    TextObject t;

    const int SCREEN_WIDTH = 480;
    const int SCREEN_HEIGHT = 626;

    bool GameState;
    
    bool birdDie = false;
    bool checkDie = true;
    bool playing = false;
    bool newGame = false;

    SDL_Window* window;
    SDL_Event event;
    SDL_Renderer* renderer;

    //music
    Mix_Music* backgroundSound;
    Mix_Chunk* wingSound;
    Mix_Chunk* winSound;
    Mix_Chunk* dieSound;

    //score
    int fontSize = 50;
    int bestScore;
    int score = 0;
    TTF_Font* scoreFont;

    //menu
    SDL_Rect start = { 167, 360, 213, 86 };
    SDL_Rect quit1 = { 167, 481, 213, 86 };
    SDL_Rect playAgain = { 56, 507, 197, 78};
    SDL_Rect quit2 = { 297, 507, 197, 78};

    SDL_Color white = {250,  250, 250, 250};

public:
    GameLoop();
    ~GameLoop();
    void Initialize();
    bool getGameState();
    void NewGame();
    void Event();
    void Update();
    bool checkCollision(const SDL_Rect &a,const SDL_Rect &b );
    void CollisionDetection();
    bool checkScore(const SDL_Rect &a,const SDL_Rect &b );
    void Score();
    void Die();
    void Render();
    void Close();

    void set_color(int code);
};