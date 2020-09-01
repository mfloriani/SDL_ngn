#include "ngnpch.h"
#include "Transform.h"

namespace ngn
{
	Transform::Transform() : 
		Component(),
		m_position(glm::vec2()),
		m_direction(glm::vec2()),
		m_angle(0.0f)
	{

	}

	Transform::~Transform()
	{
		
	}
}