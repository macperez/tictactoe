#include <iostream>
#include <numeric>
#include "Board.h"
#include <cmath>




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

void Board :: SetValue(int row, int col, int value)
{
    int lastValue = grid_[row][col]; 

    if (lastValue != 0 && value == 0) 
        occupation_--;
    else if (lastValue == 0 && value != 0)
        occupation_ ++;    
    
    grid_[row][col] = value; 


}

bool Board :: isCompleted() const 
{
    return occupation_ == grid_.size();
}

int Board :: evalRows() const 
{
    int s = 0, p  = 0; 
    for (int r = 0 ; r < 3; r++)
    {
        p = grid_[r][0] + grid_[r][1] + grid_[r][2];
        if (std::abs(p) > s)
            s = p; 
    }

    return s;
}

int Board :: evalCols () const
{
    int s = 0, p  = 0; 
    for (int c = 0 ; c < 3; c++)
    {
        p = grid_[0][c] + grid_[1][c] + grid_[2][c];
        if (std::abs(p) > s)
            s = p; 
    }
    return s;


}

int Board :: evalMainDiag() const
{
    return grid_[0][0] + grid_[1][1] + grid_[2][2];
}

int Board :: evalSecondDiag() const
{
    return grid_[0][2] + grid_[1][1] + grid_[2][0];
}