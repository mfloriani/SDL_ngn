#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/components/Component.h"

namespace ngn
{
	class NGN_API System
	{
	public:
		System() {}
		virtual ~System() {}

		virtual void OnStart() = 0;
		virtual void OnUpdate(float dt) = 0;
		virtual void OnQuit() = 0;

		void Register()
		{

		}

		void Deregister()
		{

		}

	private:
		std::vector<Component> m_components;
	};
}