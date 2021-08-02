#pragma once
#include <vector>
#include <memory>
#include <GL\glut.h>
#include "GameWindow.h"
#include "Entity.h"
#include "Ball.h"
#include "Cue.h"
#include "Wall.h"
#include "Surface.h"
#include "ForceRegistry.h"
#include "Solver.h"
#include "ContactResolver.h"
#include "CollisionData.h"
#include "Drag.h"
#include "Gravity.h"
#include "CueHit.h"

using namespace std;
#pragma once

class Game
{
private:
	float dx = 0.3f;
	float dy = 0.3f;
	float fx = 0.3f;
	float fy = 0.3f;
	float mass = 10.0f;
	Drag* drag;
	Gravity* gravity;
	Surface* surface;
	CueHit* cuehit;
	vector<unique_ptr<CollisionData>> collisionData;
	vector<Entity*> gameEntities;
	GameWindow* window;
	ForceRegistry* forceRegistry = nullptr;
	vector<PhysicsEntity*> dynObjs;	
	Solver* solver = nullptr;
	Cue* cue;

	Ball* cueBall;
	ContactResolver* resolver = nullptr;
	void GetCollisionsData();

public:
	void Load();
	void Render();
	void Update(float dt);
	void ReshapeWindow(int width, int height);


	Game() {};
	virtual ~Game()
	{
		if (solver != nullptr) delete solver;
		if (window != nullptr) delete window;
		if (forceRegistry != nullptr) delete forceRegistry;
		if (resolver != nullptr) delete resolver;

		delete cuehit;

		for (vector<PhysicsEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
			delete *it;
	}
};