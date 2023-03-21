#include"Game.h"
#include"Player.h"
#include"Field.h"
#include"Gimmick.h"
#include"GimmickManager.h"
#include"UI/UI.h"
#include"Filta.h"
#include"GameData.h"
#include"../TaskSystem/TaskManager.h"
#include"../Title/Title.h"

Game::Game() :Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
	SOUND("BGM_Game")->Volume(0.3);
	SOUND("BGM_Game")->Play(true);
	new Player(CVector3D(200, 0, 0), false);
	new Field();
	new GimmickManager();
	new UI();
	new Filta();
	new Filta2();
}

Game::~Game()
{
	if (m_drawTask)delete m_drawTask;
}

void Game::Update(float deltatime)
{
	/*if (PUSH(CInput::eButton2))
	{
		TaskManager::Instance()->AllRemoveTask();
		new Title();
	}*/

	
	//ゲームオーバでタイトル
	if (PUSH(CInput::eButton2) && GameData::life <= 0)
	{
		TaskManager::Instance()->AllRemoveTask();
		new Title();
	}
	//ゲームクリアでタイトル
	if (PUSH(CInput::eButton2) && GameData::Clear) {
		TaskManager::Instance()->AllRemoveTask();
		new Title();
	}
	//問題点
	/*if (PUSH(CInput::eButton1) && GameData::life <= 0)
	{
		TaskManager::Instance()->AllRemoveTask();
		GameData::life = 3;
		ObjectBase::m_scroll.x = 0;
		new Game();
	}*/
}