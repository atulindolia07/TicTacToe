#include <iostream>
#include "PlayingPiece.hpp"

class PlayingPieceO : public PlayingPiece{
    public:
    PlayingPieceO():PlayingPiece(PieceType::O){}
};