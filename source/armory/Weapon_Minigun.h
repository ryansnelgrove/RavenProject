#ifndef MINIGUN_H
#define MINIGUN_H

#include "Raven_Weapon.h"

class Minigun :
	public Raven_Weapon
{
private:
	void InitializeFuzzyModule();

	double m_dSpread;
public:
	Minigun(Raven_Bot* owner);
	
	void Render();

	void ShootAt(Vector2D pos);

	double GetDesirability(double DistToTarget);
};

#endif

