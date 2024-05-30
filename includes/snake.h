#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <raymath.h>

#define SNAKE_HEAD_COLOR GREEN
#define SNAKE_COLOR DARKGREEN
#define SNAKE_SIZE 20
#define SNAKE_GAME_TILES 40
#define FOOD_COLOR RED

typedef struct Tail {
	Vector2 position;
	struct Tail *next;
}	Tail;

typedef struct {
	Vector2 position;/* values between 0-(SNAKE_GAME_TILES - 1) */
	Vector2 direction;/* values 0 or 1 */
	size_t	size;
	Tail	*tail;
}	Snake;

typedef struct {
	Vector2 position;
}	Food;

#define UP_DIRECTION (Vector2){0.0f, -1}
#define DOWN_DIRECTION (Vector2){0.0f, 1}
#define LEFT_DIRECTION (Vector2){-1, 0.0f}
#define RIGHT_DIRECTION (Vector2){1, 0.0f}

Snake	*create_Snake(Vector2 position);
void	draw_Snake(Snake *snake, Vector2 offset);
void	drawSnakeHead(Snake *snake, Vector2 offset);
void	changeSnakeDir(Snake *snake, Vector2 direction);
void	snake_update_position(Snake *snake, Food *food);
void	add_Tail(Snake *snake);
void	changeFoodPosition(Food *food);
void	drawFood(Food *food, Vector2 offset);
void	free_Snake(Snake *snake);
void	reset_Snake(Snake *snake);

#endif // SNAKE_H

