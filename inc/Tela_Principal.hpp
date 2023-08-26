#ifndef TELA_PRINCIPAL_HPP
#define TELA_PRINCIPAL_HPP

#include "BaseMenu.hpp"

/*
class DigitalState {
public:
	void setState(int s) { state = s; }
	int getState() { return state; }
private:
	int state;
};*/

class Tela_Principal: public BaseMenu
{
public:
	Tela_Principal();
	void Show(sf::RenderTarget& target) const;
	void Update(float frametime);
private:
	void EventCallback(int id);
	xsf::Sprite background_;
	//xsf::Sprite title_;
	xsf::Sprite imgLeds[4][2];
	xsf::Sprite imgButtons[4][2];
	sf::RectangleShape quadro;
	sf::Text text[3];
	sf::Font font;
};

#endif // TELA_PRINCIPAL_HPP

