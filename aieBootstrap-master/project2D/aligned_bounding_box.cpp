#include "aligned_bounding_box.h"
#include <cmath>
aligned_bounding_box::aligned_bounding_box(const glm::vec2& position, const glm::vec2& a_extents) :
										   Rigidbody(ShapeType::AABB, position), extents(a_extents)
{
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