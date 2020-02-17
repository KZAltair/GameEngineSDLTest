#include "Game.h"
#include "AssetManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "KeyboardControlComponent.h"
#include <iostream>

EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;

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

	LoadLevel(0);

	isRunning = true;
	return;
}

void Game::LoadLevel(int levelNumber)
{
	//Here include new assets to asset manager list
	assetManager->AddTexture("tank-image", std::string("./assets/images/tank-big-right.png").c_str());
	assetManager->AddTexture("chopper-image", std::string("./assets/images/chopper-spritesheet.png").c_str());

	//Here add new entities to the entity manager
	Entity& tankEntity(manager.AddEntity("tank"));
	tankEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
	tankEntity.AddComponent<SpriteComponent>("tank-image");

	Entity& chopperEntity(manager.AddEntity("chopper"));
	chopperEntity.AddComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
	chopperEntity.AddComponent<SpriteComponent>("chopper-image", 2, 90, true, false);
	chopperEntity.AddComponent<KeyboardControlComponent>("up", "right", "down", "left", "space");
}

void Game::Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FrameTarget));
	float dt = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	//Clamp deltatime to a max value
	dt = (dt > 0.05f) ? 0.05f : dt;

	ticksLastFrame = SDL_GetTicks();

	//Here call manager.Update to update entities
	//Code here
	manager.Update(dt);
}

void Game::ProcessInput()
{
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
		}
		default:
		{
			break;
		}
	}
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255); //Set background color
	SDL_RenderClear(renderer);

	//Here call manager.Render()
	//Code goes here
	if (manager.HasNoEntities())
	{
		return;
	}

	manager.Render();

	SDL_RenderPresent(renderer); //Swapping buffers and present them on the screen
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
