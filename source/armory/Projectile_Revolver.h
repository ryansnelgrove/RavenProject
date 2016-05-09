#ifndef REVBULLET_H
#define REVBULLET_H

#include "Raven_Projectile.h"

class Raven_Bot;

class RevBullet : public Raven_Projectile
{

private:

	void TestForImpact();

public:
	RevBullet(Raven_Bot* shooter, Vector2D target);

	void Render();

	void Update();
};
#endif