#include <iostream>
#include "TicTacToe.h"



TicTacToe::TicTacToe( int size, int lineLength, std::string player1Name, std::string player2Name):
    board_(size), lineLength_(lineLength)
{
        
        finished_ = false;
        player1_ = std::make_unique<HumanPlayer>(player1Name, 1);  

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
    
    int val; 

    if (board_.IsComplete()){
        finished_ = true; 
        return; 
    }

    val = board_.CheckRows(lineLength_);

    if (val == -lineLength_)
        player1_ -> MakeWinner(); 
    else if (val == lineLength_)
        player2_ -> MakeWinner();
    
    if (player1_ -> IsWinner() || player2_ -> IsWinner()){
        finished_ = true; 
        return; 
    }
        

    val = board_.CheckCols(lineLength_);




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


 void PrintLine(std::vector<int>const& line){
    for(const int & val: line)
        std::cout << val <<" ";
    std::cout << std::endl;
    
}



void TicTacToe :: StartTest(){ 
        // set some points
        board_.setCoordinates(1 , 1,-1);
        board_.setCoordinates(1 , 2, -1);
        board_.setCoordinates(1 , 3, -1);

        board_.setCoordinates(1 , 0, 1);
        board_.setCoordinates(2 , 0, 1);
        board_.setCoordinates(3 , 0, 1);


        board_.setCoordinates(0 , 2, -1);
        board_.setCoordinates(1 , 1, -1);
        board_.setCoordinates(2 , 0, -1);


        board_.Show();

        int val = board_.CheckRows(3); 
        std::cout << "val = " << val << std::endl; 

        val = board_.CheckCols(3);
        std::cout << "val = " << val << std::endl; 

        val = board_.CheckCols(3);
        std::cout << "val = " << val << std::endl; 
    
        std::cout << "chequeando secundarias \n" << std::endl; 
        val = board_.CheckSecondaryDiagonals(3);
        //auto values = board_.getAxis(0, 2, Direction::SECONDARY_DIAGONAL);
        //PrintLine(values);

        std::cout << "val = " << val << std::endl; 

   
   
}

