// raylib on SDL

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

static SDL_Window *window;
static SDL_Renderer *renderer;
static bool window_should_close;
static bool is_left_pressed;
static bool is_right_pressed;
static bool is_up_pressed;
static bool is_down_pressed;
static bool is_button_left_pressed;
static bool is_button_right_pressed;

#ifndef PI
#define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
#define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
#define RAD2DEG (180.0f/PI)
#endif

enum Flags
{
	FLAG_MSAA_4X_HINT,
};

enum Key
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
};

enum Button
{
	MOUSE_LEFT_BUTTON,
	MOUSE_RIGHT_BUTTON,
};

enum Color
{
	BLACK,
	WHITE,
	GREEN,
};

static void SetConfigFlags(enum Flags flags)
{
	if (flags == FLAG_MSAA_4X_HINT)
	{
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	}
}

static void InitWindow(int screenWidth, int screenHeight, const char *title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
}

static void CloseWindow(void)
{
	SDL_Quit();
}

static int MeasureText(const char *text, int fontWidth)
{
	return strlen(text) * fontWidth;
}

static void SetTargetFPS(int fps)
{
	(void)fps;
}

static bool WindowShouldClose()
{
	window_should_close = false;
	is_button_left_pressed = false;
	is_button_right_pressed = false;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			window_should_close = true;
			break;
		}
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_LEFT:
				is_left_pressed = true;
				break;
			case SDL_SCANCODE_RIGHT:
				is_right_pressed = true;
				break;
			case SDL_SCANCODE_UP:
				is_up_pressed = true;
				break;
			case SDL_SCANCODE_DOWN:
				is_down_pressed = true;
				break;
			}
			break;
		}
		case SDL_KEYUP:
		{
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_LEFT:
				is_left_pressed = false;
				break;
			case SDL_SCANCODE_RIGHT:
				is_right_pressed = false;
				break;
			case SDL_SCANCODE_UP:
				is_up_pressed = false;
				break;
			case SDL_SCANCODE_DOWN:
				is_down_pressed = false;
				break;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				is_button_left_pressed = true;
				break;
			case SDL_BUTTON_RIGHT:
				is_button_right_pressed = true;
				break;
			}
			break;
		}
		}
	}

	return window_should_close;
}

static bool IsKeyDown(enum Key key)
{
	switch (key)
	{
	case KEY_LEFT:
		return is_left_pressed;
	case KEY_RIGHT:
		return is_right_pressed;
	case KEY_UP:
		return is_up_pressed;
	case KEY_DOWN:
		return is_down_pressed;
	}
}

static bool IsMouseButtonPressed(enum Button button)
{
	switch (button)
	{
	case MOUSE_LEFT_BUTTON:
		return is_button_left_pressed;
	case MOUSE_RIGHT_BUTTON:
		return is_button_right_pressed;
	}
}

static Vector2 GetMousePosition(void)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return (Vector2)
	{
		x, y
	};
}

static int GetRandomValue(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

static void BeginDrawing(void)
{
}

static void EndDrawing(void)
{
	SDL_RenderPresent(renderer);
}

static void SetRenderColor(enum Color color)
{
	switch (color)
	{
	case BLACK:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		break;
	case WHITE:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		break;
	case GREEN:
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		break;
	}
}

static void ClearBackground(enum Color color)
{
	SetRenderColor(color);
	SDL_RenderClear(renderer);
}

static void DrawFPS(int x, int y)
{
	(void)x;
	(void)y;
}

static void DrawLineV(Vector2 vertexA, Vector2 vertexB, enum Color color)
{
	SetRenderColor(color);
	SDL_RenderDrawLine(renderer, vertexA.x, vertexA.y, vertexB.x, vertexB.y);
}

static void DrawRectangle(int x, int y, int w, int h, enum Color color)
{
	SetRenderColor(color);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderDrawRect(renderer, &rect);
}

static void DrawText(const char *text, int x, int y, int fontSize, enum Color color)
{
	(void)fontSize;
	SetRenderColor(color);
	SDL_Rect rect = { x, y, fontSize, fontSize };
	SDL_RenderDrawRect(renderer, &rect);
}
