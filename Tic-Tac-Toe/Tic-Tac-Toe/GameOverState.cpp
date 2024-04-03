#include "GameOverState.h"
#include<sstream>
#include <iostream>

#include "DEFINATIONS.h"
#include "MainMenuState.h"
#include "GameState.h"


namespace arcade
{
	GameOverState::GameOverState(gameDataRef data) :_data(data)
	{

	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("RetryButton", RETRY_BUTTON_FILEPATH );
		this->_data->assets.LoadTexture("HomeButton", HOME_BUTTON_BACKGROUND_FILEPATH);


		this->_retryButton.setTexture(this->_data->assets.GetTexture("RetryButton"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("HomeButton"));

		this->_retryButton.setPosition((this->_data->window.getSize().x / 2) - (this->_retryButton.getLocalBounds().width / 2), (this->_data->window.getSize().x / 3) - (this->_retryButton.getLocalBounds().height / 2));

		this->_homeButton.setPosition((this->_data->window.getSize().x / 3 * 2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->window.getSize().x / 3) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void GameOverState::HandleInput()
	{
		sf::Event events;
		while (this->_data->window.pollEvent(events))
		{
			if (sf::Event::Closed == events.type) {
				this->_data->window.close();
			}
			if (this->_data->inputs.isSpriteClicked(_retryButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(stateRef(new GameState(_data)), true);
			}
			if (this->_data->inputs.isSpriteClicked(_homeButton, sf::Mouse::Left, this->_data->window))
			{
				//this->_data->machine.RemoveState();
				this->_data->machine.AddState(stateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(_retryButton);
		this->_data->window.draw(_homeButton);

		this->_data->window.display();

	}

}