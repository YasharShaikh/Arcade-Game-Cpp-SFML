#pragma once

#include<sstream>
#include <iostream>

#include "MainMenuState.h"
#include "GameState.h"
#include "DEFINATIONS.h"

namespace arcade
{
	MainMenuState::MainMenuState(gameDataRef data) : _data(data)
	{

	}
	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAINMENU_SCENE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Title", MAINMENU_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("PlayButton", MAINMENU_PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("PlayButtonOuter", MAINMENU_PLAY_BUTTON_OUTER_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_title.setTexture(this->_data->assets.GetTexture("Title"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("PlayButton"));
		this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("PlayButtonOuter"));



		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height));

		this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width), (SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height));

		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width), this->_title.getGlobalBounds().height * 0.1);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;


		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{

				this->_data->machine.AddState(stateRef(new GameState(_data)), true);

			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}
	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_playButtonOuter);
		this->_data->window.draw(this->_title);


		this->_data->window.display();
	}
}
