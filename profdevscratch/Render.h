#pragma once
#include <utility>      
#include <string>       
#include <iostream>     

#include "window.h"
#include "SDL.h"
#include "eventfactory.h"
#include <array>
#include <vector>




/**
 * .the custom handy dandy renderer for all your rendering needs 
 */
class Render
{
private:

	bool requiresDrawUpdate = false;

	bool rendererFinished = false;

	/**
	 * .any function errors to be returned
	 */
	std::string error;
	std::vector<Uint8> penRGBA = { 255,255,255,255 };

	std::array<float, 4> renderBackground = { 1,1,1,1 };

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

	/**
	 * .
	 * 
	 * \return  sdl renderer
	 */
	SDL_Renderer* getSDLRenderer();
	/**
	 * .sets sdl renderer
	 */
	
	void setSDLRenderer(SDL_Renderer* myNewRenderer);
	/**
	 * .sets fill 
	 * 
	 * \param onOrOff fill on or fill off
	 */
	void setFill(bool onOrOff);
	/**
	 * .gets pen colour
	 * 
	 * \return  the pen colour
	 */
	std::vector<Uint8> getPenColour();

	/**
	 * .gets fill bool
	 * 
	 * \return the fill bool 
	 */
	bool getFill();
	/**
	 * .gets fill value
	 * 
	 * \return fill bool 
	 */
	/**
	 * .gets pen 
	 * 
	 * \return pen values
	 */
	std::pair<float, float> getPen();
	/**
	 * .gets window
	 * 
	 * \return object window value
	 */
	window* getWindow();
	/**
	 * .draws shape to texture
	 * 
	 * \param targetShape shape to be drawn
	 */
	void drawShapeToText(shape* targetShape);
	/**
	 * 
	 * .gets last function error
	 */
	std::string getLastError(); 
	/**
	 * .remove all texture targets 
	 * 
	 */
	void removeAnyTargets();


	void setBackgroundColour(std::array<float,4> colour);

	std::array<float, 4> getBackgroundColour();

	void setFinished(bool finished);

	bool isFinished();

	void waitForRenderUpdate();

	void doDraw();

	bool getRequiresUpdate();

	void resetSDLColours();
};

