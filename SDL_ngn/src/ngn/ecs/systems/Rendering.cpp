#include "ngnpch.h"
#include "Rendering.h"

#include "ngn/platform/Renderer.h"

#include "ngn/ecs/components/ComponentManager.h"
#include "ngn/ecs/components/Sprite.h"
#include "ngn/ecs/components/Transform.h"

namespace ngn
{
	
	void Rendering::OnStart()
	{
		
	}

	void Rendering::OnUpdate(float dt)
	{
		SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 0xFF);
		SDL_RenderClear(SDLRenderer);
		
		auto& sprites = COMPONENT_MGR(Sprite).GetComponents();
		for (auto& sprite : sprites)
		{
			//TODO: keep ref to tranforms inside system?
			auto transform = COMPONENT_MGR(Transform).GetComponent(sprite.owner);
			sprite.SetTo(transform->position.x, transform->position.y);
			Renderer::RenderTexture(sprite.GetTexture(), &sprite.GetSourceRect(), &sprite.GetDestinationRect());
		}

		SDL_RenderPresent(SDLRenderer);
	}

	void Rendering::OnQuit()
	{

	}
}