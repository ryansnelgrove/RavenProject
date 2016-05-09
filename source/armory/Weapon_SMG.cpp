#include "Weapon_SMG.h"
#include "../Raven_Bot.h"
#include "misc/Cgdi.h"
#include "../Raven_Game.h"
#include "../Raven_Map.h"
#include "../lua/Raven_Scriptor.h"
#include "fuzzy/FuzzyOperators.h"

SMG::SMG(Raven_Bot* owner) :

			Raven_Weapon(type_smg,
						 script->GetInt("SMG_DefaultRounds"),
						 script->GetInt("SMG_MaxRoundsCarried"),
						 script->GetDouble("SMG_FiringFreq"),
						 script->GetDouble("SMG_IdealRange"),
						 script->GetDouble("Bullet_MaxSpeed"),
						 owner)
{
	const int NumWeaponVerts = 4;
	const Vector2D weapon[NumWeaponVerts] = { 
		Vector2D(0, -1),
		Vector2D(10, -1),
		Vector2D(10, 1),
		Vector2D(0, 1) };

	for (int vtx = 0; vtx < NumWeaponVerts; ++vtx)
	{
		m_vecWeaponVB.push_back(weapon[vtx]);
	}

	InitializeFuzzyModule();
}

inline void SMG::ShootAt(Vector2D pos)
{
	if (isReadyForNextShot())
	{
		m_pOwner->GetWorld()->AddBullet(m_pOwner, pos);

		UpdateTimeWeaponIsNextAvailable();

		m_pOwner->GetWorld()->GetMap()->AddSoundTrigger(m_pOwner, script->GetDouble("SMG_SoundRange"));
	}
}

double SMG::GetDesirability(double DistToTarget)
{
	m_FuzzyModule.Fuzzify("DistToTarget", DistToTarget);

	m_dLastDesirabilityScore = m_FuzzyModule.DeFuzzify("Desirability", FuzzyModule::max_av);

	return m_dLastDesirabilityScore;
}

void SMG::InitializeFuzzyModule()
{
	FuzzyVariable& DistToTarget = m_FuzzyModule.CreateFLV("DistToTarget");

	FzSet& Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet& Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet& Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 1000);

	FuzzyVariable& Desirability = m_FuzzyModule.CreateFLV("Desirability");

	FzSet& VeryDesirable = Desirability.AddRightShoulderSet("VeryDesirable", 50, 75, 100);
	FzSet& Desirable = Desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet& Undesirable = Desirability.AddLeftShoulderSet("Undesirable", 0, 25, 50);

	m_FuzzyModule.AddRule(Target_Close, Desirable);
	m_FuzzyModule.AddRule(Target_Medium, Desirable);
	m_FuzzyModule.AddRule(Target_Far, Undesirable);
}

void SMG::Render()
{
	m_vecWeaponVBTrans = WorldTransform(m_vecWeaponVB,
		m_pOwner->Pos(),
		m_pOwner->Facing(),
		m_pOwner->Facing().Perp(),
		m_pOwner->Scale());

	gdi->DarkGreenPen();

	gdi->ClosedShape(m_vecWeaponVBTrans);
}