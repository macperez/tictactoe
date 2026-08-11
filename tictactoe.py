from enum import Enum


class RowOrientation(Enum): 
    VERTICAL = 1
    HORIZONTAL = 2
    MAIN_DIAGONAL = 3
    SECONDARY_DIAGONAL = 4



class Board: 
    def __init__(self, n : int):
        self.busy_counter = 0
        self.N_SIZE = n
        self.grid = [  [0 for _ in range(n)] for _ in range(n)   ]
    
    def show(self): 
        for row in self.grid: 
            print("")
            row_str = ""
            for col in row: 
                if col == -1:
                    row_str += f"X   "
                elif col == 1:
                    row_str += f"O   "
                else:
                    row_str += f".   "
            print(row_str)

    def set_coordinates(self, row: int, col: int, value: int):
        if value != 0:
            self.grid[row][col] = value; 
            self.busy_counter += 1
    
    def coordinates_valid(self, row_txt: str, col_txt: str)-> tuple[bool, int, int]: 
        if not (row_txt.isdigit() and col_txt.isdigit()):
            return False, -1, -1 
        row = int(row_txt)
        col = int(col_txt)
        if col < 1 or col > self.N_SIZE or row < 1 or row > self.N_SIZE: 
            return False, -1, -1
        row -= 1 
        col -= 1
        if self.grid[row][col] != 0:
            print(f"[{row}, {col}] are busy")
            return False, -1, -1
    
        return True, row, col
    
    def _get_axis(self, row, col, axis = 1):
        n = len(self.grid)
        if row >= n or row < 0 or col >= n or col < 0:
            return None
        if axis == RowOrientation.HORIZONTAL: #horizontal
            return self.grid[row]
        elif axis == RowOrientation.VERTICAL: # vertical
            return [self.grid[row][col] for row in range(n)]
        elif axis == RowOrientation.mro: # main diagonal
            steps = min(n - row, n - col)
            return [self.grid[row + s] [col + s] for s in range(steps)]
        # secondary diagonal
        steps = min(len(self.grid) - row, col)
        return [self.grid[row + s] [col - s] for s in range(steps + 1)]

    def _check_axis(self, array: list[int], length : int) -> tuple [bool, int]:
        i = 0
        while i < len(array) - 1:
            if array[i] == array[i + 1]:
                total = array[i]
                while i < len(array) - 1 and array[i] == array[i + 1]:
                    total += array[i + 1]
                    if abs(total) == length:
                        return True, total
                    i += 1
            else:
                i += 1
        return False, 0

    def check_rows(self, line_length:int) -> int:
        # rows
        val = 0
        for row_index in range(self.N_SIZE):
            row_values  = self._get_axis(row_index, 0, RowOrientation.HORIZONTAL)
            found, val = self._check_axis(row_values, line_length)
            if found:
                break
        return val
    
    

    def check_cols(self, line_length:int) -> int:
        # cols
        val = 0
        for col_index in range(self.N_SIZE):
            col_values  = self._get_axis(0, col_index, RowOrientation.VERTICAL)
            found, val = self._check_axis(col_values, line_length)
            if found:
                break
        return val
    

    def check_main_diagonals(self, line_length:int) -> int:
        val = 0
        for col_index in range(self.N_SIZE):
            main_diag_values  = self._get_axis(0, col_index, RowOrientation.MAIN_DIAGONAL)
            found, val = self._check_axis(main_diag_values, line_length)
            if found:
                return val

        
        for row_index in range(1, self.N_SIZE):
            main_diag_values  = self._get_axis(row_index, 0, RowOrientation.MAIN_DIAGONAL)
            found, val = self._check_axis(main_diag_values, line_length)
            if found:
                break
        
        return val

        
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

    


    def all_board_filled(self) -> bool:
        return self.busy_counter == self.N_SIZE * self.N_SIZE



class Player:
    def __init__(self, num: int , name:str):
        self.name = name
        self.win = False
        self.number = num
    

class Computer(Player):
    def __init__(self, num):
        super().__init__(num, 'computer')

    def play(self):
        pass


class Human(Player):
    def __init__(self, num: int, name: str):
        super().__init__(num, name)

    def play(self, board: Board):
        row, col = -1, -1
        while True:
            entry = input(f"Player , {self.name}, enter coordinates [x][y]: ")
            rowtxt, coltxt = entry.split()
            res, row, col = board.coordinates_valid(rowtxt, coltxt)
            if res: break        
            print(f"Please enter valid row<space>col, (1-{board.N_SIZE}) (1-{board.N_SIZE}) Ex: 1 4") 
        
        board.set_coordinates(row, col, -1)  if self.number == 1 else board.set_coordinates(row, col, 1) 
                
    
        




class Game(): 
    def __init__(self, player1_name, player2_name=None, matrix_size=3, line_length=3):

        self.board = Board(matrix_size)
        self.line_length = line_length # line_length must be < matrix_size
        self.busy_counter = 0
        self.finished = False
        self.player1 = Human(1, player1_name)
        self.player2 = Computer(2, player2_name) if player2_name == 'computer' \
            else Human(2, player2_name)
        

    def start(self):
        print("Starting game...")
        self.board.show()
        # game loop
        while True:
            self.player1.play(self.board)
            self.board.show()
            self._update_status_game()
            if self.finished:
                break
            self.player2.play(self.board)
            self.board.show()
            self._update_status_game()
            if self.finished:
                break
        print("Finish game!!")
        if self.player1.win:
            print(f"The winner is {self.player1.name}")
        elif self.player2.win: 
            print(f"The winner is {self.player2.name}")
        else: 
            print("The game ended in a draw")

        
    def _update_status_game(self):
     
        if self.board.all_board_filled():
            self.finished = True
            return 

        val = self.board.check_rows(self.line_length)
        
        self.player1.win = val == -self.line_length
        self.player2.win = val == self.line_length
        if self.player1.win or self.player2.win:
            self.finished = True
            return 

        
        val = self.board.check_cols(self.line_length)
        self.player1.win = val == -self.line_length
        self.player2.win = val == self.line_length
        if self.player1.win or self.player2.win:
            self.finished = True
            return 


        val = self.board.check_main_diagonals(self.line_length)
        self.player1.win = val == -self.line_length
        self.player2.win = val == self.line_length
        if self.player1.win or self.player2.win:
            self.finished = True
            return 

        
        val = self.board.check_secondary_diagonals(self.line_length)
        self.player1.win = val == -self.line_length
        self.player2.win = val == self.line_length
        if self.player1.win or self.player2.win:
            self.finished = True
            return 






if __name__ == '__main__':
    # let the player choose the grid size:
    print("\n\nTIC-TAC-TOE!")
    print("------------")
    n = input("Choose the N value (N X N grid): ")
    lgth = input("Choose the length of the string (tictactoe, for-in-a-row, ...)")
    
    n = int(n) #make more robust 
    lgth = int(lgth)
    
    if lgth >= n:
        print("The board size must be great that line!")
    else: 
        player1_name = input("Player 1:\n")
        player2_name = input("Player 2(type: enter for computer):\n")
        if player2_name.strip() == "":
            player2_name = 'computer'
        game = Game(player1_name, player2_name, n, lgth)
        game.start()
        