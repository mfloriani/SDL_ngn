#include "ngnpch.h"
#include "Transform.h"

namespace ngn
{
	Transform::Transform() : 
		Component(),
		position(glm::vec2()),
		direction(glm::vec2()),
		angle(0.0f)
	{

	}

	Transform::Transform(glm::vec2 pos) : 
		Component(),
		position(pos),
		direction(glm::vec2()),
		angle(0.0f)
	{

	}

	Transform::Transform(glm::vec2 pos, glm::vec2 dir) :
		Component(),
		position(pos),
		direction(dir),
		angle(0.0f)
	{

	}

	Transform::Transform(glm::vec2 pos, glm::vec2 dir, float angle) :
		Component(),
		position(pos),
		direction(dir),
		angle(angle)
	{

	}

	Transform::~Transform()
	{
		
	}
}