#include "Quest_Manager.h"
#include "App.h"
#include "Quest1.h"
#include "Defs.h"
#include "Log.h"

QuestManager::QuestManager() : Module()
{
	name.Create("questmanager");
}

// Destructor
QuestManager::~QuestManager()
{}

// Called before render is available
bool QuestManager::Awake(pugi::xml_node& config)
{
	LOG("Loading Quest Manager");
	bool ret = true;

	//L13: TODO 6: Initialize Entities from XML 

	return ret;
}

// Called before quitting
bool QuestManager::CleanUp()
{
	bool ret = true;
	ListItem<Quest*>* item;
	item = questss.end;

	while (item != NULL && ret == true)
	{
		ret = item->data->CleanUp();
		item = item->prev;
	}

	questss.Clear();

	return ret;
}

Quest* QuestManager::CreateQuest(QuestType type, int id, SDL_Rect bounds)
{
	Quest* quests = nullptr;

	switch (type)
	{
	case QuestType::QUEST1:quests = new Quest1();
		break;
	case QuestType::UNKNOWN:
		break;
	default:
		break;
	}

	quests->Start();

	if (quests != nullptr) questss.Add(quests);

	return quests;
}

void QuestManager::DestroyQuest(Quest* quests)
{
	ListItem<Quest*>* item;

	for (item = questss.start; item != NULL; item = item->next)
	{
		if (item->data == quests) questss.Del(item);
	}
}

void QuestManager::AddQuests(Quest* quests)
{
	if (quests != nullptr) questss.Add(quests);
}

bool QuestManager::Update(float dt)
{
	accumulatedTime += dt;
	if (accumulatedTime >= updateMsCycle) doLogic = true;

	UpdateAll(dt, doLogic);

	if (doLogic == true)
	{
		accumulatedTime = 0.0f;
		doLogic = false;
	}

	return true;
}

bool QuestManager::UpdateAll(float dt, bool doLogic)
{
	bool ret = true;
	ListItem<Quest*>* item;
	Quest* pQuest = NULL;

	if (doLogic)
	{
		for (item = questss.start; item != NULL && ret == true; item = item->next)
		{
			pQuest = item->data;

			if (pQuest->active == false) continue;
			ret = item->data->Update(dt);
		}
	}

	return ret;
}

bool QuestManager::LoadState(pugi::xml_node& data)
{
	bool ret = true;

	ListItem<Quest*>* item;
	item = questss.start;

	while (item != NULL && ret == true)
	{
		ret = item->data->LoadState(data.child(item->data->name.GetString()));
		item = item->next;
	}

	return ret;
}

bool QuestManager::SaveState(pugi::xml_node& data)
{
	bool ret = true;

	ListItem<Quest*>* item;
	item = questss.start;

	while (item != NULL && ret == true)
	{
		data.append_child(item->data->name.GetString());
		ret = item->data->SaveState(data.child(item->data->name.GetString()));
		item = item->next;
	}

	return ret;
}

bool QuestManager::Draw() {

	bool ret = true;
	ListItem<Quest*>* item;
	Quest* pQuests = NULL;

	for (item = questss.start; item != NULL && ret == true; item = item->next)
	{
		pQuests = item->data;

		if (pQuests->active == false) continue;
		ret = item->data->Draw(app->render);
	}

	return ret;

}