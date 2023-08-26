#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Input.hpp"
#include "Tela.hpp"


class DigitalState {
public:
        void setState(int s) { state = s; }
        int getState() { return state; }
private:
        int state;
};

class Application
{
public:
	sf::Event event;

	Input::Action action;
	sf::Clock clock;

	enum eTelas {
		TELA_PRINCIPAL,
		TELA_CREDITOS,
		TELA_LEN
	};

	enum Size {
		WIDTH =  640,
		HEIGHT = 480
	};

	bool Init();
	bool Run(void);
	void Fini();

	void setTela(eTelas tela);

	static Application& GetInstance();
	sf::RenderWindow& GetApp();

        int getStateButton(int b) { return button[b].getState(); }
	int getStateLed(int l) { return led[l].getState(); }
	void setStateButton(int b, int s) { button[b].setState(s); }
        void setStateLed(int l, int s) { led[l].setState(s); }

        void setDisplay(int l, std::string message);
	std::string getDisplay(int l);
private:
	Application();		//singleton
	~Application();
	sf::RenderWindow app_;
	bool running_;

	// event manager
	Input& input_;

	Tela* telas_[TELA_LEN];
	Tela* telatual_;

	DigitalState button[4];
	DigitalState led[4];
	std::string DisplayMessage[3];
};

#endif // APPLICATION_HPP_INCLUDED

