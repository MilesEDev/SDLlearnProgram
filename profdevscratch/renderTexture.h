
#pragma once
#include <utility>      
#include "SDL.h"
#include <iostream>    
#include "Render.h"

class renderTexture
{
private:
	std::string lastError;
	std::pair<int, int> texturesize;
	SDL_Texture* mySDLTexture;
	SDL_Renderer* textureRenderContext;


public:

	renderTexture();

	renderTexture(int sizex, int sizey);

	renderTexture(SDL_Renderer* myrenderer);

	renderTexture(SDL_Renderer* myrenderer, int sizex, int sizey);


	void setSize(int newx, int newy);

	std::pair<int, int> getSize();



	SDL_Renderer* getRenderContext();

	void linkTextureToRender(SDL_Renderer* renderer);

	SDL_Renderer* targetThisTexture(SDL_Renderer* renderer);

	SDL_Texture* getSDLTexture();
		
		
	

	
	
};

