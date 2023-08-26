#include <cassert>

#include "gui/TextBox.hpp"
#include "gui/Menu.hpp"

#define PADDING        3
#define OUTLINE        1
#define CURSOR_WIDTH   2
#define CURSOR_COLOR   sf::Color(64, 64, 255)
#define BLINK_PERIOD   1.f

using namespace gui;


TextBox::TextBox(Menu* owner, int x, int y, int visible_chars, int max_length):
	Widget(owner, true),
	display_text_(*owner->GetBitmapFont())
{
	visible_chars_ = visible_chars;
	max_length_ = max_length;
	left_offset_ = right_offset_ = 0;
	int height = display_text_.getFont().GetCharHeight() + PADDING * 2;
	int width = display_text_.getFont().GetCharWidth() * visible_chars + PADDING * 2;

	box_.setSize(sf::Vector2f(width, height));
	box_.setOutlineThickness(OUTLINE);
	box_.setOutlineColor(owner->GetWidgetStyle().global_border_color);

	display_text_.setPosition(PADDING, PADDING);

	cursor_.setSize(sf::Vector2f(CURSOR_WIDTH, height - PADDING * 2));
	SetCursor(0);

	setPosition(x, y);
	Resize(width, height);
	OnStateChanged(GetState());
}


void TextBox::setString(const sf::String& text)
{
	left_offset_ = 0;
	text_ = text;
	if ((int) text_.length() > max_length_)
	{
		text_.erase(max_length_);
	}

	int diff = text_.length() - visible_chars_;
	if (diff > 0)
	{
		right_offset_ = diff;
		display_text_.Clear();
		for (int i = 0; i < visible_chars_; ++i)
		{
			display_text_.AppendChar(text_[i]);
		}
	}
	else
	{
		display_text_.setString(text_);
	}
	SetCursor(0);
}


const std::string& TextBox::GetText() const
{
	return text_;
}


void TextBox::Update(float frametime)
{
	cursor_timer_ += frametime;
	if (cursor_timer_ >= BLINK_PERIOD)
	{
		cursor_timer_ = 0.f;
	}
	float alpha = 255 * cursor_timer_ / BLINK_PERIOD;
	cursor_.setFillColor(sf::Color(64, 64, 255, 255 - (int) alpha));
}


void TextBox::OnTextEntered(sf::Uint32 unicode)
{
	if (unicode >= BitmapFont::FIRST_CHAR && unicode <= BitmapFont::LAST_CHAR)
	{
		if (max_length_ == -1 || (int) text_.length() < max_length_)
		{
			display_text_.InsertChar((char) unicode, cursor_pos_);
			int position = GetRealCursorPosition();
			text_.insert(position, 1, (char) unicode);
			if (display_text_.Length() > visible_chars_)
			{
				display_text_.RemoveChar(0);
				++left_offset_;
			}
			else
			{
				SetCursor(cursor_pos_ + 1);
			}
		}
	}
}


void TextBox::OnKeyPressed(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::BackSpace:
			if (cursor_pos_ > 0)
			{
				text_.erase(GetRealCursorPosition() - 1, 1);
				display_text_.RemoveChar(cursor_pos_ - 1);
				if (left_offset_ > 0)
				{
			
					display_text_.InsertChar(text_[left_offset_ - 1], 0);
					--left_offset_;
				}
				else if (right_offset_ > 0)
				{

					display_text_.AppendChar(text_[text_.length() - right_offset_]);
					--right_offset_;
					SetCursor(cursor_pos_ - 1);
				}
				else
				{
					SetCursor(cursor_pos_ - 1);
				}
			}
			break;
		case sf::Keyboard::Delete:
			if (cursor_pos_ < display_text_.Length())
			{
				text_.erase(GetRealCursorPosition(), 1);
				display_text_.RemoveChar(cursor_pos_);
				if (right_offset_ > 0)
				{

					display_text_.AppendChar(text_[text_.length() - right_offset_]);
					--right_offset_;
				}
				else if (left_offset_ > 0)
				{
	
					display_text_.InsertChar(text_[left_offset_ - 1], 0);
					--left_offset_;
				}
			}
			break;
		case sf::Keyboard::Left:
			SetCursor(cursor_pos_ - 1);
			break;
		case sf::Keyboard::Right:
			SetCursor(cursor_pos_ + 1);
			break;
		case sf::Keyboard::Home:
			SetCursor(0);
			while (left_offset_ > 0)
			{
				ShiftLeft();
			}
			break;
		case sf::Keyboard::End:
			while (right_offset_ > 0)
			{
				ShiftRight();
			}
			SetCursor(display_text_.Length());
			break;
		case sf::Keyboard::Return:
			CallTheCallback();
			break;
		default:
			return;
	}
}


void TextBox::OnMouseClicked(int x, int y)
{
	(void) y;
	int letter_width = display_text_.getFont().GetCharWidth();
	int pos = x / letter_width;
	if (pos > display_text_.Length())
	{
		pos = display_text_.Length();
	}
//	cursor_.SetX(pos * letter_width);
	cursor_pos_ = pos;
}


void TextBox::OnStateChanged(State::EState state)
{
	const WidgetStyle& style = GetOwner()->GetWidgetStyle();
	switch (state)
	{
		case State::DEFAULT:
			cursor_.setFillColor(sf::Color(255, 255, 255, 0));
			box_.setFillColor(style.textbox_bg_color);
			break;
		case State::FOCUSED:
			cursor_.setFillColor(CURSOR_COLOR);
			box_.setFillColor(style.textbox_bg_color_focus);
			break;
		default:
			break;
	}
}


void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(box_, states);
	target.draw(display_text_, states);
	target.draw(cursor_, states);
}


void TextBox::SetCursor(int position)
{
	if (position == 1 && left_offset_ > 0)
	{
		ShiftLeft();
	}
	else if (position == visible_chars_ && right_offset_ > 0)
	{
		ShiftRight();
	}
	else if (position >= 0 && position < display_text_.Length() + 1)
	{
		cursor_timer_ = 0.f;
		cursor_pos_ = position;
		cursor_.setPosition(position * display_text_.getFont().GetCharWidth(), PADDING);
	}
}


int TextBox::GetRealCursorPosition() const
{
	return left_offset_ > 0 ? (left_offset_ + cursor_pos_) : cursor_pos_;
}


void TextBox::ShiftLeft()
{
	// ab[cdef]gh => a[bcde]fgh
	display_text_.RemoveChar(-1);
	display_text_.InsertChar(text_[left_offset_ - 1], 0);
	++right_offset_;
	--left_offset_;
}


void TextBox::ShiftRight()
{
	// ab[cdef]gh => abc[defg]h
	display_text_.RemoveChar(0);
	display_text_.AppendChar(text_[text_.length() - right_offset_]);
	--right_offset_;
	++left_offset_;
}

/*
#include <iostream>
void TextBox::Debug() const
{
	std::cout << "real text is:      '" << text_ << "' (" <<  text_.length() << ")" << std::endl;
	std::cout << "displayed text is: '" << display_text_.GetText() << "' (" << display_text_.Length() << ")" << std::endl;
	std::cout << "cursor is at pos:  " << cursor_pos_ << std::endl;
	std::cout << "left offset is:    " << left_offset_ << ", right offset is " << right_offset_ << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}*/
