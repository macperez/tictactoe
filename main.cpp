#include <iostream>
#include <string>
#include "TicTacToe.h"

int main()
{
    
    std::cout << "Welcome to TIC-TAC-TOE game!!\n";
    std::cout << "-----------------------------\n\n";
    
    
    std::string name1, name2; 

    std::cout << "Enter player 1 name:\n";
    std::cin >> name1; 
    std::cout << "Enter player 2 name:\n";
    std::cin >> name2; 

    int sizeBoard; 

    std::cout << "Enter the dimension of the board:\n";
    std::cin >> sizeBoard; 
    

    int lineLength; 

    std::cout << "Enter the line length. Must be less than board size:\n";
    std::cout << "Example: you need line lenght 4 for playing \'Four in a row\' in a board of 4 size or more. \n";
    std::cin >> lineLength; 
    
    if (lineLength > sizeBoard){
        std::cout << "Must be less than board size!:\n";
    }
      
    
    
    std::cout << "-----------------\n";
    std::cout << "Let's play for gamers: ";
    std::cout << name1 << " and " << name2 << std::endl;
    std::cout << "Be luck!!!\n";
    std::cout << "-----------------\n";

    

    //std::string name1 = "manu", name2 = "lucas";
    //int sizeBoard = 4, lineLength = 3; 

    TicTacToe game (sizeBoard, lineLength, name1, name2);

    game.Start();
}