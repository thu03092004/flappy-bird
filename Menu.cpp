#include "Menu.h"

Menu::Menu()
{
    on_menu_state = true;
    on_end_state = false;
}

bool Menu::is_on_menu_state()
{
    return on_menu_state;
}

bool Menu::is_on_end_state()
{
    return on_end_state;
}

void Menu::handleEvent(SDL_Event event, bool &gameState)
{
    if (on_menu_state)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int _x = event.button.x;
            int _y = event.button.y;
            if (144 <= _x && _x <= 144 + 190 && 312 <= _y && _y <= 312 + 73)
            {
                on_menu_state = false;
            }
            else if (144 <= _x && _x <= 144 + 190 && 412 <= _y && _y <= 412 + 73)
            {
                gameState = false;
            }
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