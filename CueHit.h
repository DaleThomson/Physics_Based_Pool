#pragma once
#include <glm\glm.hpp>
#include "Parameters.h"
#include "ForceGenerator.h"

class CueHit : public ForceGenerator
{
private:
	float force;
	vec2 direction;
public:
	CueHit(float force, vec2 direction) : force(force), direction(direction) {}
	virtual ~CueHit() {}
	void updateForce(Parameters* obj, float dt);
	void setForce(float newForce, vec2 dir);

};