/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * gameState.h
 *
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include <SDL.h>

using namespace std;

class GameState
{
	public:
		virtual ~GameState(){};

		virtual void EventHandler(SDL_Event* event) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
};

#endif
