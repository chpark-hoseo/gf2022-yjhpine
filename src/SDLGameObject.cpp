#pragma once
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), 
    m_position(pParams->getX(), pParams->getY()),
    m_velocity(0, 0), m_acceleration(0,0) , m_gravity(0, 0.5), m_gravitySpeed(0, 0)
{
    m_position.getX();
    m_position.getY();
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentRow = 2;
    m_currentFrame = 0;
} 
void SDLGameObject::draw(SDL_RendererFlip flip, int x, int y)
{
    TextureManager::Instance()->drawFrame(m_textureID,
        x, y,
        m_width, m_height, 
        m_currentRow, m_currentFrame, 
        TheGame::Instance()->getRenderer(), flip);
}
void SDLGameObject::update()
{
    m_velocity += m_acceleration;
    m_position += m_velocity;
}
void SDLGameObject::Gravity()
{
     m_gravitySpeed += m_gravity;
     m_position += m_gravitySpeed;
}