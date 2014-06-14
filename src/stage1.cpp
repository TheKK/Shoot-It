/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * stage1.cpp
 *
 */

#include "stage1.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
	CleanUp();
}

void
Stage1::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			clickCount++;
			SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0x00, 0x00, 0xff);
			SDL_SetWindowGrab(Window::m_Window, SDL_TRUE);
			break;
		case SDL_KEYDOWN:		//JUST FOR DEBUGING
			if (event->key.keysym.sym == SDLK_F12) {
				gameIsRunning = false;
				gameState = GAME_QUIT;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			clickCount++;
			SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0x00, 0x00, 0xff);
			break;
	}
}

void
Stage1::Update()
{
	stringstream windowTitle;
	windowTitle << "Click: " << clickCount;
	Window::SetTitle(windowTitle.str());

	if (clickCount == 10) {
		gameIsRunning = false;
		gameState = GAME_STAGE_2;
	}
}

void
Stage1::Render()
{
	Window::Clear();
	Window::Present();
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 0xff);
}

void
Stage1::CleanUp()
{
}
