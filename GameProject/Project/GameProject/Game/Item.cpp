#include "Item.h"
#include"GameData.h"

Item::Item(const CVector3D& pos, int juel_type) :ObjectBase((int)ETaskPrio::eItem, (int)ETaskTag::eItem) {
	m_img = COPY_RESOURCE("Juel", CImage);
	m_pos = pos;
	m_juel_type = juel_type;//��΂̎��(�X�R�A���ʗp)
	//�摜�؂���
	m_img.SetRect(m_juel_type * 174, 0, (m_juel_type + 1) * 174, 174);
	//�T�C�Y����
	m_img.SetSize(174, 174);
	//���S�ʒu�ݒ�
	m_img.SetCenter(174 / 2, 174);
	//���`�ݒ�
	m_box = CAABB(CVector3D(-175 / 2 + 30, -175 + 66, 0), CVector3D(175 / 2 - 27, 0 - 16, 175 / 4));
}

void Item::Update(float deltatime) {
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}

void Item::Collision(ObjectBase* b)
{
	switch (b->GetTag())
	{
	case (int)ETaskTag::ePlayer:
		if (CollisionAABB(this, b))
		{
			SOUND("SE_Getjuel")->Play(false);
			GameData::score += GameData::juel_score[m_juel_type];
			Delete();
		}
		break;
	}
}