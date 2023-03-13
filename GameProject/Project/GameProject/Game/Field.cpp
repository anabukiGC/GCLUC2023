#include "Field.h"
//m_scroll�g�p�̂��߃C���N���[�h
#include"ObjectBase.h"
//Task�p�ɕύX
Field::Field():Task((int)ETaskPrio::eField,(int)ETaskTag::eField)
{
	//m_sky = COPY_RESOURCE("Sky", CImage);
	m_town = COPY_RESOURCE("Town", CImage);
	m_foreground = COPY_RESOURCE("ForeGround", CImage);
	m_ground_y = 540;
	//�`��̓o�^
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Field::Draw,
		(int)EDrawPrio::eField
	);

}
//�j�����ɕ`�惊�X�g�����菜��
Field::~Field()
{
	if (m_drawTask) delete m_drawTask;

}
//�I�[�o�[���C�h
void Field::Update(float deltatime)
{
}
void Field::Draw()
{
	float sc;
	//m_sky.Draw();
	//�X�N���[���l�����̂܂܎g�p
	sc = ObjectBase::m_scroll.x;
	m_town.SetRect(sc, 0, sc + 1980, 1200);
	m_town.Draw();

	m_foreground.SetRect(sc, 0, sc + 1980, 1200);
	m_foreground.Draw();
}