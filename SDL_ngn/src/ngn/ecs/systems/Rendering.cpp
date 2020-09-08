#include "ngnpch.h"
#include "Rendering.h"

#include "ngn/platform/NgnTextureManager.h"
#include "ngn/platform/NgnWindow.h"

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
		SDL_SetRenderDrawColor(NgnWindow::Renderer(), 0, 0, 0, 0xFF);
		SDL_RenderClear(NgnWindow::Renderer());
		
		auto& sprites = COMPONENT_MGR(Sprite).GetComponents();
		for (auto& sprite : sprites)
		{
			//TODO: keep ref to tranforms inside system?
			auto transform = COMPONENT_MGR(Transform).GetComponent(sprite.owner);

			auto& tex = sprite.texture;
			tex.m_dstrect.x = transform->position.x;
			tex.m_dstrect.y = transform->position.y;

			NgnTextureManager::Render(tex);
		}

		SDL_RenderPresent(NgnWindow::Renderer());
	}

	void Rendering::OnQuit()
	{

	}
}