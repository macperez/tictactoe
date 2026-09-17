#pragma once
#include <string>
#include <array> 
#include <memory>
#include "Board.h"
#include "Player.h"



class TicTacToe{
    private: 
        

        Board board_;

        bool finished_;
        std::unique_ptr<Player> player1_;
        std::unique_ptr<Player> player2_;
        

        void updateStatus(); 

    public: 
        TicTacToe(std::string player1Name, std::string player2Name="computer");
        void Start();
        
        
    private: 
        bool checkWinner(int score);

};