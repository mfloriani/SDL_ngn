#pragma once
#include "ngnpch.h"
#include "ngn/Core.h"

namespace ngn
{
	#define ASSET_MANAGER(type) ngn::AssetManager<type>::Instance()

	template<class T>
	class AssetManager
	{
	public:
		~AssetManager()
		{
			Free();
		}

		inline static AssetManager& Instance()
		{
			static AssetManager instance;
			return instance;
		}

		template<typename... TArgs>
		bool Add(std::string id, TArgs&&... args)
		{
			if (Has(id)) return false;

			T* asset = new T(std::forward<TArgs>(args)...);
			m_assets.insert(std::make_pair(id, asset));

			return true;
		}

		bool Has(std::string id) const
		{
			if (m_assets.find(id) != m_assets.end())
			{
				return true;
			}
			return false;
		}

		T* Get(std::string id) const
		{
			auto asset = m_assets.find(id);
			if (asset != m_assets.end())
			{
				return asset->second;
			}
			return nullptr;
		}

		//bool AddTexture(std::string id, std::string filePath);
		//bool AddFont(std::string id, std::string filePath, int size);
		//bool AddSound(std::string id, std::string filePath);
		//bool AddMusic(std::string id, std::string filePath);
		//bool AddAnimation(std::string id, std::vector<SDL_Rect> clips, uint32_t frameRate, bool loop);

		//SDL_Texture* GetTexture(std::string id) const;
		//TTF_Font* GetFont(std::string id) const;
		//Mix_Chunk* GetSound(std::string id) const;
		//Mix_Music* GetMusic(std::string id) const;
		//Animation* GetAnimation(std::string id) const;

//		bool HasTexture(std::string id) const;
		//bool HasFont(std::string id) const;
		//bool HasMusic(std::string id) const;
		//bool HasSound(std::string id) const;
		//bool HasAnimation(std::string id) const;

		void Free()
		{
			for (auto const& [id, asset] : m_assets)
			{
				delete asset;
			}
			m_assets.clear();
		}

	private:
		AssetManager() { NGN_CORE_INFO("AssetManager singleton created"); }
		AssetManager(const AssetManager& other) = delete;
		AssetManager& operator=(const AssetManager& other) = delete;

		std::unordered_map<std::string, T*> m_assets;
		//std::unordered_map<std::string, TTF_Font*>	_fonts;
		//std::unordered_map<std::string, Mix_Chunk*>	_sounds;
		//std::unordered_map<std::string, Mix_Music*>	_musics;
		//std::unordered_map<std::string, Animation*>	_animations;
	};
}
