#pragma once

#include "ngn/Core.h"

#include "sdl2/SDL.h"

namespace ngn
{
	//struct Animation;

	class NGN_API NgnAssetManager
	{
	public:
		NgnAssetManager();
		~NgnAssetManager();

		bool AddTexture(std::string id, std::string filePath);
		//bool AddFont(std::string id, std::string filePath, int size);
		//bool AddSound(std::string id, std::string filePath);
		//bool AddMusic(std::string id, std::string filePath);
		//bool AddAnimation(std::string id, std::vector<SDL_Rect> clips, uint32_t frameRate, bool loop);

		SDL_Texture* GetTexture(std::string id) const;
		//TTF_Font* GetFont(std::string id) const;
		//Mix_Chunk* GetSound(std::string id) const;
		//Mix_Music* GetMusic(std::string id) const;
		//Animation* GetAnimation(std::string id) const;

		bool HasTexture(std::string id) const;
		//bool HasFont(std::string id) const;
		//bool HasMusic(std::string id) const;
		//bool HasSound(std::string id) const;
		//bool HasAnimation(std::string id) const;

		void Free();

	private:
		std::unordered_map<std::string, SDL_Texture*> _textures;
		//std::unordered_map<std::string, TTF_Font*>	_fonts;
		//std::unordered_map<std::string, Mix_Chunk*>	_sounds;
		//std::unordered_map<std::string, Mix_Music*>	_musics;
		//std::unordered_map<std::string, Animation*>	_animations;
	};
}
