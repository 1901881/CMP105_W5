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
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 3.f);
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	if (moving) {
		current->animate(dt);
		setTextureRect(current->getCurrentFrame());
	}
}

void Mario::handleInput(float dt)
{

	if (moving
		&& !(input->isKeyDown(sf::Keyboard::Right))
		&& !(input->isKeyDown(sf::Keyboard::Left))
		&& !(input->isKeyDown(sf::Keyboard::Up))
		&& !(input->isKeyDown(sf::Keyboard::Down))) {
		moving = false;
		current->reset();
		setTextureRect(current->getCurrentFrame());
	}

	//Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		//input->setKeyUp(sf::Keyboard::Right);
		moving = true;
		current = &walk;
		current->setFlipped(false);
		move(200 * dt, 0);
	}
	//Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		//input->setKeyUp(sf::Keyboard::Left);
		moving = true;
		current = &walk;
		walk.setFlipped(true);
		move(-200 * dt, 0);
	}
	//Up
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		//input->setKeyUp(sf::Keyboard::Up);
		moving = true;
		current = &duck;
		//duck.animate(dt);
		move(0, 200 * dt);

	}
	//Down
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		//input->setKeyUp(sf::Keyboard::Down);
		moving = true;
		current = &swim;
		//swim.animate(dt);
		move(0, -200 * dt);
	}
}
