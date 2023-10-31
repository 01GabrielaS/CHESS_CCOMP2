/*
    This code file contains member functions of chessGame.h
*/

#include "chessGame.h"


ChessGame::ChessGame(sf::Color bordL_col = sf::Color::White, sf::Color bordD_col = sf::Color::Black)
: board(bordL_col,bordD_col)
{

}


void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);

    target.draw(board); //funcion draw de board
}


