#include <iostream>
#include <array>
#include <limits>
#include "Game.h"

TicTacToe::TicTacToe(std::string player1Name, std::string player2Name){
    player1_ = {player1Name, false};
    player2_ = {player2Name, false};
    pos_counter_ = 0;
    finished_ = false; 
}


void TicTacToe::ShowGrid() const { 
    for(const std::array<int, 3> & row: grid_){
        std::cout << "\n\n";
        for(int val: row)
            switch (val){
            case -1:
                std::cout << "X\t";
                break;
            case 1:
                std::cout << "O\t";
                break;
            
            default:
                std::cout << ".\t";
                break;
            }
    }
}

bool TicTacToe::validCoordinates(int row, int col) const {

    return true; 
}

void TicTacToe::turnPlayer(int numPlayer){
    std::string name = numPlayer == 1 ? player1_.name:player2_.name;
    int row, col;
    std::cout << "Player " << numPlayer << "(" << name << ") turn. Coordinates?\n";
    
    bool valid = false; 
    
    while (true){
        if (std::cin >> row >> col && validCoordinates(row, col))
            break;
        std::cout << "Please enter valid row<space>col, (1-3) (1-3) Ex: 1 4\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        
    grid_[row][col] = numPlayer == 1 ? 1 :-1;
    pos_counter_++;
}

void TicTacToe::updateStatus(){
    
}


void TicTacToe::Start() { 
    std::cout << "Starting game...\n";

    turnPlayer(1);
    // game loop 
    //while (true){
        
   // }
}
