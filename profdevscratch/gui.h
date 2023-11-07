#pragma once
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>



class gui
{
private:
	SDL_Window* mySDLWindow;
public:
	gui();
	void makeDefaultFrame();
	
};
