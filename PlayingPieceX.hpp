#include <iostream>
#include "PlayingPiece.hpp"

class PlayingPieceX : public PlayingPiece{
    public:
    PlayingPieceX():PlayingPiece(PieceType::X){}
};