#pragma once

#include "Core.h"
#include "events/Event.h"

namespace ngn
{

	class NGN_API Layer
	{
	public:
		Layer() {}
		~Layer() {}

		virtual void OnStart() = 0;
		virtual void OnQuit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Event& e) = 0;
	};

}