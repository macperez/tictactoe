#include <iostream>
#include <string>
#include "Game.h"

int main()
{
    
    std::cout << "Welcome to TIC-TAC-TOE game!!\n";
    std::cout << "-----------------------------\n\n";
    std::string name1, name2; 
    std::cout << "Enter player 1 name:\n";
    std::cin >> name1; 
    std::cout << "Enter player 2 name:\n";
    std::cin >> name2; 
    TicTacToe game (name1, name2);
    //game.ShowGrid();
    game.Start();
}