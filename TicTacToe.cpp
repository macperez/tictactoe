#include <iostream>
#include <array>
#include <limits>
#include <numeric>
#include "TicTacToe.h"



TicTacToe::TicTacToe(std::string player1Name, std::string player2Name)
{
    player1_ = {player1Name, false};
    player2_ = {player2Name, false};
    pos_counter_ = 0;
    finished_ = false; 
    
}



void TicTacToe::turnPlayer(int numPlayer){
    std::string name = numPlayer == 1 ? player1_.name:player2_.name;
    int row, col;
    std::cout << "\nPlayer " << numPlayer << "(" << name << ") turn. Coordinates?\n";
    
    bool valid = false; 
    
    while (true){
        if (std::cin >> row >> col && board_.validCoordinates(row, col))
            break;
        std::cout << "Please enter valid row<space>col, (1-3) (1-3) Ex: 1 4\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        
    // FIXME: set & get methods 
    // grid_[--row][--col] = numPlayer == 1 ? 1 :-1;
    pos_counter_++;
}

/*
void TicTacToe::updateStatus(){

    // check if any movement if possible 
    if (pos_counter_ == 9){
        finished_ = true; 
        return;
    }
        
    // check rows
    int s = 0;
    for(const std::array<int, 3> & row: grid_){
        s = accumulate(row.begin(), row.end(), 0);
        if (s >= 3 ||s <= -3)
            break; 
    }
    player1_.win = s == 3;
    player2_.win = s == -3;
    if (player1_.win || player2_.win){
        finished_ = true; 
        return; 
    }; 
    

    // check cols
    for(int col = 0; col < 3; col++){
        s = 0;
        for (int row = 0; row < 3; row++)
            s += grid_[row][col]; 

        if (s >= 3 ||s <= -3)
            break; 
    }
    player1_.win = s == 3;
    player2_.win = s == -3;
    if (player1_.win || player2_.win){
        finished_ = true; 
        return; 
    }; 
    
    // check main diagonal
    s = grid_[0][0] + grid_[1][1] + grid_[2][2];
    player1_.win = s == 3;
    player2_.win = s == -3;
    if (player1_.win || player2_.win){
        finished_ = true; 
        return; 
    };

    // check secondary diagonal
    s = grid_[2][0] + grid_[1][1] + grid_[0][2];
    player1_.win = s == 3;
    player2_.win = s == -3;
    if (player1_.win || player2_.win){
        finished_ = true; 
        return; 
    };

}

*/

void TicTacToe::Start() { 
    std::cout << "Starting game...\n";
    board_.ShowGrid();

    //game loop 
    
    /*
    while (true){
        turnPlayer(1); 
        board_.ShowGrid();
        updateStatus();
        if (finished_)
            break; 
        turnPlayer(2); 
        board_.ShowGrid();
        updateStatus();
        if (finished_)
            break; 
    }

    if (player1_.win)
        std::cout << "\n\n" << player1_.name << " (player 1) has won!!\n";
    else if (player2_.win)
        std::cout << "\n\n" << player1_.name << " has won!!\n";
    else
        std::cout << "\n\nDRAW!!\n";
    */
}
