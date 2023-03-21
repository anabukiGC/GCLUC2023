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
	if (m_next == 0) {
		new Game();
		GameData::life = 3;
		ObjectBase::m_scroll.x = 0;
		GameData::score = 0;
		GameData::Clear = false;
	}
	else {
		new Title();
	}
}

void Game::Update(float deltatime)
{
	//クリアリトライ
	if (PUSH(CInput::eButton1) && GameData::Clear)
	{
		m_next = 0;
		TaskManager::Instance()->AllRemoveTask();
	}
	//クリアタイトル
	if (PUSH(CInput::eButton2) && GameData::Clear)
	{
		m_next = 2;
		TaskManager::Instance()->AllRemoveTask();
	}
	//ゲームオーバリトライ
	if (PUSH(CInput::eButton1) && GameData::life <= 0)
	{
		m_next = 0;
		TaskManager::Instance()->AllRemoveTask();
	}
	//ゲームオーバタイトル
	if (PUSH(CInput::eButton2) && GameData::life <= 0)
	{
		m_next = 2;
		TaskManager::Instance()->AllRemoveTask();
	}
}