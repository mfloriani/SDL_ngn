#include "ngnpch.h"
#include "Rendering.h"

#include "ngn/Application.h"

#include "ngn/platform/NgnTextureManager.h"
#include "ngn/platform/NgnWindow.h"

namespace ngn
{
	//Rendering::Rendering(Application* app) :
	//	m_ownerApp(app)
	//{
	//	
	//}

	void Rendering::OnStart()
	{
		//m_spriteCMgr = m_ownerApp->m_spriteCMgr.get();
	}

	void Rendering::OnUpdate(float dt)
	{
		SDL_SetRenderDrawColor(NgnWindow::Renderer(), 0, 0, 0, 0xFF);
		SDL_RenderClear(NgnWindow::Renderer());
		
		auto& sprites = Application::GetSpriteCMgr()->GetComponents();
		for (auto& sprite : sprites)
		{
			NgnTextureManager::Render(sprite.GetTexture());
		}

		SDL_RenderPresent(NgnWindow::Renderer());
	}

	void Rendering::OnQuit()
	{

	}
}