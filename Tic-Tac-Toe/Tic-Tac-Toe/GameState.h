#pragma once

#include<SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "AI.h"
namespace arcade
{
	class GameState : public State
	{
	public:
		GameState(gameDataRef data);


		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:

		void InitGridPieces();
		void CheckandPlacePiece();
		void CheckPlayerWon(int turn);
		void Check3PieceforMatch(int x1,int y1, int x2,int y2, int x3, int y3, int pieceToCheck);

		gameDataRef _data;

		sf::Sprite _gameBackground;
		sf::Sprite _gridSprite;
		sf::Sprite _pauseButton;
		sf::Sprite _gridPieces[3][3];
		sf::Clock _clock;


		int gridArray[3][3];
		int turn;
		int gameState;


		AI* ai;



	};
}



