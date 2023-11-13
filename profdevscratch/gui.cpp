#include "gui.h"
#include "window.h"


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
void gui::makeDefaultFrame(Render* myrenderer,SDL_Texture* mytext,SDL_Renderer* sdlrend)
{
	
	parser* myparser = new parser();
	std::string filename;
	std::string str;
	std::string strmultiline;
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
	SDL_Rect* srcRect = new SDL_Rect();
	srcRect->x = windowx/5;
	srcRect->y = 0;
	srcRect->w = windowx-windowx/5;
	srcRect->h = windowy;
	SDL_Texture* mytextbackground = SDL_CreateTexture(sdlrend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 600, 500);
	SDL_SetRenderTarget(sdlrend, mytextbackground);
	SDL_SetRenderDrawColor(sdlrend, 0, 0, 0, 255);
	SDL_RenderClear(sdlrend);
	SDL_SetRenderTarget(sdlrend, nullptr);
	while (true)
	{

		//counter++;
		//myrenderer->drawTo(50, 100);

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);

		}

		SDL_RenderCopy(sdlrend, mytextbackground, nullptr, srcRectBlack);
		SDL_RenderCopy(sdlrend, mytext, nullptr, srcRect);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();



		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(windowx / 5, windowy), ImGuiCond_Once);

		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Once);
		ImGui::Begin("Hello, world!");
		if (this->commandLine == "run") {



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


		if (ImGui::Button("syntax", buttonsize))
		{
			myparser->clearAllLists();
			try {
				bool syntax = myparser->syntaxCheckAll();
				if (syntax) {
					ImGui::OpenPopup("syntax good");
				}

			}
			catch (InvalidParameters& e)
			{
				error = e.returnError();
				ImGui::OpenPopup("ThePopup");
			}
			catch (nonnumberexception& e)
			{
				error = e.returnError();
				ImGui::OpenPopup("ThePopup");
			}
			catch (nonfillvalue e)
			{
				error = e.returnError();
				ImGui::OpenPopup("ThePopup");

			}
			catch (notcolourexception e)
			{
				error = e.returnError();
				ImGui::OpenPopup("ThePopup");

			}
			catch (notcommandexception e)
			{
				error = e.returnError();
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
				if (!runner(myrenderer, mytext, strmultiline, myparser)) 
				{
					ImGui::OpenPopup("ThePopup");
					
				}
			}
			else if (!str.empty())
			{
				if (!runner(myrenderer, mytext, str, myparser) )
				{
					ImGui::OpenPopup("ThePopup");

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

	myparser->clearAllLists();
	try {
		myparser->splitToCommands(mystring);
		mytext = myparser->runForAll(myrenderer, mytext);
	}


	catch (InvalidParameters& e)
	{
		error = e.returnError();
		return false;
	}
	catch (nonnumberexception& e)
	{
		error = e.returnError();
		return false;
		
	}
	catch (nonfillvalue e)
	{
		error = e.returnError();
		return false;
		
	}
	catch (notcolourexception e)
	{
		error = e.returnError();
		return false;

	}
	catch (notcommandexception e)
	{
		error = e.returnError();
		return false;

	}
	
	return true;

}



