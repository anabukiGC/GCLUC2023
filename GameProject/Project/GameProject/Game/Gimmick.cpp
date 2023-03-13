#include "Gimmick.h"
#include "Field.h"
//#include"GameData.h"
//ObjectBase�g�p
Hari::Hari(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Hari", CImage);
	m_pos = pos;
	//���S�ʒu�ݒ�
	m_img.SetCenter(44 / 2, 74);
}

void Hari::Update(float deltatime) {
	static int move_speed = 9;
	m_pos.x -= move_speed;
}

//�e�͕`�悵�Ȃ�
void Hari::DrawShadow()
{
}

//ObjectBase�g�p
YIwa::YIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick, (int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//���S�ʒu�ݒ�
	m_img.SetCenter(224 / 2, 224);
	//���`�ݒ�(�����͗]����)
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 34, 0), CVector3D(224 / 2 - 32, -34, 224 / 2 - 70));

}
	
//Task�g�p	
void YIwa::Update(float deltatime) {
	static int move_speed = 10;
	if (m_pos.y < 0) {
		m_pos.y += move_speed;
		//m_pos.x += GameData::move_speed;
		m_pos.x += 6;
	}
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);

}

//�e�͕`�悵�Ȃ�
void YIwa::DrawShadow()
{
}

//ObjectBase�g�p
XIwa::XIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick ){
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//���S�ʒu�ݒ�
	m_img.SetCenter(224 / 2, 224);

}

//Task�g�p	
void XIwa::Update(float deltatime) {
	static int move_speed = 10;
	m_pos.x -= move_speed;
	
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);

}

//�e�͕`�悵�Ȃ�
void XIwa::DrawShadow() 
{
}
