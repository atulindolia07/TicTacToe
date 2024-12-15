#include<iostream>
#include "PlayingPiece.hpp"

class Player{
    public:
        std::string name;
        PlayingPiece playingPiece;

        Player(std::string name, PlayingPiece playingPiece){
            this->name = name;
            this->playingPiece = playingPiece;
        }

        void setName(std::string name){
            this->name = name;
        }

        std::string getName(){
            return this->name;
        }

        void setPlayingPiece(PlayingPiece playingPiece){
            this->playingPiece = playingPiece;
        }

        PlayingPiece getPlayingPiece(){
            return this->playingPiece;
        }
};