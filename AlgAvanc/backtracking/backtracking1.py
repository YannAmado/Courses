class Queen:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def check_threaten(queens: Queen):
    n_queens = 0
    for i in queens:
        if i.x >= 0:
            n_queens += 1
    for pos1 in range(n_queens):
        for pos2 in range(pos1, n_queens):
            if pos1 != pos2:
                #if they are on the same row or col
                if queens[pos1].x == queens[pos2].x or queens[pos1].y == queens[pos2].y:
                    return True

                #if they are on the diagonal
                if abs(queens[pos1].x - queens[pos2].x) ==  abs(queens[pos1].y - queens[pos2].y):
                    return True
    return False


def cut_leaf(queens):
    if check_threaten(queens):
        return True
    return False


def sum_queens(board: list, queens: Queen):
    sum = 0
    for i in range(8):
        sum += board[queens[i].x][queens[i].y]
    return sum


def find_solution(board: list, queens: list, current_queen: int):
    if cut_leaf(queens):
        return
    if current_queen == 8:
        sum = sum_queens(board, queens)
        global biggest_sum
        if sum > biggest_sum:
            biggest_sum = sum
        return

    for i in range(8):
        queens[current_queen].x = current_queen
        queens[current_queen].y = i
        find_solution(board, queens, current_queen+1)
    queens[current_queen].x = -1
    queens[current_queen].y = -1
    return


n_tests = int(input())

queens = []
for i in range(8):
    queens.append(Queen(-1, -1))
for z in range(n_tests):
    biggest_sum = 0
    board = []
    for i in range(8):          # A for loop for row entries
        line = input()
        if line == '' or line=='\r' or line == '\n':
            line = input()
        values = [int(value) for value in line.split()]
        board.append(values)
    find_solution(board, queens, 0)
    print("{:>5}".format(biggest_sum))
