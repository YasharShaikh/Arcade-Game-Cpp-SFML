#pragma once
#include<memory>
#include<string>
#include<SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace arcade
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager inputs;


	};
	typedef std::shared_ptr<GameData> gameDataRef;



	class Game
	{
	public:

		Game(int width, int height, std::string Title);


	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		gameDataRef _data = std::make_shared<GameData>();


		void Run();


	};
}

