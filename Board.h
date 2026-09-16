#pragma once
#include <array>



class Board 
{
    private: 
        std::array<std::array<int, 3>, 3> grid_;
        int occupation_;  
        
    public: 
        Board();    

        bool validCoordinates(int row, int col) const; 
        void ShowGrid() const; 

    

}; 
