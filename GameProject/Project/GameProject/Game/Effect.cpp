#include "Effect.h"

Effect::Effect(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eEffect, (int)ETaskTag::eEffect)
{
	m_img = COPY_RESOURCE("Sna", CImage);
	m_pos = pos;
	m_img.SetCenter(124, 64);
	m_alppha = 1.0;

}

void Effect::Update(float deltatime)
{
	int x = 5 + rand() % 20;
	int y = 10 + rand() % 10;
	m_pos.x -= x;
	m_pos.y -= y;
	m_alppha -= 0.09;
	if (m_alppha < 0) {
		Delete();
	}
	m_img.SetColor(1, 1, 1, m_alppha);
}

void Effect::DrawShadow()
{

}
