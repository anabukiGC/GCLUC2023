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
	m_score = GameData::score;
}

void UI::Draw()
{
	m_title_text.Draw(1500, 100, 255, 255, 255, "%d m", m_m);
	m_title_text.Draw(1500, 200, 255, 255, 255, "sc.%d", m_score);
	//ハート(hp)
	int life = GameData::life;
	for (int i = 0; i < life; i++) {
		m_life.SetSize(32 * 2, 32 * 2);
		m_life.SetPos(100+(32 * i)*2, 50);
		m_life.Draw();
	}
}