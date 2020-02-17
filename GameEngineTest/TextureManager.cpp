#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);
	if (!surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destRect, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, texture, &sourceRect, &destRect, 0.0f, nullptr, flip);
}
