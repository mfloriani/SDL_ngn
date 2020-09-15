#include "ngnpch.h"
#include "ngn/Core.h"

#include "ngn/ecs/components/Sprite.h"

namespace ngn
{
	#define SDLRenderer Renderer::Instance().GetSDLRenderer()

	class NGN_API Renderer
	{
	public:
		~Renderer();
		void Quit();

		static Renderer& Instance()
		{
			static Renderer instance;
			return instance; 
		}

		inline static void RenderTexture(Texture* tex, SDL_Rect* src, SDL_Rect* dst)
		{
			SDL_RenderCopyEx(SDLRenderer, tex->GetSDLTexture(), src, dst, 0.0, NULL, SDL_RendererFlip::SDL_FLIP_NONE);
		}

		inline SDL_Renderer* GetSDLRenderer() const { return m_renderer; }
		
	private:
		Renderer();
		Renderer(const Renderer& other) = delete;
		Renderer& operator=(const Renderer& other) = delete;

	private:
		SDL_Renderer* m_renderer;
	};
}