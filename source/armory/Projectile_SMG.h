#ifndef BULLET_H
#define BULLET_H
#pragma once
#include "Raven_Projectile.h"

class Bullet : public Raven_Projectile
{
private:
	void TestForImpact();
public:
	Bullet(Raven_Bot* shooter, Vector2D target);

	void Render();

	void Update();
};
#endif

