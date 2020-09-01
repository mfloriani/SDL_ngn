#pragma once

#include "ngn/Core.h"
#include "ngn/ecs/entities/Entity.h"

namespace ngn
{
	class NGN_API Component
	{
		//friend class ComponentManager;

	public:
		Component() : m_owner(0) 
		{
			NGN_CORE_TRACE("Component()");
		}
		
		Component(const Component& other)
		{
			NGN_CORE_TRACE("Component(&)");
		}

		Component(Component&& other) noexcept
		{
			NGN_CORE_TRACE("Component(&&)");
		}

		Component& operator=(const Component& other)
		{
			NGN_CORE_TRACE("Component&=");
			return *this;
		}

		Component& operator=(const Component&& other)
		{
			NGN_CORE_TRACE("Component&&=");
			return *this;
		}

		virtual ~Component()
		{
			//NGN_CORE_TRACE("Component destructor");
		}

		inline EntityID GetOwner() const { return m_owner; }

	private:
		EntityID m_owner;
	};
}
