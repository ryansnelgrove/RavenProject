#ifndef REVOLVER_H
#define REVOLVER_H
#pragma warning (disable:4786)

#include "Raven_Weapon.h"

class Revolver :
	public Raven_Weapon
{
private:
	void InitializeFuzzyModule();
public:
	Revolver(Raven_Bot* owner);
	
	void Render();

	void ShootAt(Vector2D pos);

	double GetDesirability(double DistToTarget);
};

#endif

