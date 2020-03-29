#include "PhysicsScene.h"
#include "Rigidbody.h"
#include <iostream>
#include <list>
PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
	while (!objects.empty())
	{
		objects.erase(objects.end() - 1);
	}
}

void PhysicsScene::addObject(PhysicsObject* actor)
{
	objects.push_back(actor);
}

void PhysicsScene::removeObject(PhysicsObject* actor)
{
	auto location = std::find(objects.begin(), objects.end(), actor);
	objects.erase(location);
	delete actor;
	actor = nullptr;
}

void PhysicsScene::update(float deltaTime)
{
	static std::list<PhysicsObject*> dirty;

	
	accumulatedTime += deltaTime;

	while (accumulatedTime >= m_timeStep)
	{
		for (auto pObject : objects)
		{
			pObject->fixedUpdate(m_gravity, m_timeStep);
		}

		accumulatedTime -= m_timeStep;

		for (auto pObject : objects)
		{
			for (auto pOther : objects)
			{
				if (pObject == pOther)
					continue;
				if (std::find(dirty.begin(), dirty.end(), pObject) != dirty.end() &&
					std::find(dirty.begin(), dirty.end(), pOther) != dirty.end())
					continue;

				Rigidbody* pRigid = dynamic_cast<Rigidbody*>(pOther);
				if (pRigid->checkCollision(pObject))
				{
					pRigid->applyForceToObject(dynamic_cast<Rigidbody*>(pObject),
						pRigid->get_velocity() * pRigid->getMass());
					dirty.push_back(pRigid);
					dirty.push_back(pOther);
				}
			}
			
		}
		dirty.clear();
	}
}

void PhysicsScene::updateGizmos()
{
	for (auto pObject : objects)
	{
		pObject->makeGizmo();
	}
}

void PhysicsScene::debugScene()
{
	int count = 0;
	for (auto pObject : objects)
	{
		std::cout << count << " : ";
		pObject->debug();
		count++;
	}
}
