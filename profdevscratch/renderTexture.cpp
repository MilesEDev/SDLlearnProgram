#include <utility>      
#include "SDL.h"
#include <iostream>     
#include "contextalreadyset.h"
#include "renderTexture.h"



renderTexture::renderTexture()
{


}
renderTexture::renderTexture(int sizex, int sizey)
{
	texturesize = std::make_pair(sizex, sizey);
}
renderTexture::renderTexture(SDL_Renderer* myrenderer) 
{
	mySDLTexture = SDL_CreateTexture(myrenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 450, 200);
	texturesize = std::make_pair(450, 200);
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
void renderTexture::expand(std::pair<int, int> vertices[]) {

	int donothing = 1;
}

SDL_Renderer* renderTexture::getRenderContext() 
{
	return textureRenderContext;
}

void renderTexture::linkTextureToRender(SDL_Renderer* renderer) 
{
	try 
	{
		throw contextalreadyset();
		/*
		if (textureRenderContext != nullptr) {

			std::cout << "null triggered";
			throw contextalreadyset();

		}
		else {
			textureRenderContext = renderer;
			mySDLTexture = SDL_CreateTexture(textureRenderContext, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, texturesize.first, texturesize.second);
		}*/
	}
		catch(contextalreadyset ermsg) {
			ermsg.what();
		}
		
	

}

