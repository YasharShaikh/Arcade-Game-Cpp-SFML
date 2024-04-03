#include "Game.h"
#include "SplashState.h"

namespace arcade
{
	Game::Game(int width, int height, std::string Title)
	{
		_data->window.create(sf::VideoMode(width, height), Title, sf::Style::Close | sf::Style::Titlebar);

		_data->machine.AddState(stateRef(new SplashState(this->_data)));

		this->Run();
	}
	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;
		
		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime-currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;


			while (accumulator>=dt)
			{
				this->_data->machine.getActiveState()->HandleInput();
				this->_data->machine.getActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->Draw(interpolation);
		}

	}
}