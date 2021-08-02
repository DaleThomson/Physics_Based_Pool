// (c) Marco Gilardi, 2017

#pragma once

#include <glm\glm.hpp>
#include <vector>

using namespace std;
using namespace glm;

class PhysicsEntity;

class Contact
{
private:
	vector<PhysicsEntity*> objs;

	vec2 contactNormal;
	float restitution;
	float penetration;

	vec2 computeImpulse(float dt);
	void applyImpulse(vec2 impulse);

	void resolveVelocity(float dt);
	float resolveRestingContact(float dt);

public:
	
	void resolveInterpenetration(float dt);
	Contact() :penetration(0), restitution(0) {}
	virtual ~Contact() {}
	vec2 getContactNormal() const;

	void setObjects(vector<PhysicsEntity*>& objects);
	void setRestitution(float rest);
	void setPenetration(float penetration);
	void setContactNormal(vec2& normal);

	float computeSeparatingVelocity() const;
	void resolveContacts(float dt);
};