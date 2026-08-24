#pragma once
#include <string>
#include "Board.h"




class Player { 
    protected: 
        std::string name_; 
        bool win_ = false; 
        int number_; 
    
    public: 
        Player(std::string playerName, int number);
        virtual ~Player() = default;
        virtual void Play(Board & board) = 0; 
        void MakeWinner(); 
        bool IsWinner() const;
        const std::string& GetName() const; 


};


// Derived class ClassPlayer
class HumanPlayer: public Player {
    public:
        HumanPlayer(std::string name, int number);
        void Play(Board & board) override;

};



// Derived class ComputerPlayer
class ComputerPlayer: public Player {
    public:
        ComputerPlayer(std::string name, int number);
        //void Play(Board & board) override;

};


