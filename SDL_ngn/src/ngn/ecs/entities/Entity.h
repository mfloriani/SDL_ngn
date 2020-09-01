#pragma once

#include "ngn/Core.h"

namespace ngn
{
	typedef unsigned int EntityID;

	class NGN_API EntityManager
	{
	public:
		static EntityID GetNewID()
		{
			static EntityID id = 0;
			return ++id;
		}
	};
}