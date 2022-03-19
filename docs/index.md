## Quest Manager

# What is a Quest?
The quests are activities/objectives/actions that the player has to do either alone or cooperatively, to obtain something, either material (objects) or intangible (Continue in the game or experience to level up).

# Type of Quest
* Kill quests: these quests are characterized by the fact that you have to kill enemies or things to complete them, it could be killing enemies, animals or structures, it depends on the game.
* Collect quest: These quests are characterized by the fact that they are collection missions. Normally these quests ask you to collect plants, or objects, but at the same time  usualy can be related to the Quill Quest since you may have to collect animal skin or meat.
* Protection Quest: these questsv are characterized by the fact that you have to protect someone, having to overcome the missions without a character dying.
* Combo Quest: these quests are characterized by the fact that you have to press certain keys in a certain order and time (making a combo), The Quick time events could be classified as combo quests, because if you fail, you can lose. 
* Mixed Quest: These are quests that have one or more types of missions already mentioned above.

![Different Quests Types](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Quest_images.png)

The missions, at the same time, can be of different types:
* Main Quest: these Quests are necessary to continue in history and are obligatory.
* Secondary Quest: They are optional Quest, they come out as you complete the main Quest, they are not necessary to continue with the story nor are they obligatory.
* Chained Quest: They are Quest linked to the Quests, that is, once you complete one, they will instantly give you the next one, you will not have to go look for it.
* Events Quest: These are Quest that are active for a limited time, they can be daily, weekly, monthly or specific events for a special occasion.

![Different Quests](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Quest_types.png)

# Code
First of all, we must first create the Quests.h module, the module contains the loading and saving of the quests as well as a class, with the quests that you are going to use. this module will be the parent of the other search modules, since the search modules will be derived from it.

```#C
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
```

Then we are going to create Quest_manager.h and Quest_manager.cpp, these modules will create the entities in the scene and organize them in the game. This module will have the functions to create or destroy the entities in the scenes.

In the first place, we are going to create the quests, in the CreateQuest function, it is important that in this function, we must call the quest Start, since this way the program enters this Quest.cpp function (first we need the quest modules created ).

The Quest_manager will contain the collisions and the mission states, since they will then be used in the Oncolision, which is used in these modules, and then they will be called in the Quest module.

```#C
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

```
![Code3](https://github.com/rayolop20/Quest_Manager/blob/main/Page_images/Code3.png)

* collisions: collisions are important for the missions, since they will be used as a sensor, and will be used for the player to interact with them.
The collisions are used in the oncolision of Quest_manager, where we will define how the missions will work, in my case I have made them activate with the bools and then the player does TP to indicate that the mission is complete


```#C
void QuestManager::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider_M1)
	{
		if (c1->type == Collider::Type::QUEST1 && c2->type == Collider::Type::PLAYER) {
			ques1 = true;
		}
		
	}
	if (c1 == collider_M1_2)
	{
		if (c1->type == Collider::Type::QUEST1_2 && c2->type == Collider::Type::PLAYER && ques1 == true) {
			ques1 = false;

			app->player->Z.position.x = 0;
			app->player->Z.position.y = 0;

		}
	}
}
```

In the mission module, we are going to initialize the collisions in the Start and then in the update we are going to define what the mission will do, if it ends here, if the player dies...

* Start

```#C
	app->questManager->collider_M1 = app->collisions->AddCollider({ 200, 200, 50, 50 }, Collider::Type::QUEST1, (Module*)app->questManager);
	app->questManager->collider_M1_2 = app->collisions->AddCollider({500, 500, 50, 50}, Collider::Type::QUEST1_2, (Module*)app->questManager);

```

* Update
```#C
	SDL_Rect Quest1 = { 200, 200, 50, 50 };
	app->render->DrawRectangle(Quest1, 0, 0, 255);

	if (app->questManager->ques1 == true)
	{
		SDL_Rect Quest1 = { 500, 500, 50, 50 };
		app->render->DrawRectangle(Quest1, 0, 0, 255);

	}

	app->questManager->collider_M1->SetPos(200, 200);
 ```

for finsh the only what we need to do is implement the quest on the scene

```#C
	//(.h)
	QuestType* quest1;
	//Start (.cpp) 
	Quest1* quest1 = (Quest1*)app->questManager->CreateQuest(QuestType::QUEST1, 0, { 0, 0 });

 ```
## TODOS

* DOWNLOAD HANDOUT HERE:
* https://drive.google.com/drive/folders/1J4AwV-EyjnmkMZGU4G89kenj37R7VUBI?usp=sharing

# Todo 1
* [Quest_Manager.cpp] Add the Quest on List
 
 -Call the constructor Called QuestType
 
 
 # Todo 2
* [Collisions.cpp, Collider.h ] Create The colliders
 
 -Create the colliders on struct
 
 -Make The matrix (use the player for reference)
 
 -Draw the colider
 
  # Todo 3
* [Quest_Manager.cpp, Quest_Manager.h ] Make the colision system
 
 -Player Hits with the colider, what wappend?
 
 -We need some elements
 
   # Todo 4 [Quest1.cpp]
 -add the coliders
 
   # Todo 5 [Quest1.cpp]
 -Make the Quest
 
  # Todo 6 [Scene.cpp]
 -Initialize the Quest
 
 -Put it on scene
