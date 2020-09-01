#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/systems/System.h"

namespace ngn
{

	class NGN_API Physics : public System
	{
	public:
		

	private:


		// Inherited via System
		virtual void OnUpdate(float dt) override;

	};

}