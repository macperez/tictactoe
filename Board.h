#pragma once

#include <vector> 


enum class Direction  {
    HORIZONTAL, 
    VERTICAL, 
    MAIN_DIAGONAL, 
    SECONDARY_DIAGONAL

};

class Board{ 
    private: 
        int busyCounter_ = 0; 
        int size_; 

        
        std::vector<std::vector<int>> grid_;

        
        //bool validCoordinates(int row, int col) const;
        //std::vector<int> getLine(int row, int col, Direction direction) const; 


    public: 

        Board(int size);
        void Show() const; 
        //void setCoordinates(int row, int col, int value);
};
