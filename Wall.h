#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>
#include <iostream>
#include "Transform.h"
#include "Entity.h"
#include <algorithm>

#include "PhysicsEntity.h"
#include "AABB.h"

using namespace std;
using namespace glm;

class Wall : public PhysicsEntity
{
private:
	vec2 radii;
	vec3 color;

public:												
	Wall(vec2 r, Parameters* params, vec3 color = vec3(1, 1, 0))
		: radii(r), color(color)
	{
		Wall::params = params;
		collider = new AABB(radii, params->transform);
	}

	virtual ~Wall() {
	}

	void setColor(float r, float g, float b);

	void update(float dt);

	void draw(int width, int height);
};