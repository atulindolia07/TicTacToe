#include<iostream>
#include "PieceType.hpp"

class PlayingPiece {
    public:
    PieceType pieceType;

    PlayingPiece(PieceType pieceType){
        this->pieceType = pieceType;
    }
};
