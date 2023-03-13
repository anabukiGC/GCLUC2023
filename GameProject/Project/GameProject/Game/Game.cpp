#include"Game.h"
#include"Player.h"
#include"Field.h"
#include"Gimmick.h"
#include"../Title/Title.h"

Game::Game() :Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
	new Player(CVector3D(200, 0, 0), false);
	new Field();
	new Hari(CVector3D(400, 0, 0));
	new XIwa(CVector3D(600, 0, 0));
	new YIwa(CVector3D(800, -1000, 0));
}

void Game::Update(float deltatime)
{
	if (PUSH(CInput::eButton2))
	{
	}
}