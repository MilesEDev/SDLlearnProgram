#pragma once
#include <utility>      
#include <string>       
#include <iostream>     

#include "window.h"
#include "SDL.h"
#include "eventfactory.h"
#include <array>
#include <vector>





class Render
{
private:

	std::string error;
	std::vector<Uint8> penRGBA;
	/**
	 * .the cordinate of the pen
	 */
	std::pair<float, float> penStartCordinate;
	/**
	 * .a boolean to show whether to fill a shape or not
	 */
	bool fill = false;
	/**
	 * .the window to draw on
	 */
	SDL_Window* canvas;
	/**
	 * .the sdl renderer to render shapes with
	 */
	SDL_Renderer* myrenderer;

	window* renderWindow;



public:
	/**
	 * .blank constructor generates a default window and default positions for pen
	 *
	 */
	Render();
	/**
	* this is the constrctor for creating a renderer with user positions
	*
	* \param x this is used as x position for cordinate of pen
	* \param y this is used as y position for cordinate of pen
	*/
	

	Render(window* mywindow);
	/**
	*
	* .sets the positon of the pen with provided x and y cordinates
	*
	* \param x the x cordinate of where the pen should be
	* \param y the y cordinate of where the pen should be
	*/
	Render(SDL_Renderer* SDLRenderer); 
	void setPen(float x, float y);
	/**
	 * .draws line to set position given by float cords from pen pos
	 *
	 * \param x the x cordinate to target
	 * \param y the y cordinate to target
	 */
	void drawTo(float x, float y);
	/**
	 *
	 * .links the renderer to a new window
	 *
	 * \param mywindow the window to link renderer too
	 */
	void linkToWindow(window* mywindow);
	/**
	 * .uses the red green blue and alpha values to set the colour of the pen
	 *
	 * \param R red value
	 * \param G green value
	 * \param B blue value
	 * \param A alpha value
	 */
	void setPenColourRGBA(Uint8 R, Uint8 G, Uint8 B, Uint8 A);
	/**
	 * .sets the colour of the pen using a string to determine what colour to set to
	 *
	 * \param the name of the colour you want to set pen to
	 */
	void setPenColourString(std::string);
	/**
	 *
	 * .this clears the current render with the current colour
	 *
	 */
	void renderClear();
	/**
	 * .this swaps the back buffer and by doing so presents all the rendering
	 *
	 */
	void showRender();
	/**
	 * . clears the canvas back to a white background immediatly called both rendershow and renderclear
	 */
	void renderClearAbsoloute();

	
	SDL_Renderer* getSDLRenderer();

	void setSDLRenderer(SDL_Renderer* myNewRenderer);
	
	void setFill(bool onOrOff);
	
	std::vector<Uint8> getPenColour();

	bool getFill();

	std::pair<float, float> getPen();

	window* getWindow();

	void drawShapeToText(shape* targetShape);

	std::string getLastError(); 

	void removeAnyTargets();

};

