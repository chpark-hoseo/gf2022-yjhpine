#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Collision.h"

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 960

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_MAP_X 40
#define MAX_MAP_Y 30

#define TILE_SIZE 32

class Player : public SDLGameObject
{
private:
    bool isjumping;
    SDL_Rect playerCollider;
    Collision coll; 
    int a;

public:
    void handleInput();
    void Jumping();
    virtual void draw();
    virtual void update();
    virtual void clean();
    void loadMap(const char* name);
    void drawmap();
    void initmap(SDL_Rect src_brick);

    Player(const LoaderParams* pParams);

    SDL_Rect Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    SDL_Rect Brick[1200];
    int tile[MAX_MAP_Y][MAX_MAP_X];
};

