#pragma once
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>
#include "window.h"
#include "imgui_stdlib.h"
#include "Render.h"
#include "parser.h"



class gui
{
private:
	SDL_Window* mySDLWindow;
public:
	gui();
	gui(window* mywindow);
	void makeDefaultFrame(Render* myrenderer,SDL_Texture* mytext,SDL_Renderer* myrend);
	SDL_Window* getWindow();
	


	
};
