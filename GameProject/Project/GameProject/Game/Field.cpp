#include "Field.h"
//m_scroll使用のためインクルード
#include"ObjectBase.h"
//Task用に変更
Field::Field():Task((int)ETaskPrio::eField,(int)ETaskTag::eField)
{
	//m_sky = COPY_RESOURCE("Sky", CImage);
	m_town = COPY_RESOURCE("Town", CImage);
	m_foreground = COPY_RESOURCE("ForeGround", CImage);
	m_ground_y = 540;
	//描画の登録
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Field::Draw,
		(int)EDrawPrio::eField
	);

}
//破棄時に描画リストから取り除く
Field::~Field()
{
	if (m_drawTask) delete m_drawTask;

}
//オーバーライド
void Field::Update(float deltatime)
{
}
void Field::Draw()
{
	float sc;
	//m_sky.Draw();
	//スクロール値をそのまま使用
	sc = ObjectBase::m_scroll.x;
	m_town.SetRect(sc, 0, sc + 1980, 1200);
	m_town.Draw();

	m_foreground.SetRect(sc, 0, sc + 1980, 1200);
	m_foreground.Draw();
}