#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <glm.hpp>
#include "EntityManager.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")

class AssetManager;

class Game
{
public:
	Game();
	~Game();
	bool IsRunning() const;
	void Initialize(int width, int height);
	void LoadLevel(int levelNumber);
	void Update();
	void ProcessInput();
	void Render();
	void Destroy();
private:
	SDL_Window* window;
	bool isRunning;
	float ticksLastFrame = 0.0f;

public:
	static SDL_Renderer* renderer;
	static AssetManager* assetManager;
	static constexpr int WindowWidth = 800;
	static constexpr int WindowHeight = 600;
	static constexpr int FPS = 60;
	static constexpr int FrameTarget = 1000 / FPS;
};
