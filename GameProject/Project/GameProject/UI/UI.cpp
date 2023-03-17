#include"UI.h"
#include"../Game/GameData.h"
#include "../Game/ObjectBase.h"

UI::UI()
	:Task((int)ETaskPrio::eUI, (int)ETaskTag::eUI)
	, m_m(0)
	, m_km(0)
	, m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_life = COPY_RESOURCE("life", CImage);
	//キャラクター描画を登録
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&UI::Draw,
		(int)EDrawPrio::eUI
	);
}

UI::~UI()
{
	if (m_drawTask)delete m_drawTask;
}

void UI::Update(float Deletetime)
{
	m_m = GameData::PXtoM(ObjectBase::m_scroll.x);
}

void UI::Draw()
{
	m_title_text.Draw(1500, 100, 255, 255, 255, "%d m", m_m);
	//ハート(hp)
	int life = GameData::life;
	for (int i = 0; i < life; i++) {
		m_life.SetSize(32 * 2, 32 * 2);
		m_life.SetPos(100+(32 * i)*2, 50);
		m_life.Draw();
	}
}

UI2::UI2(int ui_type):Task((int)ETaskPrio::eUI, (int)ETaskTag::eUI)
{
	UI_Type = ui_type;
	if (UI_Type == 0) {
	m_over = COPY_RESOURCE("GameOver", CImage);
	}
	else {
		m_clear = COPY_RESOURCE("GameClear", CImage);
	}
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&UI::Draw,
		(int)EDrawPrio::eUI
	);
}

UI2::~UI2()
{
	if (m_drawTask)delete m_drawTask;
}

void UI2::Update(float Deletetime)
{

}

void UI2::Draw()
{
	m_over.Draw();
	m_over.SetPos(300, 600);
}
