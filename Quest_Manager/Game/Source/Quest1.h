#ifndef __QUEST1_H__
#define __QUEST1_H__

#include "Quests.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;
struct Collider;


class Quest1 : public Quest
{
public:
	// Constructor
	Quest1();

	// Destructor
	~Quest1();


	bool Awake(pugi::xml_node&);
	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start();

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	bool Update(float dt);

	// Called at the end of the application loop
	// Performs the render call of the player sprite

	Collider* collider = nullptr;
public:

};

#endif // __QUEST1_H__
