#include "Gimmick.h"
#include "Field.h"
//#include"GameData.h"

Hari::Hari(const CVector3D& pos) :Base(eType_Gimmick) {
	m_img = COPY_RESOURCE("Hari", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(44 / 2, 74);
}

void Hari::Draw() {
	/*
	for (int i = 0; i < 6; i++) {
		m_img.SetPos(45*i*-1+300, 50*i+750);
		m_img.Draw();
	}
	*/
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

YIwa::YIwa(const CVector3D& pos) :Base(eType_Gimmick) {
	m_img = COPY_RESOURCE("Iwa", CImage);

	m_img2 = COPY_RESOURCE("Statekage", CImage);

	m_img3 = COPY_RESOURCE("Endkage", CImage);

	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224);
	m_img2.SetCenter(224 / 2, 224);
	m_img3.SetCenter(224 / 2, 224);
	//箱形設定(増減は余白分)
	m_box = CAABB(CVector3D(-224 / 2 + 37, -224 + 34, 0), CVector3D(224 / 2 - 32, -34, 224 / 2 - 70));

}

void YIwa::Update() {
	static int move_speed = 10;
	if (m_pos.y < 0) {
		m_pos.y += move_speed;
		//m_pos.x += GameData::move_speed;
		m_pos.x += 6;
	}

}

void YIwa::Draw() {
	if (m_pos.y >= -400) {
		m_img3.SetPos(GetScreenPos(m_pos).x, 900);
		m_img3.Draw();
	}
	else {
		m_img2.SetPos(GetScreenPos(m_pos).x, 900);
		m_img2.Draw();
	}
	//m_img.SetPos(1000,900);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	//矩形の表示
	DrawRect();
}

XIwa::XIwa(const CVector3D& pos) :Base(eType_Gimmick) {
	m_img = COPY_RESOURCE("Iwa", CImage);
	m_pos = pos;
	//中心位置設定
	m_img.SetCenter(224 / 2, 224);

}

void XIwa::Draw() {
	//m_img.SetPos(1000,900);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}