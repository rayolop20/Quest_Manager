#include "Player.h"

#include "App.h"
#include "Animation.h"
#include "Input.h"
#include "Render.h"
#include "Window.h"
#include "Collisions.h"
#include "Scene.h"

#include "Map.h"
#include "Defs.h"
#include "Log.h"

Player::Player() : Module()
{
	name.Create("player");

}

Player::~Player()
{

}

bool Player::Awake(pugi::xml_node& config) {

	LOG("Loading Player");
	bool ret = true;

	return ret;
}

bool Player::Start()
{
	bool ret = true;
	Z.Pcol = app->collisions->AddCollider({ Z.position.x,Z.position.y, 100, 100 }, Collider::Type::PLAYER, this);

	return ret;
}

bool Player::Update(float dt)
{
	player = { Z.position.x,Z.position.y, 100, 100 };
	app->render->DrawRectangle(player, 200, 200, 200);

	//movement
	{
		//left
		{
			if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT && Z.MoveXD == false)
			{
				Z.position.x+=3;
				Z.MoveXA = true;
			}

			if (app->input->GetKey(SDL_SCANCODE_D) == KEY_UP)
			{
				Z.MoveXA = false;
			}
		}
		//right
		{
			if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT && Z.MoveXA == false)
			{
				Z.position.x-=3;
				Z.MoveXD = true;
			}

			if (app->input->GetKey(SDL_SCANCODE_A) == KEY_UP)
			{
				Z.MoveXD = false;
			}
		}
		//up
		{
			if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT && Z.MoveYW == false)
			{
				Z.position.y-=3;
				Z.MoveYS = true;
			}

			if (app->input->GetKey(SDL_SCANCODE_W) == KEY_UP)
			{
				Z.MoveYS = false;
			}
		}
		//down
		{
			if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT && Z.MoveYS == false)
			{
				Z.position.y+=3;
				Z.MoveYW = true;
			}

			if (app->input->GetKey(SDL_SCANCODE_S) == KEY_UP)
			{
				Z.MoveYW = false;
			}
		}
	}

	//debug
	if (app->input->GetKey(SDL_SCANCODE_F1) == KEY_IDLE)
	{
		app->collisions->DebugDraw();
	}

	Z.Pcol->SetPos(Z.position.x, Z.position.y);

	return true;
}

bool Player::PostUpdate()
{
	//draw player

	return true;
}

