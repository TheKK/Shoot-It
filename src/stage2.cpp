/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * stage2.cpp
 *
 */

#include "stage2.h"

Stage2::Stage2()
{
}

Stage2::~Stage2()
{
	CleanUp();
}

void
Stage2::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:		//JUST FOR DEBUGING
			gameIsRunning = false;
			gameState = GAME_QUIT;
			break;
		case SDL_WINDOWEVENT:
			switch (event->window.event) {
				case SDL_WINDOWEVENT_MOVED:
					clickCount += 5;
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					SDL_ShowWindow(Window::m_Window);
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			clickCount++;


			SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0x00, 0x00, 0xff);
			break;
	}
}

void
Stage2::Update()
{
	stringstream windowTitle;
	windowTitle << "Click: " << clickCount;
	Window::SetTitle(windowTitle.str());

	if (--currentTime == 0) {
		int x = rand() % (screenW - windowW);
		int y = rand() % (screenH - windowH);
		SDL_SetWindowPosition(Window::m_Window, x, y);

		currentTime = vanishTime;
	}

	if (clickCount >= 50) {
		int x, y;
		int windowX, windowY;

		x = rand() % (clickCount / 5) - (clickCount / 10);
		y = rand() % (clickCount / 5) - (clickCount / 10);

		SDL_GetWindowPosition(Window::m_Window, &windowX, &windowY);

		SDL_SetWindowPosition(
				Window::m_Window,
				windowX + x, windowY + y
				);
	}

	if (clickCount >= 100) {
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		SDL_SetRenderDrawColor(Window::m_Renderer, r, g, b, 0xff);

		vanishTime = 40;
	}

	if (clickCount >= 150) {
		int newWindowW = rand() % (windowW * clickCount / 300);
		int newWindowH = rand() % (windowH * clickCount / 300);

		SDL_SetWindowSize(
				Window::m_Window,
				newWindowW, newWindowH
				);

		vanishTime = 30;
	}

	if (clickCount >= 3500) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Why so serious?", "It's just a game", Window::m_Window);
		gameIsRunning = false;
		gameState = GAME_QUIT;
	}
}

void
Stage2::Render()
{
	Window::Clear();
	Window::Present();
	SDL_SetRenderDrawColor(Window::m_Renderer, 0xff, 0xff, 0xff, 0xff);
}

void
Stage2::CleanUp()
{
}
