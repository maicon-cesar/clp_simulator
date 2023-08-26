#ifndef TELA_HPP
#define TELA_HPP

#include <SFML/Graphics.hpp>
#include "Resources.hpp"


class Tela
{
public:
	virtual void OnEvent(const sf::Event& event) = 0;
	virtual void Update(float frametime) { (void) frametime; }
	virtual void Show(sf::RenderTarget& target) const = 0;
	virtual void OnFocus() {}
	virtual ~Tela() {}

protected:
	inline const sf::Font& GetMenuFont() const {return Resources::getFont("res/Ubuntu-R.ttf");}
};

#endif // TELA_HPP
