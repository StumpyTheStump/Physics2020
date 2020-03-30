#pragma once
#include "PhysicsObject.h"
#include "Rigidbody.h"

class aligned_bounding_box : public Rigidbody
{
public:

	aligned_bounding_box(const glm::vec2& a_position,
						 const glm::vec2& a_extents,
						 const glm::vec2& a_velocity,
						 float a_mass);

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);

	const glm::vec2 get_position() const;
	void set_position(const glm::vec2& a_position);

	const glm::vec2 get_extents() const;
	void set_extents(const glm::vec2& a_extents);

	const float get_width() const;
	const float get_height() const;

	const glm::vec2 get_min() const;
	const glm::vec2 get_max() const;

private:
	union
	{
		glm::vec2 extents;
		struct
		{
			float m_width;
			float m_height;
		};
	};
};

