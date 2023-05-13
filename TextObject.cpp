#include "TextObject.h"
#include <cstring>

TextObject::TextObject()
{
	surfaceText = NULL;
}

TextObject::~TextObject()
{
	SDL_FreeSurface(surfaceText);
	TTF_CloseFont(font);
	font = NULL;
}

SDL_Texture* TextObject::getTextTexture()
{
	return texture;
}

void TextObject::WriteText(string text, TTF_Font* textFont, SDL_Color textColor, SDL_Renderer* ren)
{
	font = textFont;
	surfaceText = TTF_RenderText_Solid(font, text.c_str(), textColor); //text.c_str() trả về một con trỏ tới một chuỗi ký tự có kiểu const char*
	texture = SDL_CreateTextureFromSurface(ren, surfaceText);
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);
	setDest(220, 20, w, h);
}

void TextObject::WriteText1(string text, TTF_Font* textFont, SDL_Color textColor, SDL_Renderer* ren)
{
	font = textFont;
	surfaceText = TTF_RenderText_Solid(font, text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(ren, surfaceText);
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);
	setDest(160, 280, w, h);
}

void TextObject::WriteText2(string text, TTF_Font* textFont, SDL_Color textColor, SDL_Renderer* ren)
{
	font = textFont;
	surfaceText = TTF_RenderText_Solid(font, text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(ren, surfaceText);
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);
	setDest(350, 330, w, h);
}

void TextObject::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTextTexture(), NULL, &getDest());
}