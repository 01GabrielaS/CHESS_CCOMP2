#include "Piece_hijas.h"



void PKing::calcPossibleMoves(Piece* tmpPiece){
    int piecePos{tmpPiece->getPosition()};
    tmpPiece->getPossibleMoves().clear();

    if((piecePos / 8) != 0){
        tmpPiece->getPossibleMoves().push_back(piecePos - 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos - 9);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos - 7);
    }
    if((piecePos / 8) != 7){
        tmpPiece->getPossibleMoves().push_back(piecePos + 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos + 7);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos + 9);
    }
    if((piecePos % 8) != 0)
        tmpPiece->getPossibleMoves().push_back(piecePos - 1);
    if((piecePos % 8) != 7)
        tmpPiece->getPossibleMoves().push_back(piecePos + 1);

}



void PKnight::calcPossibleMoves(Piece* tmpPiece) {
    tmpPiece->getPossibleMoves().clear();

    int piecePos{tmpPiece->getPosition()};

    if((piecePos / 8) != 0 ){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 10);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 6);
        if((piecePos / 8) != 1){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 17);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 15);
        }
    }
    if((piecePos / 8) != 7){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 6);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 10);
        if((piecePos / 8) != 6){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 15);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 17);
        }
    }

    tmpPiece->getDangerMoves().clear();

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );

}



