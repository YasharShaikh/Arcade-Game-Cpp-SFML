#pragma once
#include<sstream>
#include <iostream>

#include "DEFINATIONS.h"
#include "PauseState.h"
#include "MainMenuState.h"
#include "GameState.h"

namespace arcade
{
	PauseState::PauseState(gameDataRef data) :_data(data)
	{

	}
	void PauseState :: Init()
	{
		this->_data->assets.LoadTexture("pauseBackground", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("resumeButton", RESUME_BUTTON_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("homebutton", HOME_BUTTON_BACKGROUND_FILEPATH);


		this->_pauseBackground.setTexture(this->_data->assets.GetTexture("pauseBackground"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("resumeButton"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("homebutton"));

		this->_pauseButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2), (this->_data->window.getSize().x / 3) - (this->_resumeButton.getLocalBounds().height / 2));

		this->_homeButton.setPosition((this->_data->window.getSize().x / 3*2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->window.getSize().x / 3) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void PauseState::HandleInput()
	{
		sf::Event events;

		while (this->_data->window.pollEvent(events))
		{
			if (sf::Event::Closed == events.type) {
				this->_data->window.close();
			}

			if (this->_data->inputs.isSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
			}
			
			if (this->_data->inputs.isSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(stateRef(new MainMenuState(_data)), true);																									
			}
		}
	}

	void PauseState::Update(float dt)
	{

	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear();
		
		this->_data->window.draw(this->_pauseBackground);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}