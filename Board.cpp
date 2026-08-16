#include <iostream>
#include "Board.h"


Board::Board(int size)
    : size_(size), grid_(size, std::vector <int> (size, 0))
{
    // at the beginning all positions are free, naturally 
    busyCounter_ = 0;

   
    std::cout << "done! \n";
}



void Board::Show() const{
    
    std::cout << std::endl;
    for(const std::vector<int> & row: grid_){
        std::cout << "\n";
        for(const int & val: row)
            switch (val){
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


bool Board::validCoordinates(int row, int col) const {
    row--;
    col--;
    return  row >= 0 && row < size_ && col >= 0 && col < size_ && grid_[row][col] == 0;   
}


int Board::GetSize() const{
    return size_;
}

void  Board::setCoordinates(int row, int col, int value){
    std::cout << "Set coordinates\n";
    

}
