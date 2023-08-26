#include "gui/layouts/HBoxLayout.hpp"
#include "gui/Widget.hpp"

using namespace gui;


HBoxLayout::HBoxLayout(float x, float y): Layout(x, y)
{
}


Widget* HBoxLayout::Add(Widget* widget)
{
	sf::Vector2f pos = GetOffset();
	widget->setPosition(pos);
	pos.x += widget->GetHeight() + GetSpacing().x + 90;
	SetOffset(pos.x, pos.y);
	widget->SetVisible(false);
	return widget;
}
