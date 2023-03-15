#include"UI.h"
#include"../Game/GameData.h"
#include "../Game/ObjectBase.h"

UI::UI(const CVector2D& pos)
	:Task((int)ETaskPrio::eUI, (int)ETaskTag::eUI)
	, m_km(0)
{
	
}

void UI::Update(float Deletetime)
{
	printf("%04f\n", ObjectBase::m_scroll.x);
}