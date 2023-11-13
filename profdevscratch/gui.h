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
#include <thread>
#include <thread>




class gui
{
private:
	std::string commandLine;
	SDL_Window* mySDLWindow;
	std::thread* mythread;

public:
	std::string error;
	gui();
	gui(window* mywindow);
	void makeDefaultFrame(Render* myrenderer,SDL_Texture* mytext,SDL_Renderer* myrend);
	SDL_Window* getWindow();
	void consoleInput();
	void caller();
	void runner(Render* myrenderer,SDL_Texture* mytext,std::string mystring,parser* myparser);


	




	
};

