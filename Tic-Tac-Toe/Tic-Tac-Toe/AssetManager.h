#pragma once

#include <map>
#include <SFML/Graphics.hpp>


namespace arcade
{
	class AssetManager
	{
	public:
		AssetManager() {};
		~AssetManager() {};

		void LoadTexture(std::string name, std::string filename);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string filename);
		sf::Font &GetFont(std::string name);


	private:
		std::map<std::string, sf::Texture> _texture;
		std::map<std::string, sf::Font> _fonts;
	};

}

