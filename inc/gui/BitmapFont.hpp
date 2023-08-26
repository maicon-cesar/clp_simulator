#ifndef GUI_BITMAPFONT_HPP
#define GUI_BITMAPFONT_HPP

#include <SFML/Graphics.hpp>

namespace gui
{

class BitmapFont
{
public:
	enum
	{
		FIRST_CHAR = 32, LAST_CHAR = 126
	};

	/**
	 * @param image: chemin image de la police bitmap
	 * @param width: nombre de caractères en largeur
	 * @param height: nombre de caractère en hauteur
	 */
	BitmapFont(const sf::Texture& image, int width, int height);

	/**
	 * Changer l'image de la police
	 */
	bool setTexture(const sf::Texture& image);

	/**
	 * Récupérer l'image en cours d'utilisation
	 */
	const sf::Texture& getTexture() const;

	/**
	 * Obtenir le subrect d'un caractère
	 * @param character: caractère demandé
	 * @return subrect dans l'image de la police
	 */
	sf::IntRect GetCharRect(char character) const;

	/**
	 * Largeur d'un caractère
	 */
	int GetCharWidth() const;

	/**
	 * Hauteur d'un caractère
	 */
	int GetCharHeight() const;

private:
	const sf::Texture* m_texture;
	int width_;
	int height_;
	int char_width_;
	int char_height_;
};

}

#endif // GUI_BITMAPFONT_HPP

