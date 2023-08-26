#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <string>
#include <map>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Resources
{
public:
	static void setDataPath(const std::string& path);
	static const std::string& getDataPath();

	static sf::Texture& getTexture(const std::string& name);

	static sf::Font& getFont(const std::string& name);

	static sf::SoundBuffer& getSoundBuffer(const std::string& name);

private:
	static std::string m_path;

	typedef std::map<std::string, sf::Texture> TextureMap;
	static TextureMap m_textures;

	typedef std::map<std::string, sf::Font> FontMap;
	static FontMap m_fonts;

	typedef std::map<std::string, sf::SoundBuffer> SoundMap;
	static SoundMap m_sounds;
};

#endif // RESOURCES_HPP

