#pragma once
#include <string>
#include <memory>
#include "Board.h"
#include "Player.h"


class TicTacToe{
    private: 
        Board board_;

        int lineLength_; 
            
        bool finished_;
        std::unique_ptr <Player> player1_; 
        std::unique_ptr <Player> player2_; 
            

        void updateStatus(); 

    public: 
        TicTacToe(int size, int lineLength, std::string player1Name, std::string player2Name="computer");
        void Start();
        void StartTest();
        

};
