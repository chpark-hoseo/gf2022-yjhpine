#include "Game.h"

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
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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
	

	SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;

	SDL_Surface* surface = SDL_LoadBMP("Assets/animate.bmp");
	texture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, NULL, NULL, &SR.w, &SR.h);

	DR.w = SR.w;
	DR.h = SR.h;

	DR.x = SR.x = 0;
	DR.y = SR.y = 0;

	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;

	a = 0;

	m_bRunning = true;
	return true;
}
void Game::update()
{
	if (m_destinationRectangle.x == 0)//����1 - �¿�� �ݺ� �̵��ϱ�
		a = 1;
	else if (m_destinationRectangle.x > 520)
		a = 2;
	if (a == 1)
	{
		m_destinationRectangle.x++;
		SDL_Delay(3);
	}
	else if (a == 2)
	{
		m_destinationRectangle.x--;
		SDL_Delay(3);
	}
}
void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, texture, &SR, &DR);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_RenderFillRect(m_pRenderer, &fillRect);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
	SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
	SDL_RenderDrawRect(m_pRenderer, &outlineRect);

	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);	
	SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH / 2, i);
	}
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
