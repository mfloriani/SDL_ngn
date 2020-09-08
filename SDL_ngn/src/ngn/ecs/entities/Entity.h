#pragma once

#include "ngn/Core.h"

namespace ngn
{
	typedef unsigned int EntityID;
	constexpr EntityID INVALID_ENTITY_ID{ 0 };

	class NGN_API EntityManager
	{
	public:
		static EntityID GetNewID()
		{
			static EntityID id = INVALID_ENTITY_ID;
			return ++id;
		}
	};
}