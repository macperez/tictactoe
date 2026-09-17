#pragma once
#include <array>


enum class Direction  {
    HORIZONTAL, 
    VERTICAL, 
    MAIN_DIAGONAL, 
    SECONDARY_DIAGONAL

};


class Board 
{
    private: 
        std::array<std::array<int, 3>, 3> grid_;
        int occupation_;  
        
    public: 
        Board();    

        bool validCoordinates(int row, int col) const; 
        void ShowGrid() const; 
        void SetValue(int row, int col, int value);
        bool isCompleted() const; 

     
        int evalRows() const;
        int evalCols() const;
        int evalMainDiag() const; 
        int evalSecondDiag() const; 

}; 
