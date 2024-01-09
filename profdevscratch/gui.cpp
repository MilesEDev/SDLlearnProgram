#include "gui.h"
#include "window.h"
#include <future>
#include <algorithm>

gui::gui() 
{
	
	window* mywindow = new window(); 
	mySDLWindow = mywindow->getSDLWindow();
	
	SDL_GLContext gl_context = SDL_GL_CreateContext(mySDLWindow);

	SDL_GL_MakeCurrent(mySDLWindow, gl_context);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImGui_ImplSDL2_InitForOpenGL(mySDLWindow, gl_context);
	ImGui_ImplOpenGL3_Init("#version 450");
}
gui::gui(window* mywindow)
{
	
	mySDLWindow = mywindow->getSDLWindow();
	SDL_GLContext gl_context = SDL_GL_CreateContext(mySDLWindow);

	SDL_GL_MakeCurrent(mySDLWindow, gl_context);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForOpenGL(mySDLWindow, gl_context);
	ImGui_ImplOpenGL3_Init("#version 130");
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
	int SDL_GL_SetSwapInterval(1);
	
}
void gui::makeDefaultFrame(Render* myrenderer, SDL_Texture* mytext,SDL_Renderer* sdlrend)
{

	bool threaded = false;
	parser* myparser = new parser();
	std::string filename;
	
	bool done = false;
	ImVec2 buttonsize = ImVec2(50, 20);
	
	float height = 50;
	float width = 50;
	//SDL_GL_BindTexture(mytext,&height,&width);
	int counter = 0;
	
	window* mywindow = myrenderer->getWindow();
	SDL_Rect* srcRectBlack = new SDL_Rect();
	int windowx = mywindow->getWindowSize().first ;
	int windowy = mywindow->getWindowSize().second;
	caller();
	srcRectBlack->x = 0;
	srcRectBlack->y = 0;
	srcRectBlack->w = windowx/5;
	srcRectBlack->h = windowy;
	srcRect = new SDL_Rect();
	srcRect->x = windowx/5;
	srcRect->y = 0;
	srcRect->w = windowx-windowx/5;
	srcRect->h = windowy;
	SDL_Texture* mytextbackground = SDL_CreateTexture(sdlrend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 600, 500);
	
	SDL_SetRenderTarget(sdlrend, mytextbackground);
	SDL_SetRenderDrawColor(sdlrend, 0, 0, 0, 255);
	SDL_RenderClear(sdlrend);
	SDL_SetRenderTarget(sdlrend, nullptr);
	std::string errorth1;
	std::string errorth2;
	
	SDL_Event event = SDL_Event();
	while (event.type != SDL_QUIT)
	{

		//counter++;
		//myrenderer->drawTo(50, 100);

		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) break;
			ImGui_ImplSDL2_ProcessEvent(&event);

		}
		if (!threaded)
		{
			SDL_RenderCopy(sdlrend, mytextbackground, nullptr, srcRectBlack);
			SDL_RenderCopy(sdlrend, mytext, nullptr, srcRect);
		}
		else
		{
			threaded = false;
		}
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();



		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(windowx / 5, windowy), ImGuiCond_Once);

		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
		ImGui::Begin("Hello, world!");
		if (this->commandLine == "run") {


			myparser->clearAllLists();
			runner(myrenderer, mytext, strmultiline, myparser);
			if (!error.empty())
			{
				ImGui::OpenPopup("ThePopup");

			}
			commandLine.clear();
			caller();

		}
		else if (!this->commandLine.empty())
		{
			runner(myrenderer, mytext, commandLine, myparser);
			if (!error.empty())
			{
				ImGui::OpenPopup("ThePopup");

			}
			commandLine.clear();
			caller();


		}

		if (ImGui::Button("save", buttonsize))
		{
			myparser->saveToTxt(strmultiline);

		}
		ImGui::SameLine(0.0f, 9.0f);

		if (ImGui::Button("load", buttonsize))
		{
			strmultiline = myparser->loadFromTxt(filename);

		}
		ImGui::InputText("fileToLoad", &filename);
	
		//ImGui::InputText()
		ImGui::InputTextMultiline("##label", &strmultiline);
		ImGui::InputText("###label", &str);
		ImGui::InputTextMultiline("thread", &thread2);


		if (ImGui::Button("syntax", buttonsize))
		{

			if (!strmultiline.empty())
			{
				myparser->clearAllLists();
				myrenderer->setPen(0, 0);
				myparser->splitToCommands(strmultiline);
			}
			else if (!str.empty())
			{
				myparser->splitToCommands(strmultiline);
			}

			std::string syntax = myparser->syntaxCheckAll();
			if (syntax == "ok") {
				ImGui::OpenPopup("syntax good");
			}
			else
			{
				error = syntax;
				ImGui::OpenPopup("ThePopup");
			}
		}
			
	
			
		if (ImGui::BeginPopupModal("ThePopup")) {
			ImGui::Text(error.c_str());
			if (ImGui::Button("ok", buttonsize))
			{
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();

		}
		if (ImGui::BeginPopupModal("syntax good")) {
			ImGui::Text("syntax good");
			myparser->clearAllLists();
			if (ImGui::Button("ok", buttonsize))
			{
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();

		}

		ImGui::SameLine(0.0f, 9.0f);
		if (ImGui::Button("run", buttonsize))
		{
			if (!strmultiline.empty()) 
			{
				myparser->clearAllLists();
				myrenderer->setPen(0, 0);
				runner(myrenderer, mytext, strmultiline, myparser);
				
			}
			else if (!str.empty())
			{
				if (!runner(myrenderer, mytext, str, myparser) )
				{
					ImGui::OpenPopup("ThePopup");

				}
			}

		}
		if (ImGui::Button("runThreads", buttonsize))//make multi thread changes too
		{
			
			SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);

			Render myrenderer2 = *myrenderer;
			
			std::vector<Render*> renderers = { myrenderer , &myrenderer2 };
			for (int i = 0; i < renderers.size(); ++i) {
				renderers[i]->setFinished(false);
			}

			std::thread thread_runner1(&gui::superSimpleThread,this, myrenderer);
			std::thread thread_runner2(&gui::superSimpleThread, this, &myrenderer2);
			
			bool allRenderersFinished = false;

			while (!allRenderersFinished) {

				allRenderersFinished = true;

				for (auto& renderer : renderers) {

					if (!renderer->isFinished()) allRenderersFinished = false;

					if (renderer->getRequiresUpdate()) {
						renderer->doDraw();
					}
				}				
			}
			
			
			std::cout << "Thread is joinable" << std::endl;
			thread_runner1.join();
			thread_runner2.join();
			std::cout << "Thread joined" << std::endl;
			//thread_runner2.join();

			
			SDL_SetRenderTarget(myrenderer->getSDLRenderer(), nullptr);
			SDL_RenderCopy(myrenderer->getSDLRenderer(), mytext, nullptr, nullptr);

			error = errorth1 + errorth2;

			//ImGui::OpenPopup("ThePopup");
			
		}
		ImGui::End();


		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		SDL_GL_SwapWindow(mySDLWindow);
	}
				
			
}
	

	
	

