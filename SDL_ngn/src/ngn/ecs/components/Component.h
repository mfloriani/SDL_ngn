#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/entities/Entity.h"

namespace ngn
{
	struct NGN_API Component
	{
	public:
		Component() = default;
		
		Component(const Component& other) = default;
		Component& operator=(const Component& other) = default;

		Component(Component&& other) = default;			
		Component& operator=(Component&& other) = default;

		virtual ~Component() = default;
	public:
		EntityID owner{ INVALID_ENTITY_ID };
	};
}
