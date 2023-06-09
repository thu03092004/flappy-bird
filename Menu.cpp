#include "Menu.h"

Menu::Menu()
{
    on_menu_state = true;
    on_end_state = false;
    howToPlay = false;
}

bool Menu::is_on_menu_state()
{
    return on_menu_state;
}

bool Menu::is_on_end_state()
{
    return on_end_state;
}

bool Menu::how_to_play()
{
    return howToPlay;
}
void Menu::Start()
{
    on_menu_state = true;
    on_end_state = false;
}

void Menu::Return()
{
    on_menu_state = true;
    howToPlay = false;
}

void Menu::handleEvent(SDL_Event event, bool &gameState, Mix_Chunk* clickSound)
{
    if (on_menu_state)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int _x = event.button.x;
            int _y = event.button.y;
            if (144 <= _x && _x <= 144 + 190 && 312 <= _y && _y <= 312 + 73)
            {
                Mix_VolumeChunk(clickSound, 25);
                Mix_PlayChannel(1, clickSound, 0);
                on_menu_state = false;
            }
            else if (144 <= _x && _x <= 144 + 190 && 412 <= _y && _y <= 412 + 73)
            {
                Mix_VolumeChunk(clickSound, 25);
                Mix_PlayChannel(1, clickSound, 0);
                gameState = false;
            }
            else if (398 <= _x && _x <= 398 + 42 && 551 <= _y && _y <= 551 + 61)
            {
                Mix_VolumeChunk(clickSound, 25);
                Mix_PlayChannel(1, clickSound, 0);
                on_menu_state = false;
                howToPlay = true;
            }
        }
    }
}

void Menu::handle_end_menu_state_event(SDL_Event event, bool &gameState, Mix_Chunk* clickSound)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int _x = event.button.x;
        int _y = event.button.y;

        if(49 <= _x && _x <= 49 + 170 && 440 <= _y && _y <= 440 + 68)
        {
            Mix_VolumeChunk(clickSound, 25);
            Mix_PlayChannel(1, clickSound, 0);
            on_end_state = false;
        }
        else if(259 <= _x && _x <= 259 + 170 && 440 <= _y && _y <= 440 + 68)
        {
            Mix_VolumeChunk(clickSound, 25);
            Mix_PlayChannel(1, clickSound, 0);
            gameState = false;
        }
    }
}
// MenuOption Menu::handleMenuClick(SDL_Event event)
// {
//     if (on_end_state)
//     {
//         if (event.type == SDL_MOUSEBUTTONDOWN)
//         {
//             int _x = event.button.x;
//             int _y = event.button.y;

//             if (49 <= _x && _x <= 49 + 170 && 480 <= _y && _y <= 480 + 68)
//             {
//                 return PLAY_AGAIN;
//             }
//             else if (259 <= _x && _x <= 259 + 170 && 480 <= _y && _y <= 480 + 68)
//             {
//                 return QUIT;
//             }
//             else
//             {
//                 // Không nhấp vào gì cả
//                 return -1;
//             }
//         }
//     }
// }

void Menu::update(bool &birdDie)
{
    if (birdDie)
    {
        on_end_state = true;
    }
}

void Menu::CreateTexture1(const char *address, SDL_Renderer *ren)
{
    end_state = TextureManager::Texture(address, ren);
}

void Menu::Render(SDL_Renderer *ren)
{
    if (on_menu_state)
    {
        SDL_RenderCopyEx(ren, getTexture(), NULL, NULL, 0, NULL, SDL_FLIP_NONE);
    }
    if (on_end_state)
    {
        SDL_RenderCopyEx(ren, end_state, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
    }
}