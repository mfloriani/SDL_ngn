#pragma once

#include "Event.h"

namespace ngn
{
	class NGN_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApp);
	};
}