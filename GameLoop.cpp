#include "GameLoop.h"

using namespace std;

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;

    //bird
    p.setSrc(0, 0, 68, 48);

}

GameLoop::~GameLoop()
{

}

void GameLoop::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", 
                            SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED, 
                            SCREEN_WIDTH, SCREEN_HEIGHT, 
                            SDL_WINDOW_SHOWN);
    if(window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            std::cout << "Succeeded!" << std::endl;
            GameState = true;
         
            //bird
            p.CreateTexture("image/bird/1-1.png", renderer);
            p.CreateTexture1("image/bird/1-2.png", renderer);
            p.CreateTexture2("image/bird/1-3.png", renderer);

            //background
            b.CreateTexture("image/background/day.png", renderer);

            //nền
            g1.CreateTexture("image/background/ground.png", renderer);
            g2.CreateTexture("image/background/ground.png", renderer);

            //pipe
            for(int i = 0; i < 2; i++)
            {
                p1_[i].CreateTexture("image/pipe/pipedown.png", renderer);
                p2_[i].CreateTexture("image/pipe/pipeup.png", renderer);
            }
        }
        else
        {
            std::cerr << "Not created!" << std::endl;
        }
    }
    else
    {
        std::cerr << "Window not created!" << std::endl;
    }


    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Close();
	}
    if(Mix_Init(1) == 0)
    {
        std::cerr << "Sound could not initialize! Mix_Error: " << Mix_GetError() << std::endl;
		Close();
    }
    else
    {
        backgroundSound = Mix_LoadMUS("sound/background.mp3");
        wingSound = Mix_LoadWAV("sound/wing.wav");
        winSound = Mix_LoadWAV("sound/win.wav");
        dieSound = Mix_LoadWAV("sound/die.wav");
    }
    Mix_VolumeMusic(30);
    Mix_PlayMusic(backgroundSound, -1);



    if(TTF_Init() < 0)
    {
        std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        Close();
    }
    else
    {
        scoreFont = TTF_OpenFont("font/font.ttf", fontSize);
    }

    std::ifstream file("bestScore.txt");
    if(!file.is_open())
    {
        cout << "Unable to open bestScore.txt !" << endl;
        Close();
    }
    else
    {
        file.close();
    }


}

bool GameLoop::getGameState()
{
    return GameState;
}

void GameLoop::NewGame()
{

}

void GameLoop::Event()
{
	SDL_PollEvent(&event);
    if(birdDie)
    {
        Mix_VolumeChunk(dieSound, 30);
        Mix_PlayChannel(1, dieSound, 0);
        GameState = false;
        SDL_Delay(3000);
        Close();
    }
    else
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                GameState = false;
	        }
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    Mix_VolumeChunk(wingSound, 25);
                    Mix_PlayChannel(1, wingSound, 0);
                    if (!p.JumpState())
                    {
                        p.Jump();
                    }
                    else
			        {
				        p.Gravity();
			        }
		        }
	        }
	        default:
            {
                p.Gravity();
            }
        }
    }
    CollisionDetection();
    Score();
}




void GameLoop::Update()
{
    g1.GroundUpdate1(birdDie);
    g2.GroundUpdate2(birdDie);

    p1_[0].PipeUpdate1(0, birdDie);
	p1_[1].PipeUpdate1(1, birdDie);
	p2_[0].PipeUpdate2(0);
	p2_[1].PipeUpdate2(1);

    std::string scoreText = std::to_string(score);
    t.WriteText(scoreText, scoreFont, white, renderer);

    ifstream read("bestScore.txt");
    read >> bestScore;
    read.close();
    if(score > bestScore)
    {
        bestScore = score;

        ofstream file("bestScore.txt");
        file << score;
        file.close();
    }
}

void GameLoop::Die()
{
    if(birdDie && !checkDie)
    {
        SDL_Delay( 500 );
    }   
}
void GameLoop::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    g1.GroundRender(renderer);
    g2.GroundRender(renderer);

    p1_[0].Render(renderer);
	p1_[1].Render(renderer);
	p2_[0].Render(renderer);
	p2_[1].Render(renderer);

    p.Render(renderer);

    t.Render(renderer);

    SDL_RenderPresent(renderer);
}

bool GameLoop::checkCollision(const SDL_Rect& a,const SDL_Rect& b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void GameLoop::CollisionDetection()
{
    //pipe down
    if(checkCollision( (&p)->getDest() , (&p1_[0])->getDest() ) ||
       checkCollision( (&p)->getDest() , (&p1_[1])->getDest() ) )
    {
        birdDie = true;
    }

    // pipe up
    if(checkCollision( (&p)->getDest() , (&p2_[0])->getDest() ) ||
       checkCollision( (&p)->getDest() , (&p2_[1])->getDest() ) )
    {
        birdDie = true;
    }

    //đất
    if(checkCollision( (&p)->getDest() , (&g1)->getDest() ) ||
       checkCollision( (&p)->getDest() , (&g2)->getDest() ) )
       {
        birdDie = true;
       }
}

bool GameLoop::checkScore(const SDL_Rect& a,const SDL_Rect& b)
{
    if( (int)a.x == (int) (b.x + 40) ) return true;
    return false;
}

void GameLoop::Score()
{
    if(checkScore( (&p)->getDest() , (&p1_[0])->getDest() ) ||
       checkScore( (&p)->getDest() , (&p1_[1])->getDest() ) )
    {
        score ++;
    }
}

void GameLoop::Close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

void GameLoop::set_color(int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}