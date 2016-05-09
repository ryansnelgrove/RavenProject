#ifndef BELT_H
#define BELT_H

#include "Raven_Projectile.h"
class Belt : public Raven_Projectile
{
private:
	void TestForImpact();
public:
	Belt(Raven_Bot* shooter, Vector2D target);

	void Render();

	void Update();
};
#endif