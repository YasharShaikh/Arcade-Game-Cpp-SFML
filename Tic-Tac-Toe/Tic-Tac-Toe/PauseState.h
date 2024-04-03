#pragma once

#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace arcade
{
	class PauseState : public State
	{
	public:
		PauseState(gameDataRef data);


		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		gameDataRef _data;
		sf::Sprite _pauseBackground;

		sf::Sprite _pauseButton;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}


