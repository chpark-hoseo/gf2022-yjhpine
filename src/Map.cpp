#include "map.h"
#include "Game.h"

Map::Map(const LoaderParams* pParams, int x, int y) : SDLGameObject(pParams)
{
	mbox.x = x;
	mbox.y = y;

	mbox.w = 32;
	mbox.h = 32;
}
void Map::draw()
{
	
}
void Map::update()
{

}
SDL_Rect Map::getbox()
{
	return mbox;
}