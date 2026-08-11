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
