#ifndef __QUESTS_H__
#define __QUESTS_H__

#include "Point.h"
#include "SString.h"
#include "Input.h"
#include "Render.h"

struct Collider;

enum class QuestType
{
	QUEST1,
	UNKNOWN
};

class Quest
{
public:

	Quest(QuestType type) : type(type), active(true) {}

	virtual bool Start()
	{
		return true;
	}

	virtual bool Update(float dt)
	{
		return true;
	}

	virtual bool Draw(Render* render)
	{
		return true;
	}

	virtual bool CleanUp()
	{
		return true;
	}

	virtual bool LoadState(pugi::xml_node&)
	{
		return true;
	}

	virtual bool SaveState(pugi::xml_node&)
	{
		return true;
	}

	void Quest::Enable()
	{
		if (!active)
		{
			active = true;
			Start();
		}
	}

	void Quest::Disable()
	{
		if (active)
		{
			active = false;
			CleanUp();
		}
	}

	virtual void OnCollision(Collider* c1, Collider* c2) {

	};

public:

	SString name;
	QuestType type;
	bool active = true;

	iPoint position;
	bool renderable = false;
	//SDL_Texture* texture;
};

#endif // __QUESTS_H__