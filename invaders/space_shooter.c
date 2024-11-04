#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int x, y;
    int health;
} Player;

typedef struct {
    int x, y;
    int is_alive;
} Alien;

typedef struct {
    int x, y;
} Obstacle;

#define MAX_ALIENS 5
#define MAX_OBSTACLES 3
#define PLAYER_HEALTH 3

void initialize_game();
void draw_player(Player *player);
void move_player(Player *player, int key);
void draw_aliens(Alien aliens[], int num_aliens);
void move_aliens(Alien aliens[], int num_aliens);
void draw_obstacles(Obstacle obstacles[], int num_obstacles);
void game_loop(Player *player, Alien aliens[], int *num_aliens, Obstacle obstacles[], int *phase);

int main() {
    Player player = {5, LINES / 2, PLAYER_HEALTH};  // Player's starting position and health
    Alien aliens[MAX_ALIENS];
    Obstacle obstacles[MAX_OBSTACLES];
    int num_aliens = 3;
    int phase = 1;

    initialize_game();
    game_loop(&player, aliens, &num_aliens, obstacles, &phase);

    endwin();
    return 0;
}

void initialize_game() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(100);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);  // Player color
    init_pair(2, COLOR_RED, COLOR_BLACK);   // Alien color
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);// Obstacle color
}

void draw_player(Player *player) {
    attron(COLOR_PAIR(1));
    mvprintw(player->y, player->x, ">");
    attroff(COLOR_PAIR(1));
}

void move_player(Player *player, int key) {
    switch (key) {
        case KEY_UP: if (player->y > 1) player->y--; break;
        case KEY_DOWN: if (player->y < LINES - 2) player->y++; break;
        case KEY_LEFT: if (player->x > 1) player->x--; break;
        case KEY_RIGHT: if (player->x < COLS - 2) player->x++; break;
    }
}

void draw_aliens(Alien aliens[], int num_aliens) {
    for (int i = 0; i < num_aliens; i++) {
        if (aliens[i].is_alive) {
            attron(COLOR_PAIR(2));
            mvprintw(aliens[i].y, aliens[i].x, "A");
            attroff(COLOR_PAIR(2));
        }
    }
}

void move_aliens(Alien aliens[], int num_aliens) {
    for (int i = 0; i < num_aliens; i++) {
        if (aliens[i].is_alive) {
            aliens[i].x--;
            if (aliens[i].x < 0) {
                aliens[i].x = COLS - 1;
                aliens[i].y = rand() % (LINES - 2) + 1;
            }
        }
    }
}

void draw_obstacles(Obstacle obstacles[], int num_obstacles) {
    for (int i = 0; i < num_obstacles; i++) {
        attron(COLOR_PAIR(3));
        mvprintw(obstacles[i].y, obstacles[i].x, "#");
        attroff(COLOR_PAIR(3));
    }
}

void game_loop(Player *player, Alien aliens[], int *num_aliens, Obstacle obstacles[], int *phase) {
    int ch;
    int num_obstacles = *phase;

    // Initialize aliens and obstacles
    for (int i = 0; i < *num_aliens; i++) {
        aliens[i].x = COLS - 10 - (i * 5);
        aliens[i].y = (i % (LINES - 2)) + 1;
        aliens[i].is_alive = 1;
    }

    for (int i = 0; i < num_obstacles; i++) {
        obstacles[i].x = COLS / 2 + (i * 5);
        obstacles[i].y = (i % (LINES - 2)) + 1;
    }

    while (player->health > 0) {
        clear();
        draw_player(player);
        draw_aliens(aliens, *num_aliens);
        draw_obstacles(obstacles, num_obstacles);

        ch = getch();
        if (ch == 'q') break;
        move_player(player, ch);
        move_aliens(aliens, *num_aliens);

        // Check for collisions with aliens
        for (int i = 0; i < *num_aliens; i++) {
            if (aliens[i].is_alive && aliens[i].x == player->x && aliens[i].y == player->y) {
                player->health--;
                aliens[i].is_alive = 0;  // Destroy the alien
            }
        }

        refresh();
        usleep(50000);
    }
}

