#pragma once
#include <string>
#include <array> 
#include "Board.h"
#include "Player.h"


class TicTacToe{
    private: 
        
        Board board_; 

        int pos_counter_; 
        bool finished_;
        Player player1_; 
        Player player2_;
        
        void updateStatus(); 

    public: 
        TicTacToe(std::string player1Name, std::string player2Name="computer", int size);
        void Start();
        
};