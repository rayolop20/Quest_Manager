#ifndef __QUESTMANAGER_H__
#define __QUESTMANAGER_H__

#include "Module.h"
#include "Quests.h"

#include "List.h"

class Textures;
class Audio;
class Collisions;
class PathFinding;
class Render;

class QuestManager : public Module
{
public:

	QuestManager();

	// Destructor
	virtual ~QuestManager();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	bool Update(float dt);

	bool Draw();

	// Called before quitting
	bool CleanUp();

	// Additional methods
	Quest* CreateQuest(QuestType type, int id, SDL_Rect bounds);

	void DestroyQuest(Quest* quests);

	void AddQuests(Quest* quests);

	bool UpdateAll(float dt, bool doLogic);

	bool LoadState(pugi::xml_node& data);

	bool SaveState(pugi::xml_node& data);

	void OnCollision(Collider* c1, Collider* c2);
public:

	List<Quest*> questss;


	Input* input;
	Textures* tex;
	Audio* audio;
	Collisions* collisions;
	PathFinding* path;
	Render* render;

	Collider* collider = nullptr;

	float accumulatedTime = 0.0f;
	float updateMsCycle = 0.0f;
	bool doLogic = false;
};

#endif // __QUESTMANAGER_H__
