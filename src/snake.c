#include <snake.h>

Snake	*create_Snake(Vector2 position)
{
	Snake *snake = malloc(sizeof(Snake));
	if (!snake)
		return NULL;
	snake->position = position;
	//snake->direction = (Vector2){0, 0};
	snake->direction = RIGHT_DIRECTION;
	snake->size = 1;
	snake->tail = NULL;
	return snake;
}

void	changeSnakeDir(Snake *snake, Vector2 direction)
{
	/*if (Vector2Equals(Vector2Add(snake->direction, direction), (Vector2){0.0f, 0.0f}))
		return;*/
	snake->direction = direction;
}

void	snake_update_position(Snake *snake, Food *food)
{
	if (snake->position.x + snake->direction.x == food->position.x && snake->position.y + snake->direction.y == food->position.y)
	{
		printf("Snake ate the food\n");
		add_Tail(snake);
		changeFoodPosition(food);
	}
	Vector2 Headpos = snake->position;
	snake->position.x += snake->direction.x;
	snake->position.y += snake->direction.y;
	
	if (snake->position.x < 0 || snake->position.x >= SNAKE_GAME_TILES ||
		snake->position.y < 0 || snake->position.y >= SNAKE_GAME_TILES)
	{
		printf("Snake hit the wall\n");
		reset_Snake(snake);
		return;
	}
	Tail *tail = snake->tail;
	Vector2 lastpos = snake->position;
	while (tail)
	{
		if (tail != snake->tail && snake->position.x == tail->position.x && snake->position.y == tail->position.y)
		{
			printf("Snake hit itself\n");
			reset_Snake(snake);
			return;
		}
		Vector2 tmp = tail->position;
		if (tail == snake->tail)
			tail->position = Headpos;
		else
			tail->position = lastpos;
		lastpos = tmp;
		tail = tail->next;
	}
}

void	add_Tail(Snake *snake)
{
	Tail *newTail = malloc(sizeof(Tail));
	if (!newTail)
		return;
	newTail->position = (Vector2){snake->position.x + snake->direction.x, snake->position.y + snake->direction.y};
	newTail->next = snake->tail;
	snake->tail = newTail;
	snake->size++;
}

void	changeFoodPosition(Food *food)
{
	food->position.x = GetRandomValue(0, SNAKE_GAME_TILES - 1);
	food->position.y = GetRandomValue(0, SNAKE_GAME_TILES - 1);
	printf("New food position: %f, %f\n", food->position.x, food->position.y);
}

void	drawFood(Food *food, Vector2 offset)
{
	DrawRectangle(offset.x + (food->position.x * SNAKE_SIZE), offset.y + (food->position.y * SNAKE_SIZE), 
				SNAKE_SIZE, SNAKE_SIZE,
				FOOD_COLOR);
}

void	free_Snake(Snake *snake)
{
	Tail *tail = snake->tail;
	while (tail)
	{
		Tail *tmp = tail;
		tail = tail->next;
		free(tmp);
	}
	free(snake);
	snake = NULL;
}

void	reset_Snake(Snake *snake)
{
	Tail *tail = snake->tail;
	while (tail)
	{
		Tail *tmp = tail;
		tail = tail->next;
		free(tmp);
	}
	snake->tail = NULL;
	snake->size = 1;
	snake->position = (Vector2){20, 20};
	snake->direction = RIGHT_DIRECTION;
}
