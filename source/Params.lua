
-------------------------[[ General game parameters ]]-------------------------
-------------------------------------------------------------------------------

--the number of bots the game instantiates

NumBots   = 3

--this is the maximum number of search cycles allocated to *all* current path
-- planning searches per update
MaxSearchCyclesPerUpdateStep = 1000

--the name of the default map
StartMap = "maps/de_dust.map"

--cell space partitioning defaults
NumCellsX = 10
NumCellsY = 10

--how long the graves remain on screen
GraveLifetime = 5


-------------------------[[ bot parameters ]]----------------------------------
-------------------------------------------------------------------------------

Bot_MaxHealth = 100
Bot_MaxSpeed  = 1.5
Bot_Mass      = 1
Bot_MaxForce  = 1.0
Bot_MaxHeadTurnRate = 0.2
Bot_Scale       = 0.8

--special movement speeds (unused)
Bot_MaxSwimmingSpeed = Bot_MaxSpeed * 0.2
Bot_MaxCrawlingSpeed = Bot_MaxSpeed * 0.6

--the number of times a second a bot 'thinks' about weapon selection
Bot_WeaponSelectionFrequency = 2

--the number of times a second a bot 'thinks' about changing strategy
Bot_GoalAppraisalUpdateFreq = 4

--the number of times a second a bot updates its target info
Bot_TargetingUpdateFreq = 2

--the number of times a second the triggers are updated
Bot_TriggerUpdateFreq = 8

--the number of times a second a bot updates its vision
Bot_VisionUpdateFreq = 4

--note that a frequency of -1 will disable the feature and a frequency of zero
--will ensure the feature is updated every bot update


--the bot's field of view (in degrees)
Bot_FOV = 180

--the bot's reaction time (in seconds)
Bot_ReactionTime = 0.2

--how long (in seconds) the bot will keep pointing its weapon at its target
--after the target goes out of view
Bot_AimPersistance = 1

--how accurate the bots are at aiming. 0 is very accurate, (the value represents
-- the max deviation in range (in radians))
Bot_AimAccuracy = 0.0

--how long a flash is displayed when the bot is hit
HitFlashTime = 0.2

--how long (in seconds) a bot's sensory memory persists
Bot_MemorySpan = 5

--goal tweakers
Bot_HealthGoalTweaker     = 1.0
Bot_ShotgunGoalTweaker    = 1.0
Bot_RailgunGoalTweaker    = 1.0
Bot_RocketLauncherTweaker = 1.0
Bot_AggroGoalTweaker      = 1.0


-------------------------[[ steering parameters ]]-----------------------------
-------------------------------------------------------------------------------

--use these values to tweak the amount that each steering force
--contributes to the total steering force
SeparationWeight       =   10.0;
WallAvoidanceWeight     =  10.0;
WanderWeight            =  1.0;
SeekWeight              =  0.5;
ArriveWeight            =  1.0;

--how close a neighbour must be before an agent considers it
--to be within its neighborhood (for separation)
ViewDistance            =  15.0;

--max feeler length
WallDetectionFeelerLength = 25.0 * Bot_Scale;

--used in path following. Determines how close a bot must be to a waypoint
--before it seeks the next waypoint
WaypointSeekDist   = 5;

-------------------------[[ giver-trigger parameters ]]-----------------------------
-------------------------------------------------------------------------------

--how close a bot must be to a giver-trigger for it to affect it
DefaultGiverTriggerRange = 10

--how many seconds before a giver-trigger reactivates itself
Health_RespawnDelay  = 10
Weapon_RespawnDelay  = 15



-------------------------[[ weapon parameters ]]-------------------------------
-------------------------------------------------------------------------------

Blaster_FiringFreq       = 3
Blaster_MaxSpeed		 = 5
Blaster_DefaultRounds    = 0 --not used, a blaster always has ammo
Blaster_MaxRoundsCarried = 0 --as above
Blaster_IdealRange		   = 50
Blaster_SoundRange	     = 100

Belt_MaxSpeed    = 20
Belt_Mass        = 0.1
Belt_MaxForce    = 100.0
Belt_Scale	 = Bot_Scale
Belt_Damage	 = 1

Bolt_MaxSpeed    = 5
Bolt_Mass        = 1
Bolt_MaxForce    = 100.0
Bolt_Scale       = Bot_Scale
Bolt_Damage      = 1

Bullet_MaxSpeed  = 15
Bullet_Mass      = 0.5
Bullet_MaxForce  = 100.0
Bullet_Scale     = Bot_Scale
Bullet_Damage    = 2

Minigun_FiringFreq	= 10
Minigun_DefaultRounds   = 50
Minigun_MaxRoundsCarried = 50
Minigun_IdealRange	= 100
Minigun_SoundRange	= 400
Minigun_Spread		= 0.25

RevBullet_MaxSpeed = 10
RevBullet_Mass	   = 1
RevBullet_MaxForce = 100
RevBullet_Scale	   = Bot_Scale
RevBullet_Damage   = 2

Revolver_FiringFreq	= 1
Revolver_DefaultRounds  = 6
Revolver_MaxRoundsCarried = 12
Revolver_IdealRange	= 75
Revolver_SoundRange	= 50

RocketLauncher_FiringFreq       = 1.5
RocketLauncher_DefaultRounds      = 15
RocketLauncher_MaxRoundsCarried = 50
RocketLauncher_IdealRange  = 150
RocketLauncher_SoundRange  = 400

Rocket_BlastRadius = 20
Rocket_MaxSpeed    = 3
Rocket_Mass        = 1
Rocket_MaxForce    = 10.0
Rocket_Scale       = Bot_Scale
Rocket_Damage      = 10
Rocket_ExplosionDecayRate = 2.0   --how fast the explosion occurs (in secs)


RailGun_FiringFreq       = 1
RailGun_DefaultRounds      = 15
RailGun_MaxRoundsCarried = 50
RailGun_IdealRange  = 200
RailGun_SoundRange  = 400

Slug_MaxSpeed    = 5000
Slug_Mass        = 0.1
Slug_MaxForce    = 10000.0
Slug_Scale       = Bot_Scale
Slug_Persistance = 0.2
Slug_Damage      = 10



ShotGun_FiringFreq       = 1
ShotGun_DefaultRounds      = 15
ShotGun_MaxRoundsCarried = 50
ShotGun_NumBallsInShell  = 10
ShotGun_Spread           = 0.05
ShotGun_IdealRange  = 100
ShotGun_SoundRange  = 400

SMG_FiringFreq  = 7.5
SMG_DefaultRounds = 30
SMG_MaxRoundsCarried = 60
SMG_IdealRange = 75
SMG_SoundRange = 100

Pellet_MaxSpeed    = 5000
Pellet_Mass        = 0.1
Pellet_MaxForce    = 1000.0
Pellet_Scale       = Bot_Scale
Pellet_Persistance = 0.1
Pellet_Damage      = 1


  