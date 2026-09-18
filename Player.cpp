#include <iostream>
#include "Player.h"


Player::Player(std::string name, int number)
    : name_(name), number_(number)
{
    win_ = false;
}

HumanPlayer::HumanPlayer(std::string name, int number) : Player(name, number)
{

}


/*
ComputerPlayer::ComputerPlayer(std::string name, int number) : Player(name, number)
{
    
}

*/

void HumanPlayer::Play(Board & board) 
{
    // human plays
    int row, col; 

    while (true){
        std::cout <<"\n\n"<< name_ << ", enter coordinates [x] [y]: " ;
        std::cin >> row >> col;
        if (board.validCoordinates(row - 1, col- 1)){
            row--; 
            col--;
            break;
        }
        std::cout << "Please enter valid row<space>col, (1-3) (1-3) Ex: 1 2\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    board.SetValue(row, col, number_ == 1? 1 : -1);
    

}


bool Player::IsWinner() const
{
    return win_; 
}
    
    
const std::string& Player::GetName() const
{
    return name_;
}

void Player::MakeWinner()
{
    win_ = true; 
} 
