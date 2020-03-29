#pragma once
#include "PhysicsScene.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "Gizmos.h"

enum ShapeType {
	LINE = 0,
	CIRCLE,
	AABB
};

class PhysicsObject
{
protected:
	PhysicsObject(ShapeType shapeID) 
	{
		shape_ID = shapeID;
	}

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {}
	
protected: 
	ShapeType shape_ID;
};