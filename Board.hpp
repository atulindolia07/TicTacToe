#include <iostream>
#include "PlayingPiece.hpp"
#include <vector>
#include <list>

class Board{
    public:
    int size;
    std::vector<std::vector<PlayingPiece>> board;

    Board(int size) : size(size),board(size,std::vector<PlayingPiece>(size)){}

    bool addPiece(int row,int col, PlayingPiece piece){
        if(board[row][col].pieceType==1 || board[row][col].pieceType==2) return false;

        board[row][col] = piece;
        return true;
    }

    std::list<std::pair<int,int>> getFreeCells(){
        std::list<std::pair<int,int>> freeCells;

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j].pieceType!=1 && board[i][j].pieceType!=2) freeCells.push_back({i,j});
            }
        }
        
    }

    void printBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j].pieceType==1) std::cout<<" X ";
                else if(board[i][j].pieceType==2) std::cout<<" O ";
                else std::cout<<"   ";

                std::cout<<" | ";
            }
            std::cout<<std::endl;
        }
    }


};