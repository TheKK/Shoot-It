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
		case SDL_QUIT:		//JUST FOR DEBUGING
			gameIsRunning = false;
			gameState = GAME_QUIT;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (++clickCount == 10) {
				gameIsRunning = false;
				gameState = GAME_STAGE_2;
			}

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
