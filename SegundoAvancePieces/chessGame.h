/*
    This header file contains th ChessGame class.
    contains the whole game.
*/

#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"
using namespace std;

class ChessGame: public sf::Drawable{
protected:
    Board board;
    array<Piece, 16> whitePieces;
    array<Piece, 16> blackPieces;
    Piece* selectedPiece;
    vector<sf::RectangleShape> possibleMovesSquares;
    sf::RectangleShape selectionBorder;
    string lastMove;
    sf::RectangleShape infoRestart;

    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;

    bool selected;
    bool playerTurn; // true = White turn, false = Black Turn
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createMovesSquares();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateInfo();
    void checkMate();
    void setTarget(sf::RenderTarget& target);



public:
    ChessGame(sf::Color bordL_col, sf::Color bordD_col);

    bool getSelected(){return selected;}

    bool getMate(){return mate;}

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();


};

#endif