class Move(object):
    def __init__(self, x, y, sign):
        self.x = x
        self.y = y
        self.sign = sign

class Player(object):
    def __init__(self, name, sign):
        self.name = name
        self.sign = sign

    def get_move(self):
        while True:
            print("{}, enter your move (x,y):".format(self.name))
            x, y = input().split(',')
            x = int(x)
            y = int(y)
            if (x>-1) and (x<3) and (y>-1) and (y<3):
                return Move(int(x), int(y), self.sign)

            else:
                print("Invalid field. Try Again!")

class Board(object):
    def __init__(self):
        self.board = [[' ']*3 for _ in range(3)]

    def __str__(self):
        return "\n".join(["|".join(row) for row in self.board])

    def get_state(self):
        print(self)

    def get_field(self, x, y):
        return self.board[x][y]

    def set_field(self, move):
        if self.get_field(move.x,move.y) == ' ':
            self.board[move.x][move.y] = move.sign


    def check_win(self, sign):
        for i in range(3):
            if self.board[i][0] == sign and self.board[i][1] == sign and self.board[i][2] == sign:
                return True
            if self.board[0][i] == sign and self.board[1][i] == sign and self.board[2][i] == sign:
                return True
        if self.board[0][0] == sign and self.board[1][1] == sign and self.board[2][2] == sign:
            return True
        if self.board[2][0] == sign and self.board[1][1] == sign and self.board[0][2] == sign:
            return True
        return False

class Game(object):
    def __init__(self):
        self.board = Board()

    def play(self, player_one, player_two):
        self.board.get_state()
        for i in range(9):
            if i % 2 == 0:
                current_player = player_one
            else:
                current_player = player_two
            while True:
                move = current_player.get_move()
                if self.board.get_field(move.x, move.y) == ' ':
                    self.board.set_field(move)
                    break
                else:
                    print("Field is signed. Try Again!")
            self.board.get_state()  
            if self.board.check_win(current_player.sign):
                if current_player == player_one:
                    return "Player One win"
                else:
                    return "Player Two win"
        return "Draw"


player_one = Player("Player One", 'X')
player_two = Player("Player Two", '0')
game = Game()
print(game.play(player_one , player_two))