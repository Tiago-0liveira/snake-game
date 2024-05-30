#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <snake.h>

#define WIN_WIDTH (SNAKE_GAME_TILES * SNAKE_SIZE + BORDER_SIZE * 2)
#define WIN_HEIGHT (WIN_WIDTH + HEADER_SIZE)
#define GAME_NAME "Snake Game"

#define BORDER_SIZE 20
#define BORDER_COLOR DARKGRAY
#define HEADER_SIZE 40
#define HEADER_COLOR GRAY

#define FPS 120
#define SPEED 5
#define BG_COLOR RAYWHITE

#endif // GAME_H