#pragma once
#include <string>
#include <array> 


struct Player{
    std::string name; 
    bool win; 
};

class TicTacToe{
    private: 
        std::array<std::array<int, 3>, 3> grid_ =  {{
            {0, 0, 0}, 
            {0, 0, 0},
            {0, 0, 0}
        }}; 

        int pos_counter_; 
        bool finished_;
        Player player1_; 
        Player player2_;

        void turnPlayer(int numPlayer);
        bool validCoordinates(int row, int col) const;
        void updateStatus(); 

    public: 
        TicTacToe(std::string player1Name, std::string player2Name="computer");
        void Start();
        void ShowGrid() const; 
        
};