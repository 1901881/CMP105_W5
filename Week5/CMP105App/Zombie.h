#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Animation.h"
class Zombie : public GameObject, private Input
{
public:
	Zombie();
	~Zombie();
	void update(float dt) override;
	void handleInput(float dt) override;

protected:
	Animation walk;
};

