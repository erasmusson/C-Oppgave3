// Oppgave3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameManager.h"
#include "PCharacter.h"
#include "HP.h"
#include "InputManager.h"

#include <stdlib.h>  
#include <crtdbg.h>  
#include <vld.h>
#include <SDL.h>
#include <iostream>

// This project is based on multiple school assignments and lectures from C++ programming. It is under development.

//Put this in main to a battleGame.
/*GameManager &sm = GameManager::Instance();
sm.startGame();
sm.runGame();

cout << "Game over." << endl << endl;
sm.deleteLists();
*/



int main(int argc, char* argv[])
{	
	SDL_Window * window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Surface* helloWorld = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Texture *drawable = nullptr;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL Could not initialize" << std::endl;
		SDL_Quit();
		return EXIT_FAILURE;
	}

	InputManager::Instance().initWindow(&window, &renderer);

	if (renderer == nullptr) {
		std::cerr << "No renderer" << std::endl;
		SDL_DestroyWindow(window); 
		SDL_Quit();
		return EXIT_FAILURE;
	}

	if (window == nullptr) {
		std::cerr << "No window" << std::endl;
		SDL_Quit();
		return EXIT_FAILURE;
	}
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		screenSurface = SDL_LoadBMP("pic.bmp");
		if (screenSurface == nullptr) {
			std::cerr << "No screenSurface" << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			return EXIT_FAILURE;
		}

		//InputManager::Instance().playGameWithArrows();
		//Comment out code below (and remove comment from line above) to play playGameWithArrows() or else moveImageGame() will be played.
		drawable = SDL_CreateTextureFromSurface(renderer, screenSurface);
		SDL_Rect coords;

		//Storlek på bilden
		coords.h = screenSurface->h;
		coords.w = screenSurface->w;

		//Position i vinduet.
		coords.y = 0;
		coords.x = 0;

		SDL_FreeSurface(screenSurface);
		InputManager::Instance().moveImageGame(&renderer, &coords, &drawable);
	}

	SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}



