#pragma once
#include <SDL.h>
#include <memory>
#include <iostream>
using namespace std;

class InputManager
{
public:
	static InputManager& Instance() {
		static InputManager inputManager;
		return inputManager;
	}
	// Keyboard.
	bool KeyDown(int iKeyIndex) const { return (CurKeyDown(iKeyIndex)) && (!OldKeyDown(iKeyIndex)); }
	bool KeyStillDown(int iKeyIndex) const { return (CurKeyDown(iKeyIndex)) && (OldKeyDown(iKeyIndex)); }
	bool KeyUp(int iKeyIndex) const { return (!CurKeyDown(iKeyIndex)) && (OldKeyDown(iKeyIndex)); }
	bool KeyStillUp(int iKeyIndex) const { return (!CurKeyDown(iKeyIndex)) && (OldKeyDown(iKeyIndex)); }

	// Mouse.
	bool MouseDown(int iButton) { return (CurKeyDown(iButton)) && (!OldKeyDown(iButton)); }
	bool MouseStillDown(int iButton) const { return (CurKeyDown(iButton)) && (OldKeyDown(iButton)); }
	bool MouseUp(int iButton) const { return (!CurKeyDown(iButton)) && (OldKeyDown(iButton)); }
	bool MouseStillUp(int iButton) const { return (!CurKeyDown(iButton)) && (OldKeyDown(iButton)); }


	void Update();
	void initWindow(SDL_Window **window, SDL_Renderer **renderer);
	void moveImageGame(SDL_Renderer **renderer, SDL_Rect *coords, SDL_Texture **drawable);
	void playGameWithArrows();


protected:
	bool CurKeyDown(int iKeyIndex) const;
	bool OldKeyDown(int iKeyIndex) const;
	bool CurMousebtnDown(int iButton) const;
	bool OldMousebtnDown(int iButton) const;

	// A pointer to SDL's internal key state array.
	const Uint8 * keys = nullptr;

	
	std::unique_ptr<Uint8 []> oldKeys;

	// Number of keys in the arrays above, for this 
	// app. (Can vary depending on setup/hardware.) 
	int keyCount;

	// Mouse pos x and y.
	int mouseX;
	int mouseY;
	// Mouse buttons pressed. 
	Uint8 buttons;
	// Mouse buttons pressed last update. 
	Uint8 oldButtons;

private:
	InputManager() {
		keys = SDL_GetKeyboardState(&keyCount);
		oldKeys = std::unique_ptr<Uint8 []>(new Uint8[keyCount]);
	}
	InputManager(const InputManager&) = delete; // Copy constructor är raderad
	InputManager& operator =(const InputManager&) = delete;
	~InputManager();
};

