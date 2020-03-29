#include "Circle.h"
#include "collision_manager.h"
#include <cmath>


circle::circle(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) :
	Rigidbody(ShapeType::CIRCLE, position, velocity, mass),
	m_radius(radius),
	m_colour(colour)
{
}

void circle::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 32, m_colour);
}

bool circle::checkCollision(PhysicsObject* pOther)
{
	return collision_manager::circle_vs_circle(*this, (circle&)*pOther);
}

const float circle::get_radius() const
{
	return m_radius;
}

void circle::set_radius(const float radius)
{
	m_radius = abs(radius);
}


