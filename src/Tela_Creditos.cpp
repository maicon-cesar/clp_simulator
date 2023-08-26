#include "Tela_Creditos.hpp"
#include "Application.hpp"
#include "Resources.hpp"
#include "StringUtils.hpp"


Tela_Creditos::Tela_Creditos()
{
	SetTitle("Projeto GB");

	std::wostringstream oss;

	oss << "     Universidade do Vale do Rio Dos Sinos       \n"
	    << "                           Version" << L" " << "1.0.0.0" << L"\n\n"
	    << "                      Estruturas de Dados" << L" \n"
	    << "                             Maicon Cesar" << L"\n\n"
	    << "                               CLP Virtual";


	gui::Label* about_text = new gui::Label(this, oss.str());
	about_text->setPosition(30, 100);
	about_text->setCharacterSize(30);

	gui::Button* b = new MenuButton(this, "Voltar");
	b->setPosition(210, 400);
	b->SetCallbackID(1);
}


void Tela_Creditos::EventCallback(int id)
{
	if (id == 1)
		Application::GetInstance().setTela(Application::TELA_PRINCIPAL);
}

