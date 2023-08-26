#include "Tela_Principal.hpp"
#include "Application.hpp"
#include "Resources.hpp"

Tela_Principal::Tela_Principal()
{
	background_.setTexture(Resources::getTexture("res/background_.jpg"));
	font.loadFromFile("res/fixedsys.ttf");

	float y = 52;
	for (int i=0; i < 3; i++, y+=40) {
		text[i].setFont(font);
		text[i].setCharacterSize(30);
		text[i].setColor(sf::Color::Black);
		text[i].setPosition(60, y);
	}

	quadro.setSize(sf::Vector2f(530, 130));
        quadro.setOutlineColor(sf::Color(0xFF, 0xFF, 0xFF, 200));
        quadro.setOutlineThickness(4);
        quadro.setFillColor(sf::Color(53, 138, 0, 255));
        quadro.setPosition(50, 50);

	float x = 50;
	for (int i=0; i < 4; i++) {
                imgLeds[i][0].setTexture(Resources::getTexture("res/ledoff.png"));
                imgLeds[i][1].setTexture(Resources::getTexture("res/ledon.png"));
                imgLeds[i][0].setScale(0.8f, 0.8f);
                imgLeds[i][0].setPosition(x, 230);
	        imgLeds[i][1].setScale(0.8f, 0.8f);
                imgLeds[i][1].setPosition(x, 230);
		x += 150;
        }

	x = 45;
	for (int i=0; i < 4; i++) {
                imgButtons[i][0].setTexture(Resources::getTexture("res/botaooff.png"));
                imgButtons[i][1].setTexture(Resources::getTexture("res/botaoon.png"));
                imgButtons[i][0].setScale(0.8f, 0.8f);
                imgButtons[i][0].setPosition(x, 330);
	        imgButtons[i][1].setScale(0.8f, 0.8f);
                imgButtons[i][1].setPosition(x, 330);
		x += 150;
        }

        gui::HBoxLayout layout1(30, 350);
	layout1.SetSpacing(35, 0);
        layout1.Add(new ConfigButton(this, "Button1"))->SetCallbackID(1);
        layout1.Add(new ConfigButton(this, "Button2"))->SetCallbackID(2);
        layout1.Add(new ConfigButton(this, "Button3"))->SetCallbackID(3);
        layout1.Add(new ConfigButton(this, "Button4"))->SetCallbackID(4);

        gui::HBoxLayout layout2(30, 385);
        layout2.SetSpacing(35, 0);
        layout2.Add(new ConfigButton(this, "Button1"))->SetCallbackID(5);
        layout2.Add(new ConfigButton(this, "Button2"))->SetCallbackID(6);
        layout2.Add(new ConfigButton(this, "Button3"))->SetCallbackID(7);
        layout2.Add(new ConfigButton(this, "Button4"))->SetCallbackID(8);

	ConfigButton *b = new ConfigButton(this, "About...");
	b->setPosition(0, 0);
	b->SetCallbackID(10);
}

void Tela_Principal::Update(float frametime)
{
	(void)frametime;
	Application& InterfaceCLP = Application::GetInstance();
	for (int i=0; i < 3; i++)
		text[i].setString(InterfaceCLP.getDisplay(i));
}

void Tela_Principal::Show(sf::RenderTarget& target) const
{
	Application& InterfaceCLP = Application::GetInstance();

	target.draw(background_);
	BaseMenu::Show(target);
	target.draw(quadro);
	for (int i=0; i < 4; i++) {
		target.draw(imgLeds[i][InterfaceCLP.getStateLed(i)]);
		target.draw(imgButtons[i][InterfaceCLP.getStateButton(i)]);
	}

	for (int i=0; i < 3; i++) {
		target.draw(text[i]);
	}
}


void Tela_Principal::EventCallback(int id)
{
	Application& InterfaceCLP = Application::GetInstance();

	switch (id) {
	case 1:
	case 2:
	case 3:
	case 4:
		InterfaceCLP.setStateButton(id-1, 1);
		break;
	case 5:
	case 6:
	case 7:
	case 8:
		InterfaceCLP.setStateButton(id-5, 0);
		break;
	case 10:
		InterfaceCLP.setTela(Application::TELA_CREDITOS);
		break;
	}
}
