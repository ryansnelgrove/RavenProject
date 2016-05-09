#ifndef SMG_H
#define SMG_H
#pragma warning (disable:4786)

#include "Raven_Weapon.h"


class Raven_Bot;


class SMG : public Raven_Weapon
{
private:
	
	void InitializeFuzzyModule();

public:

	SMG(Raven_Bot* owner);

	void Render();

	void ShootAt(Vector2D pos);

	double GetDesirability(double DistToTarget);
};

#endif
