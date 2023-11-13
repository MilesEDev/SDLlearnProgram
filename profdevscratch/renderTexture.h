
#pragma once
#include <utility>      
#include "SDL.h"
#include <iostream>    
#include "Render.h"

/**
 * .texture based on sdl texture but with get texture size and other addditional methods 
 */
class renderTexture
{
private:
	/**
	 * .stores last error to occur
	 */
	std::string lastError;
	/**
	 * .stores texture size
	 */
	std::pair<int, int> texturesize;
	/**
	 * stores sdl texture
	 */
	SDL_Texture* mySDLTexture;
	/**
	 * stores sdl renderer
	 * 
	 */
	SDL_Renderer* textureRenderContext;


public:
	/**
	 * .constructor to set up default texture
	 * 
	 */
	renderTexture();
	/**
	 * .constructor to set up texture with width and height
	 * 
	 * \param sizex the width of texture
	 * \param sizey the height of texture
	 */
	renderTexture(int sizex, int sizey);
	/**
	 * .consturctor to bind renderer context to texture 
	 * 
	 * \param myrenderer the renderer context
	 */
	renderTexture(SDL_Renderer* myrenderer);
	/**
	 * .constructor to set sizes and bind render context to texture
	 * 
	 * \param myrenderer renderer to use as context
	 * \param sizex width of texture
	 * \param sizey height of texture
	 */
	renderTexture(SDL_Renderer* myrenderer, int sizex, int sizey);

	/**
	 * .sets size of texture
	 * 
	 * \param newx new width 
	 * \param newy new height
	 */
	void setSize(int newx, int newy);
	/**
	 * .gets size of texture
	 * 
	 * \return size of texture
	 */
	std::pair<int, int> getSize();

	
	/**
	 * .returns the render context of texture
	 * 
	 * \return the render context of texture 
	 */
	SDL_Renderer* getRenderContext();
	/**
	 * .links texture to render context
	 * 
	 * \param renderer the renderer context to link texture too 
	 */
	void linkTextureToRender(SDL_Renderer* renderer);
	/**
	 * .has renderer target this texture
	 * 
	 * \param renderer the renderer to have targeted
	 * \return the renderer targetted
	 */
	SDL_Renderer* targetThisTexture(SDL_Renderer* renderer);
	/**
	 * .gets the sdl texture
	 * 
	 * \return the sdl texture 
	 */
	SDL_Texture* getSDLTexture();
		
		
	

	
	
};

