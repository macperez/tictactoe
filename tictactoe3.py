class Player():
    def __init__(self, name):
        self.name = name
        self.win = False
    


class Game(): 
    def __init__(self, player1_name, player2_name=None):
        
        self.grid = [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0],
        ]
        self.busy_counter = 0
        self.finished = False
        self.player1 = Player(player1_name)
        self.player2 = Player(player2_name)
        self.show()

    def start(self):
        print("Starting game...")
        while True:
            self.player_turn(1)
            self.show()
            self.update_status_game()
            if self.finished:
                break
            self.player_turn(2)
            self.show()
            self.update_status_game()
            if self.finished:
                break
        print("Finish game!!")
        if self.player1.win:
            print(f"The winner is {self.player1.name}")
        elif self.player2.win: 
            print(f"The winner is {self.player2.name}")
        else: 
            print("The game ended in a draw")

    def _coordinates_valid(self, row_txt: str, col_txt: str):
        if not (row_txt.isdigit() and col_txt.isdigit()):
            return False, -1, -1 
        row = int(row_txt)
        col = int(col_txt)
        if col < 1 or col > 3 or row < 1 or row > 3: 
            return False, -1, -1
        row -= 1 
        col -= 1
        if self.grid[row][col] != 0:
            print(f"[{row}, {col}] are busy")
            return False, -1, -1
    
        return True, row, col


    def player_turn(self, num_player):
        name = self.player1.name if num_player == 1 else self.player2.name
        row, col = -1, -1
        while True:
            entry = input(f"Player {num_player}: {name}; coordinates [x][y]: ")
            rowtxt, coltxt = entry.split()
            res, row, col = self._coordinates_valid(rowtxt, coltxt)
            if res: break        
            print("Please enter valid row<space>col, (1-3) (1-3) Ex: 1 4") 
        self.grid[row][col] =  -1 if num_player == 1 else 1
        self.busy_counter += 1

    def update_status_game(self):
        # rows
        sum = 0
        for r in range(3):
            sum = 0
            for c in range(3):
                sum += self.grid[r][c]
            if sum < -2 or sum > 2:
                break 

        self.player1.win = sum == -3
        self.player2.win = sum == 3
        if self.player1.win or self.player2.win: 
            self.finished = True
            return 
 
        # cols 
        for c in range(3):
            sum = 0
            for c in range(3):
                sum += self.grid[r][c]
            if sum < -2 or sum > 2:
                break 
        
        self.player1.win = sum == -3
        self.player2.win = sum == 3
        if self.player1.win or self.player2.win: 
            self.finished = True
            return 
 
        # diag1 
        sum = self.grid[0][0] + self.grid[1][1] + self.grid[2][2]
        self.player1.win = sum == -3
        self.player2.win = sum == 3
        if self.player1.win or self.player2.win: 
            self.finished = True
            return 
        
        # diag2 
        sum = self.grid[0][2] + self.grid[1][1] + self.grid[2][0]
        self.player1.win = sum == -3
        self.player2.win = sum == 3
        if self.player1.win or self.player2.win: 
            self.finished = True
            return

        if self.busy_counter == 9:
            return 
        
            
    def show(self): 
        for row in self.grid: 
            print("")
            row_str = ""
            for col in row: 
                if col == -1:
                    row_str += "X   "
                elif col == 1:
                    row_str += "O   "
                else:
                    row_str += ".   "
            print(row_str)


if __name__ == '__main__':
    
    player1_name = input("Player 1: ")
    player2_name = input("Player 2: ")
    game = Game(player1_name, player2_name)
    game.start()
    
    