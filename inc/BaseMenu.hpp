#ifndef BASEMENU_HPP
#define BASEMENU_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Tela.hpp"
#include "MenuButton.hpp"
#include "ConfigButton.hpp"
#include "gui/gui.hpp"


class BaseMenu: public Tela, public gui::Menu
{
public:
	BaseMenu();
	void OnEvent(const sf::Event& event);
	void Update(float frametime);
	void Show(sf::RenderTarget& target) const;
	void OnFocus();

protected:
	void SetTitle(const sf::String& text, int y = 20);
	const sf::Text& GetTitle() const;
	void OnWidgetFocused();

private:
	xsf::Text title_;
	mutable xsf::Sprite scrolling_background_;
	static gui::WidgetStyle global_style_;
};

#endif // BASEMENU_HPP

