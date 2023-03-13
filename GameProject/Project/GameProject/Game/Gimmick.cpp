#include "Gimmick.h"
#include "Field.h"
//#include"GameData.h"
//ObjectBase使用
Hari::Hari(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Hari", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(44 / 2, 74);
}

void Hari::Update(float deltatime) {
	static int move_speed = 9;
	m_pos.x -= move_speed;
}

//影は描画しない
void Hari::DrawShadow()
{
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
		m_pos.x += 6;
	}
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);

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

}

//Task使用	
void XIwa::Update(float deltatime) {
	static int move_speed = 10;
	m_pos.x -= move_speed;
	
	//ObjectBase::Update(deltatime);
	ObjectBase::Update(deltatime);

}

//影は描画しない
void XIwa::DrawShadow() 
{
}
