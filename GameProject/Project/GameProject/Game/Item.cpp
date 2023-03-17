#include "Item.h"

Item::Item(const CVector3D& pos, int juel_type) :ObjectBase((int)ETaskPrio::eItem, (int)ETaskTag::eItem) {
	m_img = COPY_RESOURCE("Juel", CImage);
	m_pos = pos;
	m_juel_type = juel_type;//宝石の種類(スコア判別用)
	//中心位置設定
	m_img.SetCenter(174 / 2, 174);
	//箱形設定
	m_box = CAABB(CVector3D(-174 / 2 + 30, -174 + 15, 0), CVector3D(174 / 2 - 27, 0 - 64, 174 / 4));
}

void Item::Update(float deltatime) {
	if (ObjectBase::m_scroll.x + X_MIN + -500 > m_pos.x) {
		Delete();
	}
}