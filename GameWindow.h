#pragma once
#include <GL\glut.h>

class GameWindow
{
private:
	double clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;
	int width, height;
public:

	GameWindow(char* title, int width, int height, int posX, int posY) :width(width), height(height)
	{
		glutInitDisplayMode(GLUT_DOUBLE);
		glutInitWindowSize(width, height);
		glutInitWindowPosition(posX, posY);
		glutCreateWindow(title);
	}

	virtual ~GameWindow() {}

	void Reshape(GLsizei width, GLsizei height);
	int getWidth();
	int getHeight();
};