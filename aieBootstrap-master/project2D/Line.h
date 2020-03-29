#pragma once
#include "PhysicsObject.h"
#include "glm/glm.hpp"
class line : PhysicsObject
{
public:

	line(const glm::vec2& a_normal,
		 const float a_distance = 0.0f);

	const glm::vec2 get_normal() const;
	void set_normal(const glm::vec2& a_normal);

	const float get_distance() const;
	void set_distance(const float a_distance);

private:
	glm::vec2 normal;
	float distanceFromOrigin = 0.0f;
};

