#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/components/Component.h"
#include "glm/glm.hpp"

namespace ngn
{
	struct NGN_API Transform : public Component
	{
	public:
		Transform();
		Transform(glm::vec2 pos);
		Transform(glm::vec2 pos, glm::vec2 dir);
		Transform(glm::vec2 pos, glm::vec2 dir, float angle);
		~Transform();

	public:
		glm::vec2 position;
		glm::vec2 direction;
		float	  angle;
	};
}