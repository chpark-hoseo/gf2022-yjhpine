#pragma once
#include "Game.h"
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, 640, 480, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 197, 218, 250, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
	if (!TheTextureManager::Instance()->load("assets/characters.png", "animate", m_pRenderer)) { return false; }
	if (!TheTextureManager::Instance()->load("assets/bg.png", "BG", m_pRenderer)) { return false; }
	if (!TheTextureManager::Instance()->load("assets/brick.png", "brick", m_pRenderer)) { return false; }

	
	m_gameObjects.push_back(new BG(new LoaderParams(0, 0, 1280, 960, "BG")));
	m_gameObjects.push_back(new Player(new LoaderParams(0, 100, 32, 32, "animate")));
	//m_gameObjects.push_back(new Map(new LoaderParams(0, 0, 32, 32, "brick")));

	m_bRunning = true;
	return true;
}
void Game::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 125, 218, 250, 255);
	SDL_RenderClear(m_pRenderer);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);
	for (int i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}

	SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}
void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit(); 
}
bool Game::running()
{
	return m_bRunning;
}