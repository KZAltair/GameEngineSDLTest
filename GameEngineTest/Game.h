#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <glm.hpp>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "SDL2_ttf.lib")


class Game
{
public:
	Game();
	~Game();
	bool IsRunning() const;
	void Initialize(int width, int height);
	void Update();
	void ProcessInput();
	void Render();
	void Destroy();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	glm::vec2 pos = { 100.0f, 100.0f };
	glm::vec2 vel = { 0.0f, 0.0f };
	float speed = 20.0f;
	float ticksLastFrame = 0.0f;

public:
	static constexpr int WindowWidth = 800;
	static constexpr int WindowHeight = 600;
	static constexpr int FPS = 60;
	static constexpr int FrameTarget = 1000 / FPS;
};
