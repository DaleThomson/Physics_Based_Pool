#include "Surface.h"
#include <iostream>

using namespace std;

void Surface::update(float dt)
{
	collider->update(params->transform);
}

void Surface::draw(int width, int height)
{
	vec2 position = params->transform.getPosition();

	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)

	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(2 * radii.x * aspectRatio / width, 2 * radii.y / height);
	glVertex2f(-2 * radii.x * aspectRatio / width, 2 * radii.y / height);
	glVertex2f(-2 * radii.x * aspectRatio / width, -2 * radii.y / height);
	glVertex2f(2 * radii.x * aspectRatio / width, -2 * radii.y / height);
	glEnd();
}

void Surface::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}