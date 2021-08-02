// (c) Marco Gilardi, 2017

#include "Game.h"
#include "Solver.h"
#include "VerletSolver.h"
#include "CollisionDetector.h"
#include <random>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;
using namespace glm;

void Game::Load()
{

	window = new GameWindow("Pool", 640, 800, 50, 50);

	solver = new VerletSolver();

	resolver = new ContactResolver();

	srand(time(NULL));

	drag = new Drag(dx, dy);

	gravity = new Gravity(vec2(0,-20));
	
	forceRegistry = new ForceRegistry();

	// Surface
	Parameters* params = new Parameters(0, vec2(200, 400), vec2(0), .0f);
	surface = new Surface(vec2(600, 600), params);
	surface->setColor(0.0f, 0.4f, 0.0f);
	dynObjs.push_back(surface);

#pragma region LoadBalls
	// Cue Ball
	params = new Parameters(10, vec2(320, 600), vec2(0), .0f);
	cueBall = new Ball(10, params);
	cueBall->setColor(1.0f, 1.0f, 1.0f);
	forceRegistry->add(cueBall, drag);
	dynObjs.push_back(cueBall);

	params = new Parameters(10, vec2(320, 240), vec2(0), .0f);
	Ball* Ball1 = new Ball(10, params);
	Ball1->setColor(0.0f, 1.0f, 1.0f);
	forceRegistry->add(Ball1, drag);
	dynObjs.push_back(Ball1);

	params = new Parameters(10, vec2(310, 225), vec2(0), .0f);
	Ball* Ball2 = new Ball(10, params);
	Ball2->setColor(0.5f, 0.9f, 0.6f);
	forceRegistry->add(Ball2, drag);
	dynObjs.push_back(Ball2);

	params = new Parameters(10, vec2(330, 225), vec2(0), .0f);
	Ball* Ball3 = new Ball(10, params);
	Ball3->setColor(1.0f, 1.0f, 0.0f);
	forceRegistry->add(Ball3, drag);
	dynObjs.push_back(Ball3);

	params = new Parameters(10, vec2(300, 205), vec2(0), .0f);
	Ball* Ball4 = new Ball(10, params);
	Ball4->setColor(1.0f, 1.0f, 0.0f);
	forceRegistry->add(Ball4, drag);
	dynObjs.push_back(Ball4);

	params = new Parameters(10, vec2(320, 205), vec2(0), .0f);
	Ball* Ball5 = new Ball(10, params);
	Ball5->setColor(0.0f, 0.0f, 0.0f);
	forceRegistry->add(Ball5, drag);
	dynObjs.push_back(Ball5);

	params = new Parameters(10, vec2(340, 205), vec2(0), .0f);
	Ball* Ball6 = new Ball(10, params);
	Ball6->setColor(0.0f, 1.0f, 0.0f);
	forceRegistry->add(Ball6, drag);
	dynObjs.push_back(Ball6);

	params = new Parameters(10, vec2(330, 185), vec2(0), .0f);
	Ball* Ball7 = new Ball(10, params);
	Ball7->setColor(0.2f, 1.0f, 0.5f);
	forceRegistry->add(Ball7, drag);
	dynObjs.push_back(Ball7);

	params = new Parameters(10, vec2(310, 185), vec2(0), .0f);
	Ball* Ball8 = new Ball(10, params);
	Ball8->setColor(0.5f, 0.4f, 0.9f);
	forceRegistry->add(Ball8, drag);
	dynObjs.push_back(Ball8);

	params = new Parameters(10, vec2(290, 185), vec2(0), .0f);
	Ball* Ball9 = new Ball(10, params);
	Ball9->setColor(0.5f, 0.2f, 0.9f);
	forceRegistry->add(Ball9, drag);
	dynObjs.push_back(Ball9);

	params = new Parameters(10, vec2(350, 185), vec2(0), .0f);
	Ball* Ball10 = new Ball(10, params);
	Ball10->setColor(0.3f, 0.7f, 0.5f);
	forceRegistry->add(Ball10, drag);
	dynObjs.push_back(Ball10);

	params = new Parameters(10, vec2(280, 165), vec2(0), .0f);
	Ball* Ball11 = new Ball(10, params);
	Ball11->setColor(0.3f, 0.7f, 0.5f);
	forceRegistry->add(Ball11, drag);
	dynObjs.push_back(Ball11);

	params = new Parameters(10, vec2(300, 165), vec2(0), .0f);
	Ball* Ball12 = new Ball(10, params);
	Ball12->setColor(0.7f, 0.4f, 0.9f);
	forceRegistry->add(Ball12, drag);
	dynObjs.push_back(Ball12);

	params = new Parameters(10, vec2(320, 165), vec2(0), .0f);
	Ball* Ball13 = new Ball(10, params);
	Ball13->setColor(0.1f, 0.4f, 0.7f);
	forceRegistry->add(Ball13, drag);
	dynObjs.push_back(Ball13);

	params = new Parameters(10, vec2(340, 165), vec2(0), .0f);
	Ball* Ball14 = new Ball(10, params);
	Ball14->setColor(0.9f, 0.2f, 0.7f);
	forceRegistry->add(Ball14, drag);
	dynObjs.push_back(Ball14);

	params = new Parameters(10, vec2(360, 165), vec2(0), .0f);
	Ball* Ball15 = new Ball(10, params);
	Ball15->setColor(0.5f, 0.5f, 0.9f);
	forceRegistry->add(Ball15, drag);
	dynObjs.push_back(Ball15);
#pragma endregion
#pragma region LoadWalls
	params = new Parameters(0, vec2(-60, 650), vec2(0), .0f);
	Wall* wall = new Wall(vec2(20, 180), params);
	wall->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall);

	params = new Parameters(0, vec2(-60, 150), vec2(0), .0f);
	Wall* wall2 = new Wall(vec2(20, 180), params);
	wall2->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall2);

	params = new Parameters(0, vec2(700, 150), vec2(0), .0f);
	Wall* wall3 = new Wall(vec2(20, 180), params);
	wall3->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall3);

	params = new Parameters(0, vec2(700, 650), vec2(0), .0f);
	Wall* wall4 = new Wall(vec2(20, 180), params);
	wall4->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall4);

	params = new Parameters(0, vec2(310, -80), vec2(0), .0f);
	Wall* wall5 = new Wall(vec2(300, 20), params);
	wall5->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall5);

	params = new Parameters(0, vec2(310, 880), vec2(0), .0f);
	Wall* wall6 = new Wall(vec2(300, 20), params);
	wall6->setColor(0.6f, 0.12f, 0.01f);
	dynObjs.push_back(wall6);
