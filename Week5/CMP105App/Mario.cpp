#include "Mario.h"

Mario::Mario()
{
	//walk
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);
	//swim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);
	//duck
	swim.addFrame(sf::IntRect(0, 41, 16, 20));
	swim.addFrame(sf::IntRect(16, 41, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Mario::handleInput(float dt)
{
	//Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		//input->setKeyUp(sf::Keyboard::Right);
		walk.setFlipped(false);
		move(200 * dt, 0);
	}
	//Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		//input->setKeyUp(sf::Keyboard::Left);
		walk.setFlipped(true);
		move(-200 * dt, 0);
	}
	//Up
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		//input->setKeyUp(sf::Keyboard::Up);
		move(0, -200 * dt);

	}
	//Down
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		//input->setKeyUp(sf::Keyboard::Down);
		move(0, 200 * dt);
	}
}
