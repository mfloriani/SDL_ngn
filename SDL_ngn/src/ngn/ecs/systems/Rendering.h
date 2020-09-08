#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/systems/System.h"


namespace ngn
{
	
	class NGN_API Rendering : public System
	{
	public:
		

		virtual void OnStart() override;
		virtual void OnUpdate(float dt) override;
		virtual void OnQuit() override;

	private:
		
	};

}