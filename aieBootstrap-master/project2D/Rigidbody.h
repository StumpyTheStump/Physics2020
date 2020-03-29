#pragma once
#include "PhysicsScene.h"
#include "glm/glm.hpp"
class Rigidbody : public PhysicsObject
{
public:
	~Rigidbody() {};

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug();
	void applyForce(glm::vec2 force);
	void applyForceToObject(Rigidbody* object2, glm::vec2 force);

	virtual bool checkCollision(PhysicsObject* pOther) = 0;

	glm::vec2 get_position() const  {return m_position; }
	glm::vec2 get_velocity() const { return m_velocity; }
	float getMass() const { return m_mass; }
	

	

protected:
	Rigidbody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float mass);

	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
};

