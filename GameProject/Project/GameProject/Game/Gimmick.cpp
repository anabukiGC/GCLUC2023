#include "Gimmick.h"
#include "Field.h"
#include "../Game/ObjectBase.h"
//#include"GameData.h"
//ObjectBase使用
Hari::Hari(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Hari", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(44 / 2, 74);
	//箱形設定(増減は余白分)
	m_box = CAABB(CVector3D(-44 / 2, -77, 0), CVector3D(44 / 2, 77, 44 / 4));
}

void Hari::Update(float deltatime) {
	//static int move_speed = 6;
	//m_pos.x -= move_speed;
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}

//ObjectBase使用
YIwa::YIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick, (int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224);
	//箱形設定(増減は余白分)
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 34, 0), CVector3D(224 / 2 - 32, -34, 224 / 2 - 70));

}
	
//Task使用	
void YIwa::Update(float deltatime) {
	static int move_speed = 10;
	if (m_pos.y < 0) {
		m_pos.y += move_speed;
		//m_pos.x += GameData::move_speed;
		//m_pos.x += 6;
	}
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}

}

//影は描画しない
void YIwa::DrawShadow()
{
}

//ObjectBase使用
XIwa::XIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick ){
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224);
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 34, 0), CVector3D(224 / 2 - 32, 224 / 2 - 34, 224 / 4 - 70));

}

//Task使用	
void XIwa::Update(float deltatime) {
	static int move_speed = 10;
	m_pos.x -= move_speed;
	
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}
