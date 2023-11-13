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



/**
 * .the gui of this program
 */
class gui
{
private:
	/**
	 * .command line arugment to be taken in 
	 */
	std::string commandLine;
	/**
	 * .sdl window to be used to get width of and such 
	 */
	SDL_Window* mySDLWindow;
	/**
	 * .thread to be used for command line inputs
	 * 
	 * \return thread to be called
	 */
	std::thread* mythread;

public:
	/**
	 * .error to be displayed from exceptions
	 */
	std::string error;
	/**
	 * .consturctor to set imgui context
	 */
	gui();
	/**
	 * .constructor that takes in window to set up context
	 */
	gui(window* mywindow);
	/**
	 * .sets up default frame to take in inputs
	 */
	void makeDefaultFrame(Render* myrenderer,SDL_Texture* mytext,SDL_Renderer* myrend);
	/**
	 * .gets sdl window 
	 */
	SDL_Window* getWindow();
	/**
	 * .thread function to get console input
	 */
	void consoleInput();
	/**
	 * .function to call thread
	 */
	void caller();
	/**
	 * . function to run commands 
	 */
	bool runner(Render* myrenderer,SDL_Texture* mytext,std::string mystring,parser* myparser);


	




	
};

