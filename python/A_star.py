def print_puzzle(board):
    for row in board:
        print(" ".join(map(str, row)))

def find_zero(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return i, j

def manhattan_distance(board):
    distance = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] != 0:
                target_i, target_j = (board[i][j] - 1) // 3, (board[i][j] - 1) % 3
                distance += abs(i - target_i) + abs(j - target_j)
    return distance

def is_solved(board):
    return board == [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

def solve_puzzle(initial_state):
    puzzle = initial_state
    steps = 0

    print("Initial puzzle:")
    print_puzzle(puzzle)

    open_list = [(manhattan_distance(puzzle), steps, puzzle)]
    closed_set = set()

    while open_list:
        open_list.sort(key=lambda x: x[0])
        _, g, current_state = open_list.pop(0)

        if current_state == [[1, 2, 3], [4, 5, 6], [7, 8, 0]]:
            print("Solved puzzle:")
            print_puzzle(current_state)
            print(f"Number of steps: {g}")
            return

        closed_set.add(tuple(map(tuple, current_state)))

        zero_i, zero_j = find_zero(current_state)
        possible_moves = []

        if zero_i > 0:
            possible_moves.append((zero_i - 1, zero_j))  # Move up
        if zero_i < 2:
            possible_moves.append((zero_i + 1, zero_j))  # Move down
        if zero_j > 0:
            possible_moves.append((zero_i, zero_j - 1))  # Move left
        if zero_j < 2:
            possible_moves.append((zero_i, zero_j + 1))  # Move right

        for new_pos in possible_moves:
            new_state = [list(row) for row in current_state]
            new_state[zero_i][zero_j], new_state[new_pos[0]][new_pos[1]] = new_state[new_pos[0]][new_pos[1]], new_state[zero_i][zero_j]
            if tuple(map(tuple, new_state)) not in closed_set:
                open_list.append((g + manhattan_distance(new_state), g + 1, new_state))
    
    print("No solution found!")

if __name__ == "__main__":
    initial_state = [[1, 0, 3], [4, 2, 6], [7, 5, 8]]
    solve_puzzle(initial_state)
