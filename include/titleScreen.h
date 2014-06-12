/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * titleScreen.h
 *
 */

#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <iostream>
#include <SDL.h>

#include "global.h"
#include "window.h"

#include "gameState.h"

using namespace std;

extern bool gameIsRunning;
extern enum GameStateFlag gameState;

class TitleScreen: public GameState
{
	public:
		TitleScreen();
		~TitleScreen();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render();
	private:
		int timesYouTryToExit = 0;

		void CleanUp();
};

#endif
