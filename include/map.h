#pragma once
#include "TextureManager.h"
#include "SDLGameObject.h"

class Map : public SDLGameObject
{
public:
    Map(const LoaderParams* pParams, int x, int y);
	virtual void draw();
	virtual void update();
	SDL_Rect getbox();
private:
	SDL_Rect mbox;
};

