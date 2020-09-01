#pragma once

#include "ngn/Core.h"
#include "Component.h"

namespace ngn
{
	template<class T>
	class ComponentManager
	{
	public:
		ComponentManager()
		{
			m_components = new std::vector<T>;
			m_components->reserve(COMP_MNGR_INIT_BUFFER);
		}

		~ComponentManager()
		{
			delete m_components;
			m_components = nullptr;
		}

		void Add(T&& component)
		{
			m_components->emplace_back(std::move(component));
		}

		const std::vector<T>& GetComponents() const
		{
			return *m_components;
		}

	private:
		std::vector<T>* m_components;
		//std::unordered_map<EntityID, std::vector<Component>> m_entityComponents;
		//std::unordered_map<const std::type_info, >

	};

}