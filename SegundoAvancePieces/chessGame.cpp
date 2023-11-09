/*
    This code file contains member functions of chessGame.h
*/

#include "chessGame.h"
 

ChessGame::ChessGame(sf::Color bordL_col = sf::Color::White, sf::Color bordD_col = sf::Color::Black)
: board(bordL_col,bordD_col)
{   
    Piece::loadTextures();
    restart();
}


void ChessGame::restart(){

    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false;
    turn = 1;
    //PIEZAS DE LAS FILAS INFERIOR Y SUPERIOR DEL TABLERO
    blackPieces[0].setPiece('R', false, 7);
    blackPieces[1].setPiece('N', false, 6);
    blackPieces[2].setPiece('B', false, 5);
    blackPieces[3].setPiece('K', false, 4);
    blackPieces[4].setPiece('Q', false, 3);
    blackPieces[5].setPiece('B', false, 2);
    blackPieces[6].setPiece('N', false, 1);
    blackPieces[7].setPiece('R', false, 0);

    whitePieces[0].setPiece('R', true, 56); 
    whitePieces[1].setPiece('N', true, 57); 
    whitePieces[2].setPiece('B', true, 58); 
    whitePieces[3].setPiece('Q', true, 59); 
    whitePieces[4].setPiece('K', true, 60); 
    whitePieces[5].setPiece('B', true, 61); 
    whitePieces[6].setPiece('N', true, 62); 
    whitePieces[7].setPiece('R', true, 63); 

    //PEONES
    for(int i=8;i<16;i++){
        whitePieces[i].setPiece('P', true, 48 +(i-8));
        blackPieces[i].setPiece('P', false, 15 - (i-8) );
    }

    textLastMove.setString(" ");

}

void ChessGame::updateInfo(){
    textTurn.setString("Turn: " + std::to_string(turn));
    textLastMove.setString(lastMove);

    if(!mate){
        if(playerTurn)
            textSituation.setString("White's Turn");
        else
            textSituation.setString("Blacks's Turn");

        if(playerTurnCheck)
            textSituation.setString(textSituation.getString() + "\nCheck");
    }
    else{
        if(playerTurnCheck){
            if(playerTurn)
                textSituation.setString("CHECKMATE\nBlack Wins");
            else
                textSituation.setString("CHECKMATE\nWhite Wins");
        }
        else{
            textSituation.setString("STALEMATE\nIts a DRAW");
        }

    }
}


void ChessGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);

    target.draw(board); //funcion draw de board


    for(int i=0;i<16;i++){
        target.draw(whitePieces[i]);
        target.draw(blackPieces[i]);
    }

    if (selectedPiece != NULL && selected) {
        target.draw(selectionBorder);
    }
}



bool ChessGame::selectPiece(int pos){

    for(int i=0; i<16; i++){
        if(playerTurn){ // If white turn
            if(whitePieces[i].getPosition() == pos){
                selectedPiece = &whitePieces[i];
                selected = true;
                break;
            }
        }
        else{ // If black turn
            if(blackPieces[i].getPosition() == pos){
                selectedPiece = &blackPieces[i];
                selected = true;
                break;
            }
        }
        selected = false;
    }

    if(!selected){
        selectedPiece = NULL;
        return selected;
    }
    createMovesSquares();

    return selected;
}

void ChessGame::createMovesSquares() {
    if(selectedPiece == NULL)
        return;

    selectionBorder.setSize(sf::Vector2f(64, 64)); // Tamaño del cuadro
    selectionBorder.setFillColor(sf::Color::Transparent); // Sin relleno
    selectionBorder.setOutlineColor(sf::Color::Yellow); // Contorno rojo
    selectionBorder.setOutlineThickness(-3.f); // Grosor del contorno
    int x = (selectedPiece->getPosition() % 8) * 64;
    int y = (selectedPiece->getPosition() / 8) * 64;
    selectionBorder.setPosition(x,y);

}


void ChessGame::moveSelected(int pos){
    selectedPiece->setPosition(pos);

    for(int i=0; i<16; i++){
        if(selectedPiece->getPlayer()){
            if(blackPieces[i].getPosition() == pos){
                blackPieces[i].setPosition(-1);
                break;
            }
        }
        else{
            if(whitePieces[i].getPosition() == pos){
                whitePieces[i].setPosition(-1);
                break;
            }
        }
    }

    playerTurn = !playerTurn;

    selectedPiece = NULL;
    selected = false;

}
