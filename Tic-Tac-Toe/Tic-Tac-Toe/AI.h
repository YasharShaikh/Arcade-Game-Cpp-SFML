#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include<array>

#include "Game.h"


namespace arcade
{
	class AI
	{
	public:
		AI(int playerPiece, gameDataRef data);

		void PlacePiece(int (*gridArray)[3][3], sf::Sprite gridPieces[3][3], int *gameState);


	private:

		void CheckSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);
		void CheckifPieceisEmpty(int x, int y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

		int aiPiece;
		int playerPiece;

		std::vector<std::array<int, 6>> checkMatchVector;
		gameDataRef _data;
	};
}


