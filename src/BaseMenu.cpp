#include <cassert>

#include "BaseMenu.hpp"
#include "Application.hpp"
#include "Resources.hpp"
#include "SoundSystem.hpp"


gui::WidgetStyle BaseMenu::global_style_;

BaseMenu::BaseMenu(): gui::Menu(global_style_)
{
	GetWidgetStyle().global_font = &GetMenuFont();
}


void BaseMenu::OnEvent(const sf::Event& event)
{
	// propaga eventos para o gui
	gui::Menu::OnEvent(event);
}


void BaseMenu::Update(float frametime)
{
	static const int SPEED = 30;
	static float y = 0;
	y -= SPEED * frametime;
	if (y < 0)
	{
		y = Application::HEIGHT;
	}
	scrolling_background_.setY(y);

	// update gui
	gui::Menu::Update(frametime);
}


void BaseMenu::Show(sf::RenderTarget& target) const
{
	target.draw(scrolling_background_);
	scrolling_background_.setOrigin(0.f, scrolling_background_.getHeight());
	target.draw(scrolling_background_);
	scrolling_background_.setOrigin(0.f, 0.f);

	gui::Menu::Show(target);
	target.draw(title_);
}


void BaseMenu::OnFocus()
{
	Application::GetInstance().GetApp().setMouseCursorVisible(true);
	Application::GetInstance().GetApp().setKeyRepeatEnabled(true);
}


void BaseMenu::SetTitle(const sf::String& text, int y)
{
	title_.setFont(GetMenuFont());
	title_.setCharacterSize(40);
	title_.setString(text);
	title_.setX((Application::WIDTH - title_.getWidth()) / 2);
	title_.setY(y);
}


const sf::Text& BaseMenu::GetTitle() const
{
	return title_;
}


void BaseMenu::OnWidgetFocused()
{
	SoundSystem::GetInstance().PlaySound(Resources::getSoundBuffer("res/audio/menu-select.ogg"));
}


