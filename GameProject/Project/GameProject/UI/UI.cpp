#include"UI.h"
#include"../Game/GameData.h"
#include "../Game/ObjectBase.h"

UI::UI()
	:Task((int)ETaskPrio::eUI, (int)ETaskTag::eUI)
	, m_m(0)
	, m_km(0)
	, m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//ÉLÉÉÉâÉNÉ^Å[ï`âÊÇìoò^
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&UI::Draw,
		(int)EDrawPrio::eUI
	);
}

void UI::Update(float Deletetime)
{
	m_m = GameData::PXtoM(ObjectBase::m_scroll.x);
}

void UI::Draw()
{
	m_title_text.Draw(100, 100, 255, 255, 255, "%d", m_m);
}