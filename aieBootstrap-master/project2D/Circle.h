#pragma once
#include "Rigidbody.h"

class circle : public Rigidbody
{
public:

	circle(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour);

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);

	const float get_radius() const;
	void set_radius(const float radius);
	glm::vec4 getColour() { return m_colour; }

	virtual void debug() override
	{

	}

protected: 
	glm::vec4 m_colour;
	float m_radius;

	
};

