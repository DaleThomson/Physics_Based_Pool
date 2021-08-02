#include "CueHit.h"

void CueHit::updateForce(Parameters * obj, float dt)
{
	obj->addForce(force * direction * obj->getMass());
}

void CueHit::setForce(float newForce, vec2 dir)
{
	force = newForce;
	direction = dir;
}
