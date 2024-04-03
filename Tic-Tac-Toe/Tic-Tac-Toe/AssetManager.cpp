#include "AssetManager.h"


namespace arcade
{
	void AssetManager::LoadTexture(std::string name, std::string filename)
	{
		sf::Texture text;


		if (text.loadFromFile(filename))
		{
			this->_texture[name] = text;

		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_texture.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string filename)
	{
		sf::Font font;


		if (font.loadFromFile(filename))
		{
			this->_fonts[name] = font;

		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}