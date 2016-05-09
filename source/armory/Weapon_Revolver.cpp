#include "Weapon_Revolver.h"
#include "../Raven_Bot.h"
#include "misc/Cgdi.h"
#include "../Raven_Game.h"
#include "../Raven_Map.h"
#include "../lua/Raven_Scriptor.h"
#include "fuzzy/FuzzyOperators.h"

Revolver::Revolver(Raven_But* owner) :

Raven_Weapon(type_revolve,
script->GetInt("Revolver_DefaultRounds"),
script->GetInt("Revolver_MaxRoundsCarried"),
script->GetDouble())