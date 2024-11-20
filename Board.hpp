#include<iostream>
#include "PlayingPiece.hpp"

class Board{
    public:
    int size;
    PlayingPiece ***board;

    Board(int size){
        this->size = size;
        board = new PlayingPiece** [size];
        for(int i=0;i<size;i++){
            board[i] = new PlayingPiece*[size]();
        }
    }

    bool addPiece(int row,int col, PlayingPiece *piece){
        if(board[row][col]!=nullptr){
            return false;
        }

        board[row][col] = piece;
        return false;
    }
};