#include "Game.h"
#include "SDL2/SDL_image.h"

bool Game::init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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


	m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
	//m_textureManager.load("Assets/player.png", "animate2", m_pRenderer);
	//m_textureManager.load("Assets/CuteDog.png", "animate3", m_pRenderer);
	
	m_bRunning = true;
	return true;
}
void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	m_currentFrame2 = ((SDL_GetTicks() / 50) % 8);
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//m_textureManager.draw("animate3", 100, 100, 128, 128, m_pRenderer);
	
	m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
	//m_textureManager.drawFrame("animate2", 120, 120, 50, 60, 4, m_currentFrame2, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}
void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) //�̺�Ʈ�� ������ �� ���� ��� ����??
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit(); 
}
bool Game::running()
{
	return m_bRunning;
}
