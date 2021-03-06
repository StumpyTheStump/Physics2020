#include "aligned_bounding_box.h"
#include <cmath>
aligned_bounding_box::aligned_bounding_box(const glm::vec2& position, const glm::vec2& a_extents, const glm::vec2& a_velocity, const float a_mass) :
										   Rigidbody(ShapeType::AABB, position, a_velocity, a_mass), extents(a_extents)
{
}

void aligned_bounding_box::makeGizmo()
{
	aie::Gizmos::add2DAABB(m_position, extents * 0.5f, glm::vec4(0, 1, 1, 1));
}

bool aligned_bounding_box::checkCollision(PhysicsObject* pOther)
{
	return false;
}

	

const glm::vec2 aligned_bounding_box::get_position() const
{
	return m_position;
}



void aligned_bounding_box::set_position(const glm::vec2& a_position)
{
	m_position = a_position;
}

const glm::vec2 aligned_bounding_box::get_extents() const
{
	return extents;
}

void aligned_bounding_box::set_extents(const glm::vec2& a_extents)
{
	extents = { abs(a_extents.x), abs(a_extents.y) };
}

const float aligned_bounding_box::get_width() const
{
	return m_width;
}

const float aligned_bounding_box::get_height() const
{
	return m_height;
}

const glm::vec2 aligned_bounding_box::get_min() const
{
	return m_position - 0.5f * extents;
}

const glm::vec2 aligned_bounding_box::get_max() const
{
	return m_position + 0.5f * extents;
}