#pragma once
#include <string>
#include <array> 
#include "Board.h"

struct Player{
    std::string name; 
    bool win; 
};

class TicTacToe{
    private: 
        

        Board board_;

        int pos_counter_; 
        bool finished_;
        Player player1_; 
        Player player2_;

        void turnPlayer(int numPlayer);
        //void updateStatus(); 

    public: 
        TicTacToe(std::string player1Name, std::string player2Name="computer");
        void Start();
        
        
};