#include <iostream>
#include "Player.cpp"
#include "Board.cpp"
#include "PlayingPiece.hpp"
#include "PlayingPieceO.hpp"
#include "PlayingPieceX.hpp"
#include <deque>
#include <vector>
#include <boost/algorithm/string.hpp>

class TicTacToe{
    public:
        std::deque<Player> players;
        Board *gameBoard;

        ~TicTacToe(){
            delete gameBoard;
        }

        void initializeGame(){
            PlayingPieceO noughtsPiece;
            PlayingPieceX crossPiece;

            Player player1("Atul",crossPiece);
            Player player2("Tushar",noughtsPiece);

            players.push_back(player1);
            players.push_back(player2);

            //initialize board
            gameBoard = new Board(3);
        }

        std::string startGame(){
            bool noWinner = true;

            while(noWinner){
                Player playerTurn = players.front();
                players.pop_front();

                gameBoard->printBoard();

                std::list<std::pair<int,int>> emptyCells = gameBoard->getFreeCells();

                if(emptyCells.empty()){
                    noWinner = false;
                    continue;
                }

                //Take input
                std::cout<<"Player "<<playerTurn.name<<" Enter row,column : ";
                std::string position;
                std::cin>>position;
                std::vector<std::string> values;
                boost::split(values, position, boost::is_any_of(","));
                int inputRow = std::stoi(values[0]);
                int inputColumn = std::stoi(values[1]);


                //place the piece 
                bool isPiecePlacedSuccessfully = gameBoard->addPiece(inputRow,inputColumn,playerTurn.playingPiece);
                if(!isPiecePlacedSuccessfully){
                    std::cout<<"Incorrect Position, Please enter correct position!"<<std::endl;
                    players.push_front(playerTurn);
                    continue;
                }

                players.push_back(playerTurn);

                bool winner = isThereWinner(inputRow, inputColumn, playerTurn.playingPiece.pieceType);
                if(winner) {
                    return playerTurn.name;
                }
            }

            //tie
            return "tie";
        }

        bool isThereWinner(int row,int col,PieceType pieceType){
            bool rowMatch = true;
            bool columnMatch = true;
            bool diagonalMatch = true;
            bool antiDiagonalMatch = true;

            //need to check in row
            for(int i=0;i<gameBoard.size;i++) {

                if((gameBoard.board[row][i] !=1 && gameBoard.board[row][i] !=2) || gameBoard.board[row][i].pieceType != pieceType) {
                    rowMatch = false;
                }
            }

            //need to check in column
            for(int i=0;i<gameBoard.size;i++) {

                if((gameBoard.board[i][col] !=1 && gameBoard.board[i][col] !=2) || gameBoard.board[i][col].pieceType != pieceType) {
                    columnMatch = false;
                }
            }

            //need to check diagonals
            for(int i=0, j=0; i<gameBoard.size;i++,j++) {
                if if((gameBoard.board[i][j] !=1 && gameBoard.board[i][j] !=2) || gameBoard.board[i][j].pieceType != pieceType) {
                    diagonalMatch = false;
                }
            }

            //need to check anti diagonals
            for(int i=0, j=gameBoard.size-1; i<gameBoard.size;i++,j--) {
                if if((gameBoard.board[i][j] !=1 && gameBoard.board[i][j] !=2) || gameBoard.board[i][j].pieceType != pieceType) {
                    antiDiagonalMatch = false;
                }
            }

            return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
        }


};