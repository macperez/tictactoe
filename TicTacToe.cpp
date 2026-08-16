#include <iostream>
#include "TicTacToe.h"



TicTacToe::TicTacToe( int size, std::string player1Name, std::string player2Name):
    board_(size)
{
        
        finished_ = false;
        player1_ = std::make_unique<HumanPlayer>(player1Name, 1);  

        std::cout << "Es el humano  " << player2Name << std::endl;
        player2_ =  std::make_unique<HumanPlayer>(player2Name, 2);  
        
        /*
        if (player2Name == "computer"){   
            std::cout << "Es la computadora" << std::endl;
            player2_ =  std::make_unique<ComputerPlayer>(player2Name, 2);  
        }
        else {
            std::cout << "Es el humano  " << player2Name << std::endl;
            player2_ =  std::make_unique<HumanPlayer>(player2Name, 2);  
        
        }
        */
}


void TicTacToe::updateStatus(){

}


void TicTacToe::Start() {
    std::cout << " Starting game" << std::endl;
    
    board_.Show();
    // game loop 
    while (true){
        player1_-> Play(board_);
        board_.Show();
        // update status game 
        updateStatus();
        if (finished_)
            break; 
        
        player2_ -> Play(board_);
        board_.Show();
        // update status game 
        updateStatus();
        if (finished_)
            break; 
        


    }
}