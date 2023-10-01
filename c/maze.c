#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

char maze[HEIGHT][WIDTH];

void initializeMaze() {
    // Initialize the maze with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = '#';
        }
    }
}

int isSafe(int x, int y) {
    // Check if the given coordinates are within the maze boundaries
    return (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH);
}

int isVisited(int x, int y) {
    // Check if a cell has been visited (contains a space)
    return (maze[x][y] == ' ');
}

int canVisit(int x, int y) {
    // Check if a cell can be visited (not out of bounds and not visited)
    return isSafe(x, y) && !isVisited(x, y);
}

int directions[4][2] = {
    {0, 2},  // Right
    {2, 0},  // Down
    {0, -2}, // Left
    {-2, 0}  // Up
};

void generateMaze(int x, int y) {
    // Mark the current cell as visited
    maze[x][y] = ' ';

    // Randomly shuffle the directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int tempX = x + directions[r][0];
        int tempY = y + directions[r][1];

        if (canVisit(tempX, tempY)) {
            // Remove the wall between the current cell and the next cell
            maze[x + directions[r][0] / 2][y + directions[r][1] / 2] = ' ';
            generateMaze(tempX, tempY);
        }
    }
}

void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    initializeMaze();
    generateMaze(1, 1); // Start generation from (1,1)

    // Set start and exit points
    maze[0][1] = 'S';
    maze[HEIGHT - 1][WIDTH - 2] = 'E';

    printMaze();

    return 0;
}
