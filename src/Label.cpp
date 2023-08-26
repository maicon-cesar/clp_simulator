#include "gui/Label.hpp"
#include "gui/Menu.hpp"

using namespace gui;


Label::Label(Menu* owner, const sf::String& text, int x, int y) :
	Widget(owner, false)
{
	const WidgetStyle& style = owner->GetWidgetStyle();
	text_.setString(text);
	text_.setColor(style.label_text_color);
	text_.setFont(*style.global_font);
	text_.setCharacterSize(style.global_text_size);
	text_.setPosition(0, 0);

	setPosition(x, y);
	Resize(text_.getWidth(), text_.getHeight());
}


void Label::setString(const sf::String& text)
{
	text_.setString(text);
	Resize(text_.getWidth(), text_.getHeight());
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(text_, states);
}
