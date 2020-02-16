#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>

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

public:
	static constexpr int WindowWidth = 800;
	static constexpr int WindowHeight = 600;
};
