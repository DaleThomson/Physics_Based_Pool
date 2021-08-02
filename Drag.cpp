#include "Drag.h"
#include <iostream>
#include <glm\glm.hpp>
using namespace glm;

void Drag::updateForce(Parameters * params, float dt)
{
	vec2 drag = params->velocity;
	float dragCoeff = length(drag);
	dragCoeff = k1 * dragCoeff + k2 * dragCoeff*dragCoeff;
	if (length(drag) != 0)
		drag = -dragCoeff * normalize(drag);
	//if (length(drag) + 0.5 < 1) {
	//	drag = vec2(0,0);
	//}
	params->addForce(drag);
}
