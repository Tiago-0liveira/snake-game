#include <snake.h>

void	draw_Snake(Snake *snake, Vector2 offset)
{
	drawSnakeHead(snake, offset);
	Tail *tail = snake->tail;
	while (tail)
	{
		DrawRectangle(offset.x + (tail->position.x * SNAKE_SIZE), offset.y + (tail->position.y * SNAKE_SIZE), 
				SNAKE_SIZE, SNAKE_SIZE, 
				SNAKE_COLOR);
		// Draw two stripes inside the rectangle to make it look like a snake
		DrawRectangle(offset.x + (tail->position.x * SNAKE_SIZE) + 2, offset.y + (tail->position.y * SNAKE_SIZE) + 2, 
				SNAKE_SIZE - 4, SNAKE_SIZE - 4, 
				SNAKE_HEAD_COLOR);
		
		
		
		tail = tail->next;
	}
}

void	drawSnakeHead(Snake *snake, Vector2 offset)
{
	DrawRectangle(offset.x + (snake->position.x * SNAKE_SIZE), offset.y + (snake->position.y * SNAKE_SIZE), 
				SNAKE_SIZE, SNAKE_SIZE, 
				SNAKE_HEAD_COLOR);
	Vector2 SnakeCenter = Vector2Add(Vector2Add(Vector2Scale(snake->position, SNAKE_SIZE), offset), (Vector2){SNAKE_SIZE / 2, SNAKE_SIZE / 2});
	Vector2 EyesPosCenter = Vector2Add(Vector2Scale(snake->direction, SNAKE_SIZE * 0.5), SnakeCenter);

	Vector2 eyeOffset = Vector2Scale((Vector2) {-snake->direction.y, snake->direction.x}, SNAKE_SIZE * 0.25);
    Vector2 leftEyePos = Vector2Add(EyesPosCenter, eyeOffset);
    Vector2 rightEyePos = Vector2Subtract(EyesPosCenter, eyeOffset);

    DrawCircleV(leftEyePos, 4, DARKBLUE);
    DrawCircleV(rightEyePos, 4, DARKBLUE);
}

