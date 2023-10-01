# Game Constants
EMPTY = ' '
PLAYER1 = 'X'
PLAYER2 = 'O'

# Game Board
board = [EMPTY] * 9

# Global Variables
current_player = PLAYER1


def display_board():
    lines = ['```']
    for i in range(0, 9, 3):
        row = ' | '.join(board[i:i + 3])
        lines.append(row)
        lines.append('-' * 9)
    lines.pop()
    lines.append('```')
    board_str = '\n'.join(lines)
    print(board_str)


def is_valid_move(position):
    return position in range(1, 10) and board[position - 1] == EMPTY


def make_move(position, player):
    board[position - 1] = player


def check_winner(player):
    # Check rows
    for i in range(0, 9, 3):
        if board[i] == board[i + 1] == board[i + 2] == player:
            return True

    # Check columns
    for i in range(3):
        if board[i] == board[i + 3] == board[i + 6] == player:
            return True

    # Check diagonals
    if board[0] == board[4] == board[8] == player:
        return True
    if board[2] == board[4] == board[6] == player:
        return True

    return False


def reset_board():
    global board
    board = [EMPTY] * 9


def switch_player():
    global current_player
    current_player = PLAYER2 if current_player == PLAYER1 else PLAYER1


def main():
    print("Welcome to Tic-Tac-Toe!")
    while True:
        display_board()
        try:
            position = int(
                input(f"Player {current_player}, enter your position (1-9): "))
            if not is_valid_move(position):
                print("Invalid move! Please choose a number between 1 and 9.")
                continue

            make_move(position, current_player)

            if check_winner(current_player):
                display_board()
                print(f"Player {current_player} wins!")
                reset_board()
                break

            if all(cell != EMPTY for cell in board):
                display_board()
                print("It's a draw!")
                reset_board()
                break

            switch_player()
        except ValueError:
            print("Invalid input! Please enter a number between 1 and 9.")


if __name__ == "__main__":
    main()
