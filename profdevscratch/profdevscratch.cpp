// profdevscratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#include "shape.h"
#include "gui.h"
#include "Render.h"
#include "eventfactory.h"
#include "parser.h"
#include "Expression.h"
#include "dataConverter.h"
#undef main


int main()
{
    
    Render* myrenderer = new Render(); 
    window* mywindow = new window();
    mywindow->showWindow();
    
    myrenderer->linkToWindow(mywindow);
    
    
    SDL_Renderer* mySDLRenderer = myrenderer->getSDLRenderer();
    SDL_Texture* mytext = SDL_CreateTexture(mySDLRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
    SDL_SetRenderTarget(mySDLRenderer, mytext);
    SDL_SetRenderDrawColor(mySDLRenderer, 255, 255, 255, 255);
    SDL_RenderClear(mySDLRenderer);
   
    SDL_SetRenderTarget(mySDLRenderer, nullptr);

    SDL_Delay(5000);

  
   
  
    gui* mygui = new gui(mywindow);
    
    mygui->makeDefaultFrame(myrenderer,mytext,myrenderer->getSDLRenderer());
    SDL_Delay(5000);
    

    
    
    


    
    
    
    

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
