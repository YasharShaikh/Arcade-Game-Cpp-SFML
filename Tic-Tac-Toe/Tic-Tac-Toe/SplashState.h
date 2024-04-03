#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


namespace arcade
{
	class SplashState : public State
	{
	public:
		SplashState(gameDataRef data);

		void Init();
		
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef _data;
		sf::Clock _clock; // check how long the game has been running


		sf::Sprite _background;

	};
}

