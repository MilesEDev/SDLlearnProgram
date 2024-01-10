#include "gui.h"
#include "window.h"
#include <future>
#include <algorithm>

gui::gui() 
{
	/*
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
	*/
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
	


	SDL_Event event = SDL_Event();
	while (event.type != SDL_QUIT)
	{

	

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) break;
			ImGui_ImplSDL2_ProcessEvent(&event);

		}
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();

		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(windowx / 5, windowy), ImGuiCond_Once);

		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
		ImGui::Begin("Hello, world!");

		//std::cout << "Is thread1runnning? " << (thread1Running) << std::endl;

		//thread1Running = true;
		//if (thread1Running)
		//{

			//std::cout << "Is getToRun null?: " << (myThreadManager->getToRun() == nullptr) << std::endl;
		if (!thread1Running && !thread2Running)
		{
			//std::cout << "Draw to screen" << std::endl;
			SDL_RenderCopy(sdlrend, mytextbackground, nullptr, srcRectBlack);
			//std::cout << mytextbackground<< "mybackground" << std::endl;
			SDL_RenderCopy(sdlrend, mytext, nullptr, srcRect);
		}
		if(thread1Running || thread2Running)
		{
			if (myThreadManager->getToRun() != nullptr)
			{
				std::cout << mytext << std::endl;
				SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
				myrenderer->resetSDLColours();
				myThreadManager->getToRun()->runCommand(myrenderer, myrenderer->getPen());
				myThreadManager->setToRun(nullptr);
				myrenderer->removeAnyTargets();
				SDL_RenderCopy(myrenderer->getSDLRenderer(), mytext, nullptr, srcRect);

				std::cout << "hello world" << std::endl;


				std::cout << "main thread release" << std::endl;
				SDL_Delay(5000);
				mainToThread.release();

			}
			else {
				
				SDL_RenderCopy(sdlrend, mytextbackground, nullptr, srcRectBlack);
				//std::cout << mytextbackground<< "mybackground" << std::endl;
				SDL_RenderCopy(sdlrend, mytext, nullptr, srcRect);
			}
		}
		else if(threadsRunning == true)
		{
			threadsRunning = false;
			//error = errorth1 + errorth2;
			errorth1 = "";
			errorth2 = "";
			std::cout << "------------------threads terminated-------------" << std::endl;
			if (error != "")
			{
				ImGui::OpenPopup("ThePopup");
			}
			else
			{
				error = "";
			}
			
		}
		if (!threadsRunning)
		{




			if (this->commandLine == "run") {
				mythread->join();
				if (!strmultiline.empty() && !thread2.empty())
				{

					SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
					std::cout << "Render target is now: " << mytext << std::endl;


					SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 255, 255, 255, 255);
					std::cout << "did text clear" << std::endl;
					SDL_RenderClear(myrenderer->getSDLRenderer());
					myrenderer->setPenColourRGBA(0, 0, 0, 0);
					myrenderer->setFill(false);
					myrenderer->setPen(0, 0);

					myrenderer->removeAnyTargets();
					threadsRunning = true;
					std::cout << "_________________________________newthread button started_________---" << std::endl;

					std::string newStr = strmultiline;
					std::string newStr2 = thread2;
					thread1Running = true;
					std::thread thread_runner1(&gui::runnerThreaded, this, myrenderer, newStr, std::ref(errorth1), std::ref(thread1Running), 1);

					thread_runner1.detach();



					thread2Running = true;
					std::thread thread_runner2(&gui::runnerThreaded, this, myrenderer, newStr2, std::ref(errorth2), std::ref(thread2Running), 2);

					thread_runner2.detach();


				}
				else
				{
					myparser->clearAllLists();
					runner(myrenderer, mytext, strmultiline, myparser);
					if (!error.empty())
					{
						ImGui::OpenPopup("ThePopup");

					}
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
				std::string syntax = "";
				if (!strmultiline.empty() && !thread2.empty())
				{
					myparser->clearAllLists();
					myrenderer->setPen(0, 0);
					myparser->splitToCommands(strmultiline);
					syntax = myparser->syntaxCheckAll();
					myparser->clearAllLists();
					myrenderer->setPen(0, 0);
					myparser->splitToCommands(thread2);

				}
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

				syntax = syntax + myparser->syntaxCheckAll();
		
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
					error = "";
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
				if (!strmultiline.empty() && !thread2.empty())
				{

					SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
					std::cout << "Render target is now: " << mytext << std::endl;


					SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 255, 255, 255, 255);
					std::cout << "did text clear" << std::endl;
					SDL_RenderClear(myrenderer->getSDLRenderer());
					myrenderer->setPenColourRGBA(0, 0, 0, 0);
					myrenderer->setFill(false);
					myrenderer->setPen(0, 0);

					myrenderer->removeAnyTargets();
					threadsRunning = true;
					std::cout << "_________________________________newthread button started_________---" << std::endl;

					std::string newStr = strmultiline;
					std::string newStr2 = thread2;
					thread1Running = true;
					std::thread thread_runner1(&gui::runnerThreaded, this, myrenderer, newStr, std::ref(errorth1), std::ref(thread1Running), 1);

					thread_runner1.detach();



					thread2Running = true;
					std::thread thread_runner2(&gui::runnerThreaded, this, myrenderer, newStr2, std::ref(errorth2), std::ref(thread2Running), 2);

					thread_runner2.detach();


				}
				else if (!strmultiline.empty())
				{
					myparser->clearAllLists();
					myrenderer->setPen(0, 0);
					runner(myrenderer, mytext, strmultiline, myparser);

				}
				else if (!str.empty())
				{
					if (!runner(myrenderer, mytext, str, myparser))
					{
						ImGui::OpenPopup("ThePopup");

					}
				}

			}


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


bool gui::runnerThreaded(Render* myrenderer,std::string program,std::string &errorth,bool &isrunning,int threadid)
{
	isrunning = true;
	Render* myThreadRenderer = new Render();
	myThreadRenderer->setSDLRenderer(myrenderer->getSDLRenderer());
	parser* myparser = new parser();
	myparser->splitToCommands(program);
	std::string tempError = myparser->syntaxCheckAll();
	errorth = tempError;
	std::cout << errorth << std::endl;

	while (true)
	{
		if (errorth1 == "ok" && errorth2 == "ok")
		{
			std::string tempError = myparser->runForAllThread(myrenderer, threadToThread, myThreadRenderer, mainToThread, myThreadManager, threadid);
			break;
		}
		else if (errorth1 != "" && errorth2 != "") 
		{
			break;
		}
	}
		
	
	
	errorth = tempError;
	
	if (tempError != "ok")
	{
		error = error + errorth;
	}
	
	
	myparser->clearAllLists();
	isrunning = false;
	
	
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

ThreadManager* gui::getManager()
{
	return myThreadManager;
}

void gui::releaseMainSemaphore()
{
	mainToThread.release();
}





