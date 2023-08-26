#include "Application.hpp"
#include "Telas.hpp"
#include <iostream>
#include "BaseInfo.hpp"

Application::Application()
: input_(Input::GetInstance())
{
}

bool Application::Init()
{
	input_.Init();

	bool full = false;
	int style = full ? sf::Style::Fullscreen : sf::Style::Close;

	sf::VideoMode videoMode(Application::WIDTH, Application::HEIGHT, 32);
	app_.create(videoMode, "Projeto GB - Maicon Cesar", style);
	app_.setMouseCursorVisible(false);
	app_.clear(sf::Color(0,0,0,0));
	app_.setVerticalSyncEnabled(true);
	app_.setKeyRepeatEnabled(true);
	app_.setFramerateLimit(5000);  //30
	app_.setPosition( sf::Vector2i(sf::VideoMode::getDesktopMode().width/4 + sf::VideoMode::getDesktopMode().width/16 ,
			               sf::VideoMode::getDesktopMode().height/4 + sf::VideoMode::getDesktopMode().height/16 ) );

	for (int i = 0; i < TELA_LEN; ++i)
		telas_[i] = NULL;

	setTela(TELA_PRINCIPAL);
	running_ = true;
	return true;
}

Application::~Application()
{
	app_.close();

	for (int i = 0; i < TELA_LEN; ++i) {
		if (telas_[i] != NULL)
			delete telas_[i];
	}
}

bool Application::Run()
{
	while (app_.pollEvent(event)) {
		action = input_.EventToAction(event);
		switch (action) {
			case Input::EXIT_APP:
				Fini();
				break;
			default:
				telatual_->OnEvent(event);
				break;
		}
	}
	app_.clear();
	telatual_->Update(clock.restart().asSeconds());
	telatual_->Show(app_);
	app_.display();

	return running_;
}


void Application::setTela(eTelas tela)
{
	if (telas_[tela] == NULL) {
		Tela *telaseguinte = NULL;
		switch (tela) {
			case Application::TELA_PRINCIPAL:
				telaseguinte = new Tela_Principal();
				break;
			case Application::TELA_CREDITOS:
				telaseguinte = new Tela_Creditos();
				break;
			default:
				return;
		}
		telas_[tela] = telaseguinte;
	}
	telatual_ = telas_[tela];
	telatual_->OnFocus();
}

Application& Application::GetInstance()
{
	static Application self;
	return self;
}

sf::RenderWindow& Application::GetApp()
{
	return app_;
}

void Application::Fini()
{
	running_ = false;
}

void Application::setDisplay(int l, std::string message)
{
	message.resize(30);   //30 limite do display
	DisplayMessage[l] = message;
}

std::string Application::getDisplay(int l)
{
	return DisplayMessage[l];
}






