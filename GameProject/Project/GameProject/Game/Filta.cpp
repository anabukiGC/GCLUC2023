#include"Filta.h"
#include"ObjectBase.h"
#include"GameData.h"

Filta::Filta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_filta = COPY_RESOURCE("filta", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Filta::Draw,
		(int)EDrawPrio::eFilta
	);
}

Filta::~Filta()
{
	if (m_drawTask)delete m_drawTask;
}

void Filta::Update(float deltatime)
{
	
}

void Filta::Draw()
{
	float a = 1.0 - pow( ObjectBase::m_scroll.x / 200000,4);
	m_filta.SetColor(1, 1, 1, a);
	m_filta.Draw();
}


Filta2::Filta2() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_filta2 = COPY_RESOURCE("filta2", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Filta2::Draw,
		(int)EDrawPrio::eFilta
	);
}

Filta2::~Filta2()
{
	if (m_drawTask)delete m_drawTask;
}

void Filta2::Update(float deltatime)
{
	
}

void Filta2::Draw()
{
	float a = pow(ObjectBase::m_scroll.x / 200000, 4);
	m_filta2.SetColor(1, 1, 1, a);
	m_filta2.Draw();
}

//ゲームクリアのフィルター
ClearFilta::ClearFilta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	SOUND("SE_Clear")->Play(false);
	m_clearfilta = COPY_RESOURCE("clearfilta", CImage);
	m_clearlogo = COPY_RESOURCE("clearlogo", CImage);
	m_end = COPY_RESOURCE("end", CImage);
	m_continue = COPY_RESOURCE("continue", CImage);
	s_score = COPY_RESOURCE("ao", CImage);
	m_drawTask = new DrawTask
	(this,
		(DrawFunc)&ClearFilta::Draw,
		(int)EDrawPrio::eFilta
	);
}

ClearFilta::~ClearFilta()
{
	if (m_drawTask)delete m_drawTask;
}

void ClearFilta::Update(float deltatime)
{
	if(GameData::Max < GameData::score)
	GameData::Max = GameData::score;
}

void ClearFilta::Draw()
{
	m_clearfilta.Draw();

	m_clearlogo.SetPos(250, 0);
	m_clearlogo.Draw();

	m_continue.SetPos(450, 700);
	m_continue.Draw();

	m_end.SetPos(650, 800);
	m_end.Draw();

	int score = GameData::score;
	for (int i = 6; i > 0; i--, score /= 10) {
		int s = score % 10;
		s_score.SetRect(16 * s, 0, 16 * s + 16, 32);
		s_score.SetSize(32 * 2, 64 * 2);
		s_score.SetPos(1000 + 32 * 2 * i, 750);
		s_score.Draw();
	}
}

//ゲームオーバのフィルター
OverFilta::OverFilta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	SOUND("SE_Gameover")->Play(false);
	m_overfilta = COPY_RESOURCE("overfilta", CImage);
	m_overlogo = COPY_RESOURCE("overlogo", CImage);
	m_end = COPY_RESOURCE("end", CImage);
	m_continue = COPY_RESOURCE("continue", CImage);
	s_score = COPY_RESOURCE("aka", CImage);
	m_drawTask = new DrawTask
	(this,
		(DrawFunc)&OverFilta::Draw,
		(int)EDrawPrio::eFilta
	);
}

OverFilta::~OverFilta()
{
	if (m_drawTask)delete m_drawTask;
}

void OverFilta::Update(float deltatime)
{
	if (GameData::Max < GameData::score)
	GameData::Max = GameData::score;
}

void OverFilta::Draw()
{
	m_overfilta.Draw();

	m_overlogo.SetPos(250, 0);
	m_overlogo.Draw();

	m_continue.SetPos(450, 700);
	m_continue.Draw();

	m_end.SetPos(650, 800);
	m_end.Draw();

	int score = GameData::score;
	for (int i = 6; i > 0; i--, score /= 10) {
		int s = score % 10;
		s_score.SetRect(16 * s, 0, 16 * s + 16, 32);
		s_score.SetSize(32 * 2, 64 * 2);
		s_score.SetPos(1000 + 32 * 2 * i, 750);
		s_score.Draw();
	}
}