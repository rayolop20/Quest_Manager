#include "Quests.h"
#include "App.h"
#include "Quest1.h"
#include "Collisions.h"

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
	collider = app->collisions->AddCollider({ 200, 200, 50, 50 }, Collider::Type::QUEST1, (Module*)app->questManager);

	return false;
}

bool Quest1::Update(float dt)
{
	SDL_Rect Quest1 = { 200, 200, 50, 50 };
	app->render->DrawRectangle(Quest1, 0, 0, 255);

	return false;
}

