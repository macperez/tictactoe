#include <iostream>
#include <format>
#include "Player.h"


Player::Player(std::string name, int number)
    : name_(name), number_(number)
{
    win_ = false;
}

HumanPlayer::HumanPlayer(std::string name, int number) : Player(name, number)
{

}


ComputerPlayer::ComputerPlayer(std::string name, int number) : Player(name, number)
{
    
}



void HumanPlayer::Play(Board & board) {
    // human plays
    int row, col; 

    while (true){
        std::cout << "\n\n";
        std::cout << name_ << ":: [x] [y] = " ;
        std::cin >> row >> col;
        if (board.validCoordinates(row, col)){
            row--; 
            col--;
            break;
        }
        std::cout << "Please enter valid row<space>col, (1-3) (1-3) Ex: 1 4\n";
        std::cout << std::format("Please enter valid row<space>col, (1-{}) (1-{}) Ex: 1 4\n", board.GetSize(), board.GetSize());

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    int value = number_ == 1? 1 : -1;
    board.setCoordinates(row, col, value);
    
    
}



void Player::MakeWinner(){
    win_ = true;
}


bool Player:: IsWinner() const{
    return win_;
}

const std::string & Player::GetName() const{
    return name_;
}