SDL_Window* gui::getWindow() 
{
	return mySDLWindow;
}

void gui::consoleInput()
{ 
	
	std::getline(std::cin, commandLine);

}

void gui::caller()
{
	mythread = new std::thread(&gui::consoleInput,this);
}

bool gui::runner(Render* myrenderer, SDL_Texture* mytext, std::string mystring, parser* myparser)
{


	myparser->splitToCommands(mystring);

	std::string tempError = myparser->syntaxCheckAll();
	
	if (tempError == "ok") 
	{
		
		std::pair<SDL_Texture*,std::string> runData;
		runData = myparser->runForAll(myrenderer, mytext);
		tempError = runData.second;


	}
	
	if(tempError != "ok")
	{
		error = tempError;
		ImGui::OpenPopup("ThePopup");
	}
	myparser->clearAllLists();
	
	
	return true;

}


bool gui::runnerThreaded(Render* myrenderer, SDL_Texture* mytext,std::string program,std::string &errorth)
{
	Render* myThreadRenderer = new Render();
	myThreadRenderer->setSDLRenderer(myrenderer->getSDLRenderer());
	parser* myparser = new parser();
	myparser->splitToCommands(program);
	std::string syntax = myparser->syntaxCheckAll();

	if (syntax == "ok")
	{
		mytext = myparser->runForAllThread(myrenderer, mytext,semaphoreToShare,srcRect);
	}
	else
	{
		errorth = syntax;
		
	}
	myparser->clearAllLists();


	return true;
}

std::string gui::getConsoleInput()
{
	return commandLine;
}
void gui::setConsoleInput(std::string newline) {

	commandLine = newline;
}

std::string gui::getMultiLine()
{
	return strmultiline;
}


void gui::setMultiLine(std::string newmulti)
{
	strmultiline = newmulti;
}


void gui::superSimpleThread(Render* renderer)
{
	renderer->setBackgroundColour({ 255,0,0,255 });
	renderer->waitForRenderUpdate();

	/*
	std::cout << "Make text red" << std::endl;
	
	SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 255, 0, 0, 255);
	SDL_RenderClear(myrenderer->getSDLRenderer());
	SDL_Delay(2000);
	//std::this_thread::sleep_for(std::chrono::seconds(10));

	*/

	std::cout << "Thread end" << std::endl;
	renderer->setFinished(true);
}



