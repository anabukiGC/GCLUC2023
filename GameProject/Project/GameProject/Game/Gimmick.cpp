#include "Gimmick.h"
#include "Field.h"
#include "../Game/ObjectBase.h"
#include"GameData.h"
//ObjectBase使用
UIwa::UIwa(const CVector3D& pos)
	:ObjectBase((int)ETaskPrio::eUI, (int)ETaskTag::eUI)
{
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	m_img.SetCenter(224 / 2, 224 / 2);
}

void UIwa::Update(float deltatime)
{
	static int move_speed = 20;
	m_pos.y += move_speed;
	if (GameData::UIwa == 0) {
		if (!GameData::Clear) {
			int x = 1 + rand() % 15;
			m_pos.x += x;
		}
		else {
			m_pos.x -= 25;
		}
	}
	ObjectBase::Update(deltatime);
	if (0 <= m_pos.y && m_pos.z == 800) {
		//m_pos.y -= move_speed;
	}
	else if (100 <= m_pos.y && m_pos.z == 0 || ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}

//影は描画しない
void UIwa::DrawShadow()
{

}

//XIwaの影は描画しない
void UIwa::DrawShadow2()
{

}

Hari::Hari(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Hari", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(44 / 2, 74);
	//箱形設定(増減は余白分)
	m_box = CAABB(CVector3D(-44 / 2, -77+10, 0), CVector3D(44 / 2, 0, 44 / 4));
}

void Hari::Update(float deltatime) {
	//static int move_speed = 6;
	//m_pos.x -= move_speed;
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}

//XIwaの影は描画しない
void Hari::DrawShadow2()
{

}

//ObjectBase使用
YIwa::YIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick, (int)ETaskTag::eGimick) {
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224 - 30);
	//箱形設定(増減は余白分)
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 64, 0), CVector3D(224 / 2 - 32, -4, 224 / 2 - 70));

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

//XIwaの影は描画しない
void YIwa::DrawShadow2()
{

}

//ObjectBase使用
XIwa::XIwa(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eGimmick,(int)ETaskTag::eGimick ){
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224 / 2);
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 64 + 82, -112), CVector3D(224 / 2 - 32, -4 + 82, 224 / 2 - 112));
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

//影は描画しない
void XIwa::DrawShadow()
{

}

//ObjectBase使用
Ana::Ana(const CVector3D& pos) :ObjectBase((int)ETaskPrio::eFall, (int)ETaskTag::eFall) {
	SOUND("SE_Hole")->Play(false);
	//m_img = COPY_RESOURCE("Ana", CImage);
	m_img = COPY_RESOURCE("Ana2", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(415 / 2, 0);
	//m_box = CAABB(CVector3D(340, -30, -600), CVector3D(400, 10, -400));
	m_box = CAABB(CVector3D(340, -30, -600), CVector3D(341, 10, -410));
}

//Task使用	
void Ana::Update(float deltatime) {
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}

//影は描画しない
void Ana::DrawShadow()
{

}

//XIwaの影は描画しない
void Ana::DrawShadow2()
{

}