#include "Title.h"
#include"Game/Game.h"

Title::Title():Task((int)ETaskPrio::eScene,(int)ETaskTag::eScene)
{
	m_title = COPY_RESOURCE("title", CImage);
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
	if (PUSH(CInput::eButton1)) {
		new Game();
		Delete();
	}
}

void Title::Draw()
{
	m_title.Draw();
}
