// (c) Marco Gilardi, 2017
#pragma once
#include <glm\glm.hpp>
#include "Utils.h"
#include "Transform.h"

using namespace glm;

struct Parameters
{
private:
	float restitution;
	float inverseMass;
	vec2 forceAccum;

public:
	Transform transform;
	vec2 velocity;
	vec2 acceleration;
	//Parameters: mass, initial position, initial velocity, restitution
	Parameters(float mass, vec2 pos, vec2 vel, float restit = 0) : velocity(vel), restitution(restit), forceAccum(vec2(0)), acceleration(vec2(0)), inverseMass(INFINITY)
	{
		setInvMass(mass);
		transform.Translate(pos);
	}

	virtual ~Parameters() {}

	void setInvMass(float mass);
	float getInvMass();
	float getMass();
	void setRestitution(float rest);
	float getRestitution();

	vec2 getResultant();
	void clearAccumulator();
	void addForce(vec2& force);
};