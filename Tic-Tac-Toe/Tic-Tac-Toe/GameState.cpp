#pragma once
#include "GameState.h"

#include<sstream>
#include <iostream>

#include "MainMenuState.h"
#include "PauseState.h"
#include "GameState.h"
#include "InputManager.h"
#include "GameOverState.h"
#include "DEFINATIONS.h"

namespace arcade
{
	GameState::GameState(gameDataRef data) :_data(data)
	{

	}
	void GameState::Init()
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;


		this->ai = new AI(turn, this->_data);

		this->_data->assets.LoadTexture("gameBackground", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("pauseButton", PAUSE_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("gridSprite", GAME_GRID_FILEPATH);
		this->_data->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("X Win Piece", X_WIN_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Win Piece", O_WIN_PIECE_FILEPATH);




		_gameBackground.setTexture(this->_data->assets.GetTexture("gameBackground"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("pauseButton"));
		_gridSprite.setTexture(this->_data->assets.GetTexture("gridSprite"));


		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
		_gridSprite.setPosition((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));


		InitGridPieces();

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				gridArray[x][y] = EMPTY_PIECE;
			}
		}
	}

	void GameState::HandleInput()
	{
		sf::Event event;


		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->inputs.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(stateRef(new PauseState(_data)), false);
				std::cout << "Pause game screen";
			}
			else if (this->_data->inputs.isSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->window))
			{
				if (STATE_PLAYING == gameState)
				{
					this->CheckandPlacePiece();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			if (this->_clock.getElapsedTime().asSeconds()>TIME_BEFORE_SHOWING_GAME_OVER)
			{
				this->_data->machine.AddState(stateRef(new GameOverState(_data)), true);
			}
		}
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();


		this->_data->window.draw(this->_gameBackground);
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.draw(this->_gridSprite);

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->_data->window.draw(this->_gridPieces[x][y]);

			}
		}


		this->_data->window.display();

	}

	void GameState::InitGridPieces()
	{
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X Piece").getSize();
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X Piece"));
				_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7, _gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
				_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}
	void GameState::CheckandPlacePiece()
	{
		sf::Vector2i touchPoint = this->_data->inputs.GetMousePosition(this->_data->window);
		sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
		sf::Vector2f gapOutsideofGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2); // Changed SCREEN_WIDTH to SCREEN_HEIGHT
		sf::Vector2f gridLocalTouchPos = sf::Vector2f((touchPoint.x - gapOutsideofGrid.x), (touchPoint.y - gapOutsideofGrid.y));
		sf::Vector2f gridSectionSize = sf::Vector2f((gridSize.width / 3), (gridSize.height / 3));
		int column = 0, row = 0; // Initialized column and row variables

		if (gridLocalTouchPos.x < gridSectionSize.x)
		{
			column = 1;
		}
		else if (gridLocalTouchPos.x < gridSectionSize.x * 2)
		{
			column = 2;
		}
		else if (gridLocalTouchPos.x < gridSize.width)
		{
			column = 3;
		}

		if (gridLocalTouchPos.y < gridSectionSize.y)
		{
			row = 1;
		}
		else if (gridLocalTouchPos.y < gridSectionSize.y * 2)
		{
			row = 2;
		}
		else if (gridLocalTouchPos.y < gridSize.height)
		{
			row = 3;
		}

		if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
		{
			gridArray[column - 1][row - 1] = turn;
			if (PLAYER_PIECE == turn)
			{
				_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("X Piece"));
				this->CheckPlayerWon(turn);
				//turn = AI_PIECE;

			}/*
			else if (AI_PIECE == turn)
			{
				_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("O Piece"));
				this->CheckPlayerWon(turn);
				turn = PLAYER_PIECE;
			}*/


			_gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
		}
	}

	void GameState::CheckPlayerWon(int player)
	{

		Check3PieceforMatch(0, 0, 1, 0, 2, 0, player);
		Check3PieceforMatch(0, 1, 1, 1, 2, 1, player);
		Check3PieceforMatch(0, 2, 1, 2, 2, 2, player);
		Check3PieceforMatch(0, 0, 0, 1, 0, 2, player);
		Check3PieceforMatch(1, 0, 1, 1, 1, 2, player);
		Check3PieceforMatch(2, 0, 2, 1, 2, 2, player);
		Check3PieceforMatch(0, 0, 1, 1, 2, 2, player);
		Check3PieceforMatch(0, 2, 1, 1, 2, 0, player);

		if (STATE_WON != gameState)
		{
			gameState = STATE_AI_PLAYING;

			ai->PlacePiece(&gridArray, _gridPieces, &gameState);
			Check3PieceforMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
			Check3PieceforMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
			Check3PieceforMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
			Check3PieceforMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
			Check3PieceforMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
			Check3PieceforMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
			Check3PieceforMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
			Check3PieceforMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
		}

		int emptyNum = 9;

		for (int x = 0;x<3;x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (EMPTY_PIECE != gridArray[x][y])
				{
					emptyNum--;

				}
			}
		}
		if (0 == emptyNum && (STATE_WON != gameState) && (STATE_LOSE != gameState))
		{
			gameState = STATE_DRAW;
		}
		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			this->_clock.restart();
		}
		std::cout << gameState << std::endl;
	}

	void GameState::Check3PieceforMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		if (pieceToCheck == gridArray[x1][y1] && pieceToCheck == gridArray[x2][y2] && pieceToCheck == gridArray[x3][y3])
		{
			std::string winningPieceStr;

			if (O_PIECE == pieceToCheck)
			{
				winningPieceStr = "O Win Piece";
			}
			else
			{
				winningPieceStr = "X Win Piece";
			}

			_gridPieces[x1][y1].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x2][y2].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x3][y3].setTexture(this->_data->assets.GetTexture(winningPieceStr));

			if (PLAYER_PIECE == pieceToCheck)
			{
				gameState = STATE_WON;
			}
			else
			{
				gameState = STATE_LOSE;
			}
		}
	}
	
	
}


