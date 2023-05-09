#pragma once
#include "Object.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

using namespace std;

class TextObject : public Object
{
private:
	SDL_Color color = {255, 255, 255, 255};
	//SDL_Color color2;

	SDL_Texture* texture;
	SDL_Surface* surfaceText;

public:
	TextObject();
	~TextObject();

	TTF_Font* font;

	SDL_Texture* getTextTexture();
	void WriteText(string text, TTF_Font* textFont, SDL_Color color, SDL_Renderer* ren);
	void Render(SDL_Renderer* ren);
};