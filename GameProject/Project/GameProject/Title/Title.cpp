#include "Title.h"
#include"Game/Game.h"
#include"../Game/ObjectBase.h"

Title::Title():Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
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
	if (m_drawTask)delete m_drawTask;
}

void Title::Update(float deltatime)
{
	ObjectBase::m_scroll.x += 1;
	if (PUSH(CInput::eButton1)) {
		new Game();
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
