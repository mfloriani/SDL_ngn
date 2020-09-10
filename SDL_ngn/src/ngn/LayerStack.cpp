#include "ngnpch.h"
#include "LayerStack.h"

namespace ngn
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layers)
		{
			delete layer;
		}

	}

	void LayerStack::PushFirst(Layer* layer)
	{
		m_layers.emplace(m_layers.begin(), layer);
	}

	void LayerStack::PushLast(Layer* layer)
	{
		m_layers.emplace_back(layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);
		if (it != m_layers.end())
		{
			m_layers.erase(it);
		}
	}

}