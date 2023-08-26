#ifndef COSMOBUTTON_HPP
#define COSMOBUTTON_HPP

#include "gui/Button.hpp"

class MenuButton: public gui::Button
{
public:
	MenuButton(gui::Menu* owner, const sf::String& text);

protected:
	void OnStateChanged(gui::State::EState state);
	void OnCallbackTriggered();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static const sf::Texture* img_;

	xsf::Sprite background_;
};

#endif // COSMOBUTTON_HPP

