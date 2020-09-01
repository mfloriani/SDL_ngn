#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/components/Component.h"
#include "glm/glm.hpp"

namespace ngn
{
	class NGN_API Transform : public Component
	{
	public:
		Transform();
		~Transform();

	private:
		glm::vec2 m_position;
		glm::vec2 m_direction;
		float	  m_angle;
	};
}