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
private:
    Board board;
    array<Piece, 16> whitePieces;
    array<Piece, 16> blackPieces;
    sf::RectangleShape selectionBorder;
    
    Piece* selectedPiece; //seguira la pieza seleccionada y la usaremos en todo el codigo sin necesidad de copiar toda la info de la pieza
    /*
    vector<sf::RectangleShape> possibleMovesSquares;
    string lastMove;
    */
    sf::RectangleShape infoRestart;

    sf::Font font;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;
    

    bool selected;
    bool playerTurn; // true = White , false = Black 
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createSelectSquare();
    /*
    void calcPossibleMoves();
    void calcKingMoves(Piece* tmpPiece);
    void calcQueenMoves(Piece* tmpPiece);
    void calcRookMoves(Piece* tmpPiece);
    void calcBishopMoves(Piece* tmpPiece);
    void calcKnightMoves(Piece* tmpPiece);
    void calcPawnMoves(Piece* tmpPiece);
    void calcCastling(Piece* tmpPiece);

    void eraseMoves(Piece* tmpPiece);
    */
    void checkMate();

    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    ChessGame(sf::Color bordL_col, sf::Color bordD_col);

    bool getSelected(){
        return selected;
    }

    bool getMate(){
        return mate;
    }

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();
    


};


#endif