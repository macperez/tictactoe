#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Board.h"


Board::Board(int size)
    : size_(size), grid_(size, std::vector <int> (size, 0))
{
    // at the beginning all positions are free, naturally 
    busyCounter_ = 0;   
}



void Board::Show() const{
    
    std::cout << std::endl;
    for(const std::vector<int> & row: grid_){
        std::cout << "\n\n";
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
    
    if (value){
         grid_[row][col] = value; 
         busyCounter_++;
    }

}



bool Board::IsComplete() const{
    return busyCounter_ >= size_ * size_;
}


int Board::checkLine(std::vector<int> line, int lineLength) const{
    int i = 0, total = 0; 
    while (i < line.size() - 1){
        if (line[i] == line[i + 1]){
            total = line[i];
            while (i < line.size() - 1 && line[i] == line[i + 1]){
                total += line[i + 1];
                if (std::abs(total) == lineLength)
                    return total;                 
                i++;
            }
        }else 
            i++;
    }
    return total; 
}



int Board::CheckRows(int lineLenght) const{

    int valrows = 0; 
    for (int r = 0; r < size_; r++){
        auto rowValues =  getAxis(r, 0, Direction :: HORIZONTAL);
        valrows = checkLine(rowValues, lineLenght);
        if (std::abs(valrows) == lineLenght)
            break;
    }
    return valrows;
}


int Board::CheckCols(int lineLength) const { 
    int val = 0; 
    for (int c = 0; c < size_; c++){
        auto colValues =  getAxis(0, c, Direction :: VERTICAL);
        val = checkLine(colValues, lineLength);
        if (std::abs(val) == lineLength)
            break;
    }
    return val; 
}
    

int Board::CheckMainDiagonals(int linelength) const{
    int val = 0; 
    std::vector <int> values ; 
    for (int c = 0; c < size_; c++){
        values =  getAxis(0, c, Direction :: MAIN_DIAGONAL);
        val = checkLine(values, linelength);
        if (std::abs(val) == linelength)
            return val;
    }
    for (int r = 1; r < size_; r++){
        values =  getAxis(r, 0, Direction :: MAIN_DIAGONAL);
        val = checkLine(values, linelength);
        if (std::abs(val) == linelength)
            return val;
    }
    
    
    return val; 
} 

/*
   def check_secondary_diagonals(self, line_length:int) -> int:
        val = 0
        for col_index in range(self.N_SIZE):
            sec_diag_values  = self._get_axis(0, col_index, RowOrientation.SECONDARY_DIAGONAL)
            found, val = self._check_axis(sec_diag_values, line_length)
            if found:
                return val
        
        for row_index in range(1, self.N_SIZE):
            sec_diag_values  = self._get_axis(row_index, 0, RowOrientation.SECONDARY_DIAGONAL)
            found, val = self._check_axis(sec_diag_values, line_length)
            if found:
                break
        
        return val

*/

int Board::CheckSecondaryDiagonals(int linelength) const{
    int val = 0; 
    std::vector <int> values ; 
    for (int c = 0; c < size_; c++){
        values = getAxis(0, c, Direction :: SECONDARY_DIAGONAL);
        val = checkLine(values, linelength);
        if (std::abs(val) == linelength)
            return val;
    }
    for (int r = 1; r < size_; r++){
        values =  getAxis(r, 0, Direction :: SECONDARY_DIAGONAL);
        val = checkLine(values, linelength);
        if (std::abs(val) == linelength)
            return val;
    }
    
    return val; 

} 



std::vector<int> Board::getAxis(int row, int col, Direction direction) const{
    std::vector<int> result;
    int steps = -1; 
    switch (direction){
        case Direction::HORIZONTAL:
            result = grid_[row];
            break;
        
        case Direction::VERTICAL:
            for (int r = 0 ; r < size_; r++)
                result.push_back(grid_[r][col]);
                break;

        case Direction::MAIN_DIAGONAL: 
            steps = std::min(size_ - row, size_ - col);
            for (int s = 0; s < steps; s++)
                result.push_back(grid_[row + s][col + s]);
            break;
        
        case Direction::SECONDARY_DIAGONAL:
            steps = std::min(size_ - row, col + 1);
            for (int s = 0; s < steps; s++)
                result.push_back(grid_[row + s][col - s]); 
            break;

        default:
            break;
        }

    return result;
} 



