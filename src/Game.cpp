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


	m_textureManager.load("Assets/Tree.png", "animate", m_pRenderer);
	m_textureManager.load("Assets/CuteDog.png", "animate2", m_pRenderer);
	m_textureManager.load("Assets/hihit.png", "animate3", m_pRenderer);
	
	m_bRunning = true;
	return true;
}
void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 80) % 5);
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 133, 251, 255, 255);//�⺻ ���
	SDL_RenderClear(m_pRenderer);
	
	SDL_Rect fillRect = { 0, 400, 640, 200}; //��ٴ��� ǥ���ϴ� �簢����
	SDL_SetRenderDrawColor(m_pRenderer, 105, 73, 0, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect);

	SDL_Rect fillRect2 = { 0, 400, 640, 20 }; //�ܵ� ǥ��
	SDL_SetRenderDrawColor(m_pRenderer, 103, 255, 56, 255);
	SDL_RenderFillRect(m_pRenderer, &fillRect2);

	m_textureManager.draw("animate2", 250, 310, 128, 128, m_pRenderer);//������ ��������Ʈ
	m_textureManager.draw("animate", 180, 190, 256, 256, m_pRenderer);//���� ��������Ʈ
	
	m_textureManager.drawFrame("animate3", 400, 360, 64, 64, 0, m_currentFrame, m_pRenderer); //�ٶ��� �𳯸��� ����..?�� ǥ���Ϸ� �߽��ϴ�.
	m_textureManager.drawFrame("animate3", 100, 360, 64, 64, 0, m_currentFrame, m_pRenderer); 
	m_textureManager.drawFrame("animate3", 500, 360, 64, 64, 0, m_currentFrame, m_pRenderer);

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
