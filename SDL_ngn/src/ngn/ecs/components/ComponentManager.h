#pragma once

#include "ngn/Core.h"
#include "Component.h"

#define COMPONENT_MGR(C) ngn::ComponentManager<C>::Instance()

namespace ngn
{
	template<class T>
	class NGN_API ComponentManager
	{
	public:
		static ComponentManager& Instance()
		{
			static ComponentManager instance;
			return instance;
		}

		ComponentManager(const ComponentManager&) = delete;
		ComponentManager& operator=(const ComponentManager&) = delete;

		~ComponentManager()
		{
			delete m_components;
			m_components = nullptr;
		}

		template<typename... TArgs>
		void Add(EntityID id, TArgs&&... args)
		{
			//TODO: I should prevent adding the same component more than once

			T component(std::forward<TArgs>(args)...);
			component.owner = id;

			auto& comp = m_components->emplace_back(std::move(component));
			m_entityComponentMap[id] = &comp;
		}

		std::vector<T>& GetComponents() const
		{
			return *m_components;
		}
		
		T* GetComponent(EntityID id)
		{
			auto it = m_entityComponentMap.find(id);
			if (it != m_entityComponentMap.end())
			{
				return it->second;
			}
			return nullptr;
		}

	private:
		std::vector<T>* m_components;
		std::unordered_map<EntityID, T*> m_entityComponentMap;

		ComponentManager()
		{
			m_components = new std::vector<T>;
			m_components->reserve(COMP_MNGR_INIT_BUFFER);
		}

		

		

	};

}