#include <iostream>
#include "Board.h"


Board::Board ():
grid_({
    { 0, 0, 0}, 
    {0, 0, 0},
    {0, 0, 0}
}), occupation_(0)

{

}


bool Board:: validCoordinates(int row, int col) const
{
    return  row >= 0 && row < 3 && col >= 0 && col < 3 && grid_[row][col] == 0;   

}


void Board:: ShowGrid() const
{
 
    for(const std::array<int, 3> & row: grid_)
    {
        std::cout << "\n\n";
        for(const int & val: row)
            switch (val)
            {
                case -1:
                    std::cout << "X\t";
                    break;
                case 1:
                    std::cout << "O\t";
                    break;
                
                default:
                    std::cout << ".\t";
                    break;
            }
    }

    
}