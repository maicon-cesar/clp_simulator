#ifndef GUI_HBOXLAYOUT_HPP
#define GUI_HBOXLAYOUT_HPP

#include "Layout.hpp"

namespace gui
{

class Widget;

class HBoxLayout: public Layout
{
public:
	HBoxLayout(float x, float y);

	Widget* Add(Widget* widget);

};

}

#endif // GUI_HBOXLAYOUT_HPP
