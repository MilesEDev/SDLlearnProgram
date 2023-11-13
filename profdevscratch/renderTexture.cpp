#include <utility>      
#include "SDL.h"
#include <iostream>     
#include "contextalreadyset.h"
#include "renderTexture.h"



renderTexture::renderTexture() {}

renderTexture::renderTexture(int sizex, int sizey)
{
	texturesize = std::make_pair(sizex, sizey);
}
renderTexture::renderTexture(SDL_Renderer* myrenderer) 
{
	mySDLTexture = SDL_CreateTexture(myrenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 450, 200);
	texturesize = std::make_pair(450, 200);
}
renderTexture::renderTexture(SDL_Renderer* myrenderer, int sizex, int sizey)
{
	mySDLTexture = SDL_CreateTexture(myrenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 450, 200);
	texturesize = std::make_pair(sizex, sizey);
}
void renderTexture::setSize(int newx, int newy) 
{
	texturesize.first = newx;
	texturesize.second = newy;


}

std::pair<int, int> renderTexture::getSize() 
{
	return texturesize;
}

SDL_Renderer* renderTexture::getRenderContext() 
{
	return textureRenderContext;
}

void renderTexture::linkTextureToRender(SDL_Renderer* renderer) 
{
		if (textureRenderContext != nullptr)
		{

			
			lastError = "texture already assigned";
			

		}
		else 
		{
			textureRenderContext = renderer;
			mySDLTexture = SDL_CreateTexture(textureRenderContext, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, texturesize.first, texturesize.second);
		}
	
		

}

SDL_Renderer* renderTexture::targetThisTexture(SDL_Renderer* renderer)
{
	SDL_SetRenderTarget(renderer, mySDLTexture);
	return renderer;
}

SDL_Texture* renderTexture::getSDLTexture()
{
	return mySDLTexture;
}
