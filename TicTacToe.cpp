#include <iostream>
#include <array>
#include <limits>
#include <numeric>
#include "TicTacToe.h"



TicTacToe::TicTacToe(std::string player1Name, std::string player2Name)
{
    player1_ = std::make_unique<HumanPlayer>(player1Name, 1);
    player2_ = std::make_unique<HumanPlayer>(player2Name, 2);
    finished_ = false; 
    
}





bool TicTacToe::checkWinner(int score)
{
    if (score == 3)
    {
        player1_->MakeWinner();
        return true;
    }

    if (score == -3)
    {
        player2_->MakeWinner();
        return true;
    }

    return false;
}


void TicTacToe::updateStatus(){

    // check if any movement if possible 

    if (board_.isCompleted())
    {
        finished_ = true; 
        return;
    }

    if (checkWinner(board_.evalRows()) || checkWinner(board_.evalCols()) || 
        checkWinner(board_.evalMainDiag()) || checkWinner(board_.evalSecondDiag()))
    {
        finished_ = true;
        return;
    }

}



void TicTacToe::Start() { 
    std::cout << "Starting game...\n";

    board_.ShowGrid();

    //game loop 
    
    
    while (true){    
        player1_ ->Play(board_);
        
        board_.ShowGrid();
        
        updateStatus();
        
        if (finished_)
            break; 
        
        player2_->Play(board_);
        
        board_.ShowGrid();
        
        updateStatus();
        if (finished_)
            break; 
    }

    if (player1_->IsWinner())
        std::cout << "\n\n" << player1_ ->GetName() << " (player 1) has won!!\n";
    else if (player2_-> IsWinner())
        std::cout << "\n\n" << player2_ -> GetName() << " (player 2) has won!!\n";
    else
        std::cout << "\n\nDRAW!!\n";
    
}
