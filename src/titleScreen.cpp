/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * titleScreen.cpp
 *
 */

#include "titleScreen.h"

TitleScreen::TitleScreen()
{
	Window::SetTitle("Click to start");

	Window::Clear();
	Window::Present();
}

TitleScreen::~TitleScreen()
{
	CleanUp();
}

void
TitleScreen::EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			timesYouTryToExit++;
			switch (timesYouTryToExit) {
				case 1:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "NO! You haven't play it", "You can not pass", Window::m_Window);
					break;
				case 2:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "I say no", "You can not pass", Window::m_Window);
					break;
				case 3:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "I SAY NO!!", "You can not pass", Window::m_Window);
					break;
				case 4:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "NOOOOOOOOO!!!!!", "You can not pass", Window::m_Window);
					break;
				case 5:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fine......You won", "You can pass now", Window::m_Window);
					gameIsRunning = false;
					gameState = GAME_QUIT;
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			gameIsRunning = false;
			gameState = GAME_STAGE_1;
			break;
	}
}

void
TitleScreen::Update()
{
}

void
TitleScreen::Render()
{
}

void
TitleScreen::CleanUp()
{
}
