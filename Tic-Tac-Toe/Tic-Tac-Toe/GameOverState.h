#pragma once
#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace arcade
{
	class GameOverState : public State
	{
	public:
		GameOverState(gameDataRef data);


		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;

		
	};

}

