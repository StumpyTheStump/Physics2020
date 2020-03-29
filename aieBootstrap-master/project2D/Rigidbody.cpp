#include "Rigidbody.h"

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 position,
					 glm::vec2 velocity, float mass) : PhysicsObject(shapeID),
					 m_position(position), m_velocity(velocity), m_mass(mass)
{
}

//Rigidbody(ShapeType shapeID, const glm::vec2& position)
	//: m_position(position), PhysicsObject(shapeID) {}

void Rigidbody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	applyForce(gravity * m_mass * timeStep);
	m_position += m_velocity * timeStep;
}

void Rigidbody::debug()
{
}

void Rigidbody::applyForce(glm::vec2 force)
{
	m_velocity += force / m_mass;
}

void Rigidbody::applyForceToObject(Rigidbody* object2, glm::vec2 force)
{
	object2->applyForce(force);
	this->applyForce(-force);
}


