#pragma once

#include "glew.h"
#include <iostream>
#include <string>
#include "SDL.h"

class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void SwapBuffers();

	virtual ~Display();
protected:
private:
	// Copy constructors hidden from user
	Display& operator=(const Display& display) { }
	Display(const Display& display) { m_window = nullptr; m_glContext = nullptr; }

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
};

