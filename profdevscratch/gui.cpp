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
	ImGui_ImplSDL2_InitForOpenGL(mySDLWindow, gl_context);
	ImGui_ImplOpenGL3_Init("#version 450");
}
void gui::makeDefaultFrame()
{

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("Hello, world!");
	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(mySDLWindow);

}

