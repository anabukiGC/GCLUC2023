#include"Game.h"
#include"Player.h"
#include"Field.h"
#include"Gimmick.h"
#include"GimmickManager.h"
#include"UI/UI.h"
#include"Filta.h"
#include"../TaskSystem/TaskManager.h"
#include"../Title/Title.h"

Game::Game() :Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
	new Player(CVector3D(200, 0, 0), false);
	new Field();
	new GimmickManager();
	new UI();
	new Filta();
	//new Filta2();
	//new Hari(CVector3D(400, 0, 0));
	//new XIwa(CVector3D(600, 0, 0));
	//new YIwa(CVector3D(800, -1000, 0));
}

Game::~Game()
{
	if (m_drawTask)delete m_drawTask;
}

void Game::Update(float deltatime)
{
	if (PUSH(CInput::eButton2))
	{		
		TaskManager::Instance()->AllRemoveTask();
		new Title();
	}
}