#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>
#include <iostream>
#include "Transform.h"
#include "Entity.h"
#include "Ball.h"
#include <algorithm>

using namespace std;
using namespace glm;

class Cue : public Entity
{
private:

	float MAX_CUE_DISTANCE = 150;
	float MIN_CUE_DISTANCE = 90;

	vec2 radius;
	vec2 velocity;
	vec2 acceleration;
	vec3 color;

	Ball * targetBall;
	float rotation = 0;
	float alpha;
	float distance = MIN_CUE_DISTANCE;
	float force = 0;

	void VelocityVerletSolver(float dt);
	Transform transform;
	void move(vec2 translation);

	
	void hideCue(); // Hides pool cue
	void showCue(); // Shows pool cue

public:
	Cue(vec2 r, Ball* cueBall, vec2& vel, vec2& acc) : color(vec3(1.0f, 1.0f, 1.0f)),
		radius(r), velocity(vel), acceleration(acc)
	{
		targetBall = cueBall;
	}

	virtual ~Cue() {
		delete targetBall;
	}

	void chargeShot(float increase);

	void resetCue();

	float getForce();

	float setForce();

	vec2 getOrientation();

	void setRotation(float rot);

	vec2 getPosition();

	vec2 getRadius();

	vec2 getVelocity();

	vec2 getAcceleration();

	vec2 setAcceleration(vec2 acc);

	vec2 setVelocity(vec2 vel);

	void setColor(float r, float g, float b);

	void setTarget(Ball* target); // Method to set ball target

	void setPosition(vec2 pos); // Sets cue position, honestly, without this, there isn't a god.

								// --------- Methods that implement the Entity parent class --------- 
	void update(float dt);
	void draw(int width, int height);
};