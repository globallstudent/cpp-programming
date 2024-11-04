#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // For usleep()
#include <termios.h>   // For terminal input settings
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define EMPTY ' '
#define DEMON 'X'
#define POWERUP 'O'
#define POWERUP_DURATION 10
#define DEMON_COUNT 5
#define FOOD_COUNT 50
#define LIVES 3

int score = 0, pacman_x, pacman_y, food = 0, lives = LIVES;
int power_up_mode = 0, power_up_timer = 0;
int demons[DEMON_COUNT][2];
char board[HEIGHT][WIDTH];

// Set up terminal in non-canonical mode to capture key presses without Enter
void set_noncanonical_mode(int enable) {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    if (enable) {
        t.c_lflag &= ~(ICANON | ECHO);
    } else {
        t.c_lflag |= (ICANON | ECHO);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Check for key press (non-blocking)
int key_pressed() {
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

// Capture arrow key press and convert it to direction
int get_input() {
    if (key_pressed()) {
        char ch = getchar();
        if (ch == 27) { // Escape sequence
            getchar(); // skip [
            ch = getchar();
            switch (ch) {
                case 'A': return 1; // UP (Arrow key)
                case 'B': return 2; // DOWN
                case 'D': return 3; // LEFT
                case 'C': return 4; // RIGHT
            }
        }
        // Optionally allow 'q' to exit
        if (ch == 'q') {
            exit(0);
        }
    }
    return 0;
}

void initialize() {
    srand(time(0));
    // Initialize the board with walls and empty spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
                board[i][j] = WALL;
            else
                board[i][j] = EMPTY;
        }
    }

    // Place Pacman at the center
    pacman_x = WIDTH / 2;
    pacman_y = HEIGHT / 2;
    board[pacman_y][pacman_x] = PACMAN;
    
    // Place food on the board
    for (int i = 0; i < FOOD_COUNT; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        if (board[y][x] == EMPTY) {
            board[y][x] = FOOD;
            food++;
        }
    }
    
    // Place demons (enemies)
    for (int i = 0; i < DEMON_COUNT; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        if (board[y][x] == EMPTY) {
            demons[i][0] = x;
            demons[i][1] = y;
            board[y][x] = DEMON;
        }
    }

    // Place one power-up
    int px = rand() % (WIDTH - 2) + 1;
    int py = rand() % (HEIGHT - 2) + 1;
    board[py][px] = POWERUP;
}

void draw() {
    system("clear");  // Clear the screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d | Lives: %d | Food Remaining: %d\n", score, lives, food);
    if (power_up_mode)
        printf("Power-Up Active! Moves left: %d\n", power_up_timer);
}

void move(int dx, int dy) {
    int nx = pacman_x + dx;
    int ny = pacman_y + dy;
    if (board[ny][nx] != WALL) {
        if (board[ny][nx] == FOOD) {
            score++;
            food--;
        } else if (board[ny][nx] == DEMON) {
            if (power_up_mode) {
                score += 10;  // You can destroy demons if in power-up mode
            } else {
                lives--;
                if (lives <= 0) {
                    printf("Game Over! Final Score: %d\n", score);
                    exit(0);
                }
                printf("Lost a life! Lives left: %d\n", lives);
                usleep(1000000);  // Pause after losing a life
            }
        } else if (board[ny][nx] == POWERUP) {
            power_up_mode = 1;
            power_up_timer = POWERUP_DURATION;
        }
        board[pacman_y][pacman_x] = EMPTY;
        pacman_x = nx;
        pacman_y = ny;
        board[pacman_y][pacman_x] = PACMAN;
    }
}

void move_demons() {
    for (int i = 0; i < DEMON_COUNT; i++) {
        int x = demons[i][0];
        int y = demons[i][1];
        int dx = (pacman_x > x) - (pacman_x < x);
        int dy = (pacman_y > y) - (pacman_y < y);
        
        int new_x = x + dx;
        int new_y = y + dy;
        if (board[new_y][new_x] == EMPTY || (new_x == pacman_x && new_y == pacman_y)) {
            board[y][x] = EMPTY;
            demons[i][0] = new_x;
            demons[i][1] = new_y;
            board[new_y][new_x] = DEMON;
        }
    }
}

int main() {
    set_noncanonical_mode(1);  // Enable non-canonical mode
    initialize();
    draw();
    while (1) {
        int input = get_input();
        switch (input) {
            case 1: move(0, -1); break;  // Move UP
            case 2: move(0, 1); break;   // Move DOWN
            case 3: move(-1, 0); break;  // Move LEFT
            case 4: move(1, 0); break;   // Move RIGHT
        }
        move_demons();
        if (power_up_mode && --power_up_timer == 0)
            power_up_mode = 0;
        
        draw();
        if (food == 0) {
            printf("You Win! Final Score: %d\n", score);
            break;
        }
        usleep(100000);  // Control game speed
    }
    set_noncanonical_mode(0); // Reset terminal mode
    return 0;
}

