
#include <stdio.h>
#include <game.h>
#include <string.h>

int main(void)
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	SetTargetFPS(FPS);

	Snake	*snake = create_Snake((Vector2){20, 20});
	Food	food = {{0.0f, 0.0f}};
	size_t	frameCounter = 0;
	Vector2 offset = {BORDER_SIZE, BORDER_SIZE + HEADER_SIZE};
	char	headerBuf[64];

	changeFoodPosition(&food);// food start pos
	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_RIGHT)) changeSnakeDir(snake, RIGHT_DIRECTION);
        if (IsKeyDown(KEY_LEFT)) changeSnakeDir(snake, LEFT_DIRECTION);
        if (IsKeyDown(KEY_UP)) changeSnakeDir(snake, UP_DIRECTION);
        if (IsKeyDown(KEY_DOWN)) changeSnakeDir(snake, DOWN_DIRECTION);

		frameCounter++;
		if (frameCounter >= 1.0f / SPEED * 60)
		{
			snake_update_position(snake, &food);
			frameCounter = 0;
		}
		sprintf(headerBuf, "Score: %llu", snake->size);

		BeginDrawing();
            ClearBackground(BG_COLOR);
			// Paint Header
			DrawRectangle(0, 0, // X, Y
				WIN_WIDTH, HEADER_SIZE, // Width, Height
				HEADER_COLOR); // Color
			// Write Header
			DrawText(headerBuf, BORDER_SIZE, BORDER_SIZE / 2, 20, BLACK);
			// Paint Border
			DrawRectangle(0, HEADER_SIZE, // X, Y
				WIN_WIDTH, WIN_HEIGHT, // Width, Height
				BORDER_COLOR); // Color
			DrawRectangle(BORDER_SIZE, BORDER_SIZE + HEADER_SIZE, // X, Y
				WIN_WIDTH - BORDER_SIZE * 2, WIN_HEIGHT - BORDER_SIZE * 2 - HEADER_SIZE, // Width, Height
				BLACK); // Color

			draw_Snake(snake, offset);
			drawFood(&food, offset);

        EndDrawing();
	}

	CloseWindow();

	return 0;
}

