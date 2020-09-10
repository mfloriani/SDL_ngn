#pragma once

#include "Core.h"
#include "Layer.h"


namespace ngn
{

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushFirst(Layer* layer);
		void PushLast(Layer* layer);

		void PopLayer(Layer* layer);

		inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_layers.end(); }

	private:
		std::vector<Layer*> m_layers;
	};

}