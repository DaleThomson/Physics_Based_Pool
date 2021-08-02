// (c) Marco Gilardi, 2017
#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>

#include "BoundingSphere.h"
#include "PhysicsEntity.h"

using namespace std;
using namespace glm;

class Ball : public PhysicsEntity
{
private:
	float radius;
	vec3 color;

public:												// Cyan
	Ball(float radius, Parameters* params, vec3 color = vec3(1, 1, 1)) : radius(radius), color(color)
	{
		Ball::params = params;
		collider = new BoundingSphere(Ball::radius, params->transform.getPosition());
	}

	virtual ~Ball() {
	}

	void setColor(float r, float g, float b);

	vec2 getPosition();

	void update(float dt);

	void draw(int width, int height);
};