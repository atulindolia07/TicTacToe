#include<iostream>
#include "TicTacToeGame.cpp"

int main(){
    TicTacToe game;
    game.initializeGame();
    std::cout<<"Game winner is "<<game.startGame()<<std::endl;
    return 0;
}
