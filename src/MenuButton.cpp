#include "MenuButton.hpp"
#include "Resources.hpp"
#include "SoundSystem.hpp"

#define BUT_W 220
#define BUT_H 40

const sf::Texture* MenuButton::img_ = NULL;

MenuButton::MenuButton(gui::Menu* owner, const sf::String& text) :
	gui::Button(owner, text, BUT_W, BUT_H)
{
	if (img_ == NULL)
	{
		img_ = &Resources::getTexture("res/button.png");
	}

	background_.setTexture(*img_);
	background_.setTextureRect(sf::IntRect(0, 0, BUT_W, BUT_H));
	background_.resize(BUT_W, BUT_H);

	SetTextPadding(0, 8);
	SetAlign(gui::Align::CENTER);
	OnStateChanged(GetState());
}


void MenuButton::OnStateChanged(gui::State::EState state)
{
	switch (state)
	{
		case gui::State::DEFAULT:
			background_.setTextureRect(sf::IntRect(0, 0, BUT_W, BUT_H));
			break;
		case gui::State::HOVERED:
			background_.setTextureRect(sf::IntRect(0, 40, BUT_W, BUT_H));
			SoundSystem::GetInstance().PlaySound(Resources::getSoundBuffer("res/audio/menu-select.ogg"));
			break;
		case gui::State::FOCUSED:
			background_.setTextureRect(sf::IntRect(0, 80, BUT_W, BUT_H));
			break;
		default:
			break;
	}
	gui::Button::OnStateChanged(state);
}


void MenuButton::OnCallbackTriggered()
{
	//SoundSystem::GetInstance().PlaySound(Resources::getSoundBuffer("res/audio/menu-valid.ogg"));
}


void MenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(background_, states);
	target.draw((gui::Button) *this);
}
