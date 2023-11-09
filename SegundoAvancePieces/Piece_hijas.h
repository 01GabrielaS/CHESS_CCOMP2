//
// Created by GABRIELA on 08/11/2023.
//

#ifndef PIECEHIJAS_H
#define PIECEHIJAS_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "piece.h"
#include "board.h"
#include "chessGame.h"

using namespace std;

class PKing:public Piece{
public:
    PKing(char type='P', bool player=true, int pos=-1, bool moved=false)
        :Piece(type,player,pos, moved){
    }

    void calcPossibleMoves(Piece* tmpPiece)override;

};

class PKnight:public Piece{
public:
    PKnight(char type = 'N', bool player = true, int pos = -1, bool moved = false)
            : Piece(type, player, pos, moved) {
    }
    void calcPossibleMoves(Piece* tmpPiece)override;
};


#endif
