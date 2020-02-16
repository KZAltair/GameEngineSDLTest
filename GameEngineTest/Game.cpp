#include "Game.h"
#include <iostream>

Game::Game()
{
	isRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
	return isRunning;
}

void Game::Initialize(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error init SDL." << std::endl;
		return;
	}

	window = SDL_CreateWindow(
		nullptr,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS
	);

	if (!window)
	{
		std::cerr << "Error creating a window.\n";
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cerr << "Error creating a renderer.\n";
	}

	isRunning = true;
	return;
}

void Game::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FrameTarget));
	float dt = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	//Clamp deltatime to a max value
	dt = (dt > 0.05f) ? 0.05f : dt;

	ticksLastFrame = SDL_GetTicks();
	movX += speed * dt;
}

void Game::ProcessInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
		{
			isRunning = false;
			break;
		
		}
		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				speed *= -1.0f;
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				speed *= -1.0f;
			}
			break;
		}
		default:
		{
			break;
		}
	}
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Set background color
	SDL_RenderClear(renderer);

	SDL_Rect test{ (int)movX, 200, 10, 10 };
	SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
	SDL_RenderFillRect(renderer, &test);
	SDL_RenderPresent(renderer); //Swapping buffers and present them on the screen
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
