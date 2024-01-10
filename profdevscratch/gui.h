#pragma once
#if __has_include("imgui.h") && __has_include(<stdint.h>)
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"
#endif

#include <stdio.h>
#include <SDL.h>
#include "window.h"

#include "Render.h"
#include "parser.h"
#include <thread>
#include <semaphore>
#include "ThreadManager.h"



/**
 * .the gui of this program
 */
class gui
{
private:
	
	ThreadManager* myThreadManager = new ThreadManager();
	/**
	 * .single line str to take in
	 */
	std::string str;
	/**
	 * .multi line string to take in 
	 */
	std::string strmultiline;
	/*
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
	/**
	 * .the text box for threading programs
	 */
	std::string thread2 = "";
	/**
	 * .binary semaphore to control thread1 and thread2 accsess to renderer
	 */
	std::binary_semaphore
		threadToThread{1};
	/**
	 * .binary semaphore to control accsess to mainthread
	 */
	std::binary_semaphore
		mainToThread{ 0 };
	/**
	 * .the texture rectangle area
	 */
	SDL_Rect* srcRect;

	/**
	 * .var to show whether thread 1 is running 
	 */
	bool thread1Running = false;
	/**
	 * var to show whether thread 2 is running.
	 */
	bool thread2Running = false;
	/**
	 * .var to show whether any thread is running 
	 */
	bool threadsRunning = false;
	/**
	 * .stores error message for thread1
	 */
	std::string errorth1 ="";
	/**
	 * .stores error message for thread2
	 */
	std::string errorth2 ="";

	
	
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

	bool runnerThreaded(Render* myrenderer, std::string program,std::string &erroth,bool &isRunning,int threadid);
	/**
	 * .gets the line from console
	 * 
	 * \return the console line
	 */
	std::string getConsoleInput();
	
	/**
	 * .sets console input
	 * 
	 * \return 
	 */
	void setConsoleInput(std::string newline);
	
	/**
	 * .gets the text in program textbox
	 * 
	 * \return the text in program textbox
	 */
	std::string getMultiLine();

	/**
	 * .this sets the text multiline program textbox
	 * 
	 * \param newmulti the new text to set multiline program textbox to
	 */
	void setMultiLine(std::string newmulti);

	
	/**
	 * .this gets the thread manager containing data used for controlling thread1 and 2
	 * 
	 * \return the threadmanager to return
	 */
	ThreadManager* getManager();
	/**
	 * .releases main semaphore so thread can continue execution
	 * 
	 */
	void releaseMainSemaphore();
	
	/**
	 * .sets error message for thread1
	 * 
	 * \param newErroth the new error message for thread1
	 */
	void setErroth1(std::string newErroth);

	/**
	 * .sets error message for thread2
	 *
	 * \param newErroth the new error message for thread2
	 */
	void setErroth2(std::string newErroth);


	
};	


