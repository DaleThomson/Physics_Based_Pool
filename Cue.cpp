#include "Cue.h"
#include <iostream>
#include <Windows.h>
#include <GL\glut.h>

using namespace std;

void Cue::VelocityVerletSolver(float dt)
{
	//move(dt * velocity + 0.5f * dt * dt * acceleration);
	//vec2 velInBetween = velocity + 0.5f * dt * acceleration;
	//velocity = velInBetween + 0.5f * acceleration;
}

void Cue::move(vec2 translation)
{
	transform.Translate(translation);
}

float Cue::getForce()
{
	return force;
}

//float Cue::setForce(float newForce)
//{
//	force = newForce;
//	return newForce;
//}

vec2 Cue::getOrientation()
{
	return transform.getOrientation();
}

void Cue::update(float dt)
{
	
	VelocityVerletSolver(dt);
	
	setPosition(vec2(targetBall->getPosition().x,
		targetBall->getPosition().y)+distance*transform.getOrientation());
	
	//// Press 'A' to move cue left
	//if (GetKeyState('A') < 0) {
	//	vec2 v(transform.getPosition());
	//	rotation = 0.1;
	//	setPosition(vec2(0,0));
	//	transform.Rotate(rotation);
	//	setPosition(v);
	//}

	//// Press 'D' to move cue right
	//if (GetKeyState('D') < 0) {
	//	vec2 v(transform.getPosition());
	//	rotation = -0.1;
	//	setPosition(vec2(0, 0));
	//	transform.Rotate(rotation);
	//	setPosition(v);
	//}

	// Press 'Space' to power up shot
	//if (GetKeyState(VK_SPACE) < 0) {
	//	if (distance <= MAX_CUE_DISTANCE) {
	//		cout << distance << endl;
	//		distance += 1;
	//	}
	//}
	//else {
	//	distance = MIN_CUE_DISTANCE;
	//}

	alpha = normalize(targetBall->getPosition() - transform.getPosition()).x;
	if (targetBall->getPosition().y < transform.getPosition().y)
		alpha = -alpha;
	//cout << "Ori: " << transform.getOrientation().x << " " << transform.getOrientation().y << endl;
}

void Cue::draw(int width, int height)
{
	vec2 position = transform.getPosition();

	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)
	glRotatef(180 * acos(alpha) / 3.1415f, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);

	vec2 u(2 * radius.x * aspectRatio / width, 2 * radius.y / height);

	glVertex2f(u.x, u.y);

	vec2 v(-2 * radius.x * aspectRatio / width, 2 * radius.y / height);

	glVertex2f(v.x, v.y);

	vec2 w(-2 * radius.x * aspectRatio / width, -2 * radius.y / height);

	glVertex2f(w.x, w.y);

	vec2 z(2 * radius.x * aspectRatio / width, -2 * radius.y / height);

	glVertex2f(z.x, z.y);
	glEnd();
}

void Cue::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}

void Cue::setTarget(Ball* target)
{
	targetBall = target;
}

void Cue::chargeShot(float increase)
{
	if (distance <= MAX_CUE_DISTANCE) {
		distance += increase;
		force += increase;
	}
}

void Cue::resetCue()
{
	distance = MIN_CUE_DISTANCE;
	force = 0;
}

void Cue::setRotation(float rot)
{
	vec2 v(transform.getPosition());
	rotation = rot;
	setPosition(vec2(0, 0));
	transform.Rotate(rotation);
	setPosition(v);
}

void Cue::setPosition(vec2 pos)
{
	vec2 v(pos - transform.getPosition());
	move(v);
}

vec2 Cue::getPosition()
{
	return transform.getPosition();

}

vec2 Cue::getRadius()
{
	return radius;
}

vec2 Cue::setVelocity(vec2 vel)
{
	velocity = vel;
	return velocity;
}

vec2 Cue::setAcceleration(vec2 acc)
{
	acceleration = acc;
	return acceleration;
}

vec2 Cue::getAcceleration()
{
	return acceleration;
}

vec2 Cue::getVelocity()
{
	return velocity;
}