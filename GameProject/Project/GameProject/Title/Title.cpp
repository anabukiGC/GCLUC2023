#include "Title.h"
#include"Game/Game.h"
#include"../Game/GameData.h"
#include"../Game/ObjectBase.h"

Title::Title():Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
	SOUND("BGM_Title")->Volume(0.3);
	SOUND("BGM_Title")->Play(true);
	m_title = COPY_RESOURCE("title", CImage);
	m_titlelogo = COPY_RESOURCE("titlelogo", CImage);
	m_titlebotan = COPY_RESOURCE("titlebotan", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Title::Draw,
		(int)EDrawPrio::eScene
	);
}

Title::~Title()
{
	SOUND("BGM_Title")->Pause();
	if (m_drawTask)delete m_drawTask;
}

void Title::Update(float deltatime)
{
	ObjectBase::m_scroll.x += 1;
	if (PUSH(CInput::eButton1)) {
		SOUND("SE_Start")->Play(false);
		new Game();
		GameData::life = 3;
		ObjectBase::m_scroll.x = 0;
		Delete();
	}
}

void Title::Draw()
{
	float sc;
	sc = ObjectBase::m_scroll.x;
	m_title.SetRect(sc, 0, sc + 2200, 1200);
	m_title.Draw();
	m_titlelogo.SetPos(-100, -100);
	m_titlelogo.Draw();
	m_titlebotan.SetPos(-100, -100);
	m_titlebotan.Draw();
}
