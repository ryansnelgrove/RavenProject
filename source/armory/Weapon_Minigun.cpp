#include "Weapon_Minigun.h"
#include "../Raven_Bot.h"
#include "misc/Cgdi.h"
#include "../Raven_Game.h"
#include "../Raven_Map.h"
#include "../lua/Raven_Scriptor.h"
#include "fuzzy/FuzzyOperators.h"

Minigun::Minigun(Raven_Bot* owner) :
			Raven_Weapon(type_minigun,
				script->GetInt("Minigun_DefaultRounds"),
				script->GetInt("Minigun_MaxRoundsCarried"),
				script->GetDouble("Minigun_FiringFreq"),
				script->GetDouble("Minigun_IdealRange"),
				script->GetDouble("Slug_MaxSpeed"),
				owner),
			m_dSpread(script->GetDouble("Minigun_Spread"))
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

inline void Minigun::ShootAt(Vector2D pos)
{
	if (isReadyForNextShot())
	{
		double deviation = RandInRange(0, m_dSpread) + RandInRange(0, m_dSpread) - m_dSpread;

		Vector2D AdjustedTarget = pos - m_pOwner->Pos();

		Vec2DRotateAroundOrigin(AdjustedTarget, deviation);

		m_pOwner->GetWorld()->AddBelt(m_pOwner, pos);

		UpdateTimeWeaponIsNextAvailable();

		m_pOwner->GetWorld()->GetMap()->AddSoundTrigger(m_pOwner, script->GetDouble("Minigun_SoundRange"));
	}
}

double Minigun::GetDesirability(double DistToTarget)
{
	m_FuzzyModule.Fuzzify("DistToTarget", DistToTarget);

	m_dLastDesirabilityScore = m_FuzzyModule.DeFuzzify("Desirability", FuzzyModule::max_av);

	return m_dLastDesirabilityScore;
}

void Minigun::InitializeFuzzyModule()
{
	FuzzyVariable& DistToTarget = m_FuzzyModule.CreateFLV("DistToTarget");

	FzSet& Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet& Target_Medium = DistToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet& Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 1000);

	FuzzyVariable& Desirability = m_FuzzyModule.CreateFLV("Desirability");

	FzSet& VeryDesirable = Desirability.AddRightShoulderSet("VeryDesirable", 50, 75, 100);
	FzSet& Desirable = Desirability.AddTriangularSet("Desirable", 25, 50, 75);
	FzSet& Undesirable = Desirability.AddLeftShoulderSet("Undesirable", 0, 25, 50);

	m_FuzzyModule.AddRule(Target_Close, VeryDesirable);
	m_FuzzyModule.AddRule(Target_Medium, VeryDesirable);
	m_FuzzyModule.AddRule(Target_Far, Desirable);
}

void Minigun::Render()
{
	m_vecWeaponVBTrans = WorldTransform(m_vecWeaponVB,
		m_pOwner->Pos(),
		m_pOwner->Facing(),
		m_pOwner->Facing().Perp(),
		m_pOwner->Scale());

	gdi->BlackPen();
	gdi->RedBrush();

	gdi->ClosedShape(m_vecWeaponVBTrans);
}