#pragma endregion

	cue = new Cue(vec2(80, 10), cueBall, vec2(0, 0), vec2(0, 0));
	cue->setColor(1.0f, 0.85f, 0.42f);
	cue->setVelocity(vec2(0, 0));
	gameEntities.push_back(cue);
}

void Game::ReshapeWindow(int width, int height)
{
	window->Reshape(width, height);
}

void Game::GetCollisionsData()
{

	for (vector<PhysicsEntity*>::iterator it_obj1 = dynObjs.begin(); it_obj1 < dynObjs.end() - 1; ++it_obj1)
	{

		for (vector<PhysicsEntity*>::iterator it_obj2 = it_obj1 + 1; it_obj2 < dynObjs.end(); ++it_obj2) // we make sure that we check a collision between the same objcts only once
		{
			CollisionData * data = CollisionDetector::CheckCollision(*it_obj1, *it_obj2);
			if (data != nullptr)
				collisionData.push_back(unique_ptr<CollisionData>(data));
		}
	}
}


void Game::Update(float dt) {

	forceRegistry->updateForces(dt); //Update forces and computes their resultant
	solver->integrate(dynObjs, dt);	 //Updates Position, Velocity and Acceleration of each object
	forceRegistry->clear();			 //Set the resultant of the forces of each object to 0

	// Press 'Left' to decrease surface drag
	if (GetKeyState(VK_LEFT) & 0x8000)
	{

		for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end() - 1; ++it)
		{
			Ball* ball = dynamic_cast<Ball*>(*it);
			if (ball != nullptr)
			{
				forceRegistry->remove(ball, drag);
				dx -= 0.01f;
				dy -= 0.01f;
				drag = new Drag(dx, dy);
				forceRegistry->add(ball, drag);				
			}
		}
	}

	// Press 'Right' to increase surface drag
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end() - 1; ++it)
		{
			Ball* ball = dynamic_cast<Ball*>(*it);
			if (ball != nullptr)
			{
				forceRegistry->remove(ball, drag);
				dx += 0.01f;
				dy += 0.01f;
				drag = new Drag(dx, dy);
				forceRegistry->add(ball, drag);
			}
		}
	}

	// Press 'Up' to increase ball's mass
	if (GetKeyState(VK_UP) & 0x8000)
	{
		for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end() - 1; ++it)
		{
			Ball* ball = dynamic_cast<Ball*>(*it);
			if (ball != nullptr)
			{
				mass += 1.0f;
				ball->setParams(new Parameters(mass, vec2(ball->getPosition()), ball->getParams()->velocity, .0f));
			}
		}
	}

	// Press 'Down' to increase ball's mass
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end() - 1; ++it)
		{
			Ball* ball = dynamic_cast<Ball*>(*it);
			if (ball != nullptr)
			{
				mass -= 0.01f;
				ball->setParams(new Parameters(mass, vec2(ball->getPosition()), ball->getParams()->velocity, .0f));
			}
		}
	}
	if (GetKeyState(VK_SPACE) < 0)
	{
		cue->chargeShot(1.0f);
	}
	else {
		if (cue->getForce() > 0) 
		{
			cuehit = new CueHit(cue->getForce() * 500, vec2(-cue->getOrientation().x, -cue->getOrientation().y));
			cout << "FIRING SHOT :: Force; " << cue->getForce() << " | Dir; " << -cue->getOrientation().x << " " << -cue->getOrientation().y << endl;
			forceRegistry->add(cueBall, cuehit);
			forceRegistry->add(cueBall, drag);
			cue->resetCue();
		}
		forceRegistry->remove(cueBall, drag);
		forceRegistry->remove(cueBall, cuehit);
		cuehit = new CueHit(0, vec2(0,0));
		drag = new Drag(dx, dy);
		forceRegistry->add(cueBall, cuehit);
		forceRegistry->add(cueBall, drag);

	}
	
	// Press 'A' to move cue left
	if (GetKeyState('A') < 0)
	{
		cue->setRotation(0.1);
	}

	// Press 'D' to move cue right
	if (GetKeyState('D') < 0)
	{
		cue->setRotation(-0.1);
	}

	cout << "mass: " << mass << " DragX: " << dx << " DragY: " << dy << endl;

	for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
	{
		(*it)->update(dt);			//Updates other quantities in each object
	}

	for (vector<Entity*>::iterator it = gameEntities.begin(); it < gameEntities.end(); it++)
	{
		(*it)->update(dt);			//Updates none physics objects
	}
	
	GetCollisionsData();			//Check for colliison

	while (!collisionData.empty())
	{
		unique_ptr<CollisionData>& data = collisionData.back();
		resolver->setNumIterations(data->maxNumContacts - data->numContactsLeft);
		if (data->contact != nullptr)
			resolver->resolveContacts(data->contact, data->maxNumContacts, dt);

		collisionData.pop_back(); //remove the last element from the vector, being it a smart pointer delete is called automatically on it
	}
}

void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear the color buffer
	glMatrixMode(GL_MODELVIEW);		// To operate on the model-view matrix

	for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
	{
		(*it)->draw(window->getWidth(), window->getHeight()); // Draws physics objects
	}

	for (vector<Entity*>::iterator it = gameEntities.begin(); it < gameEntities.end(); it++)
	{
		(*it)->draw(window->getWidth(), window->getHeight()); // Draws non physics objects
	}

	glutSwapBuffers();				// Swap front and back buffers (of double buffered mode)
}