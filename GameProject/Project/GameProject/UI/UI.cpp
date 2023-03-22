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
	s_score = COPY_RESOURCE("kin", CImage);	//ゲーム中
	
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
	if (m_m >= GameData::Goal) {
		GameData::Clear = true;
	}
}

void UI::Draw()
{
	if (GameData::Clear == false) {
		m_title_text.Draw(1500, 100, 255, 255, 255, "残り.%d m", GameData::Goal - m_m);
	}
	
	if (GameData::life > 0 && GameData::Clear == false) {
		m_title_text.Draw(1500, 200, 255, 255, 255, "sc.");
		m_title_text.Draw(1245, 300, 255, 255, 255, "ハイスコア.");
		//ハート(hp)
		int life = GameData::life;
		for (int i = 0; i < life; i++) {
			m_life.SetSize(32 * 2, 32 * 2);
			m_life.SetPos(100 + (32 * i) * 2, 50);
			m_life.Draw();
		}

		int score = GameData::score;
		for (int i = 6; i > 0; i--, score /= 10) {
			int s = score % 10;
			s_score.SetRect(16 * s, 0, 16 * s + 16, 32);
			s_score.SetSize(16 * 2, 32 * 2);
			s_score.SetPos(1600 + 16 * 2 * i, 150);
			s_score.Draw();
		}

		int mscore = GameData::Max;
		for (int i = 6; i > 0; i--, mscore /= 10) {
			int ms = mscore % 10;
			s_score.SetRect(16 * ms, 0, 16 * ms + 16, 32);
			s_score.SetSize(16 * 2, 32 * 2);
			s_score.SetPos(1600 + 16 * 2 * i, 250);
			s_score.Draw();
		}
	}
	

}