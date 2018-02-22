#include "stdafx.h"
#include "InputManager.h"



bool InputManager::CurKeyDown(int iKeyIndex) const
{
	if (keys[iKeyIndex] != 0) {
		return true;
	}
	return false;
}

bool InputManager::OldKeyDown(int iKeyIndex) const
{
	if (oldKeys[iKeyIndex] != 0) {
		return true;
	}
	return false;
}

bool InputManager::CurMousebtnDown(int iButton) const
{
	return false;
}

bool InputManager::OldMousebtnDown(int iButton) const
{
	return false;
}

void InputManager::Update()
{
	//Sparar nuvarande buttons i oldButtons
	oldButtons = buttons;

	//Kopierar keys (nuvarande tast) till oldKeys.
	memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));
	
	//Hämtar in nya events.
	SDL_PumpEvents();
	buttons = SDL_GetRelativeMouseState(&mouseX, &mouseY);

}

void InputManager::initWindow(SDL_Window ** window, SDL_Renderer ** renderer)
{
	SDL_Init(SDL_INIT_VIDEO);

	*window = SDL_CreateWindow(
		"Here we go",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		550,
		400,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void InputManager::moveImageGame(SDL_Renderer ** renderer, SDL_Rect * coords, SDL_Texture ** drawable)
{
	InputManager &im = InputManager::Instance();
	bool GameOn = true;
	while (GameOn) {
		im.Update();

		if (im.KeyDown(SDL_SCANCODE_LEFT)) {
			int b = coords->x;
			coords->x = b - 1;
		}


		if (im.KeyDown(SDL_SCANCODE_RIGHT)) {
			int b = coords->x;
			coords->x = b + 1;
		}

		if (im.KeyDown(SDL_SCANCODE_UP)) {
			int b = coords->y;
			coords->y = b - 1;
		}

		if (im.KeyDown(SDL_SCANCODE_DOWN)) {
			int b = coords->y;
			coords->y = b + 1;
		}

		if (SDL_HasEvent(SDL_QUIT)) {
			GameOn = false;
			cout << "Pressed window" << endl;
		}

		SDL_RenderCopy(*renderer, *drawable, nullptr, coords);

		SDL_RenderPresent(*renderer);
		SDL_RenderClear(*renderer);
	}
}

void InputManager::playGameWithArrows()
{
	bool GameOn = true;
	while (GameOn) {
		Update();

		if (KeyDown(SDL_SCANCODE_LEFT)) {
			cout << "Pressing left" << endl;
		}

		if (KeyStillDown(SDL_SCANCODE_LEFT)) {
			cout << "Still pressing left" << endl;
		}

		if (KeyDown(SDL_SCANCODE_RIGHT)) {
			cout << "Pressing right" << endl;
		}

		if (KeyDown(SDL_SCANCODE_UP)) {
			cout << "Pressing up" << endl;
		}

		if (KeyDown(SDL_SCANCODE_DOWN)) {
			cout << "Pressing down" << endl;
		}

		if (SDL_HasEvent(SDL_QUIT)) {
			GameOn = false;
			cout << "Pressed window" << endl;
		}

	}
}

InputManager::~InputManager()
{
	oldKeys.reset(nullptr);
}
