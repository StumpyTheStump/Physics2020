#include "Line.h"

line::line(const glm::vec2& a_normal /* = { 0.0f, 1.0f }*/,
			const float a_distance /*= 0.0f*/) :
	normal(a_normal),
	distanceFromOrigin(a_distance),
	PhysicsObject(ShapeType::LINE)
{
	set_normal(normal);
}

const glm::vec2 line::get_normal() const
{
	return normal;
}

void line::set_normal(const glm::vec2& a_normal)
{
	if (glm::length(a_normal) == 0)
	{
		
	}
	else
	{
		glm::normalize(a_normal);
	}
}

const float line::get_distance() const
{
	return distanceFromOrigin;
}

void line::set_distance(const float a_distance)
{
	distanceFromOrigin = a_distance;
}