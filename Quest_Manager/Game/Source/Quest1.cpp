#include "Quests.h"
#include "App.h"
#include "Quest1.h"
#include "Collisions.h"
#include "Quest_Manager.h"

Quest1::Quest1() :Quest(QuestType::QUEST1)
{
	name.Create("Quest1");
}

Quest1::~Quest1()
{

}

bool Quest1::Awake(pugi::xml_node&)
{
	return false;
}

bool Quest1::Start()
{
	app->questManager->collider_M1 = app->collisions->AddCollider({ 200, 200, 50, 50 }, Collider::Type::QUEST1, (Module*)app->questManager);
	app->questManager->collider_M1_2 = app->collisions->AddCollider({500, 500, 50, 50}, Collider::Type::QUEST1_2, (Module*)app->questManager);

	return false;
}

bool Quest1::Update(float dt)
{
	SDL_Rect Quest1 = { 200, 200, 50, 50 };
	app->render->DrawRectangle(Quest1, 0, 0, 255);

	if (app->questManager->ques1 == true)
	{
		SDL_Rect Quest1 = { 500, 500, 50, 50 };
		app->render->DrawRectangle(Quest1, 0, 0, 255);

	}

	app->questManager->collider_M1->SetPos(200, 200);
	return false;
}

