#include"ObjectBase.h"
#include"ObjectManager.h"
#define Z_CENTER 432
//スクロール値はここへ移植
CVector2D ObjectBase::m_scroll(0, 0);

//tagがオブジェクトの種類
//コンストラクタ
ObjectBase::ObjectBase(int prio,int tag)
	:Task(prio, tag)
	, m_prev(nullptr)
	, m_next(nullptr)
	, m_imgePos(0.0f, 0.0f)
	,m_pos(0.0f,0.0f,0.0f)
{
	//オブジェクトのリストへ追加
	ObjectManager::Instance()->AddObject(this);
	//キャラクター描画を登録
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&ObjectBase::Draw,
		(int)EDrawPrio::eChara
	);
	//影描画を登録
	m_shadowDrawTask = new DrawTask
	(
		this,
		(DrawFunc)&ObjectBase::DrawShadow,
		(int)EDrawPrio::eShadow
	);
	//影の設定(影の画像も変更あり)
	CVector2D shadowSize = CVector2D(192, 48);
	m_shadowImage = COPY_RESOURCE("Statekage", CImage);
	m_shadowImage.SetSize(shadowSize);
	m_shadowImage.SetCenter(CVector2D(shadowSize.x * 0.5f, shadowSize.y * 0.5f));
}

ObjectBase::~ObjectBase()
{
	//オブジェクトリストから取り除く
	ObjectManager::Instance()->RemoveObject(this);
	//描画タスク破壊
	if (m_shadowDrawTask) delete m_shadowDrawTask;
	if (m_drawTask) delete m_drawTask;

}

const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

void ObjectBase::SetDrawPriority(int prio)
{
	m_drawTask->SetPriority(prio);
}

void ObjectBase::Update(float deltaTime)
{
	//影の位置(高さは0で計算)
	CVector3D shadowPos(m_pos.x, 0, m_pos.z);
	//キャラクターと同じ計算
	m_shadowImage.SetPos(GetScreenPos(shadowPos));
}

void ObjectBase::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
#ifdef _DEBUG
	//当たり判定矩形の表示
	//DrawRect()
#endif
}

void ObjectBase::DrawShadow()
{
	//影の描画
	m_shadowImage.Draw();
}
//小山さんのデバッグ矩形描画を移植
void ObjectBase::DrawRect()
{
	//座標+Boxの幅、高さ、奥行
	CAABB box = CAABB(m_pos + m_box.min, m_pos + m_box.max);
	//手前の矩形
	Utility::DrawQuad(
		GetScreenPos(box.min),
		CVector2D(box.max.x - box.min.x, box.max.y - box.min.y),
		CVector4D(1, 0, 0, 0.5f)
	);
	//奥の矩形
	Utility::DrawQuad(
		GetScreenPos(CVector3D(box.min.x, box.min.y, box.max.z)),
		CVector2D(box.max.x - box.min.x, box.max.y - box.min.y),
		CVector4D(1, 0, 0, 0.5f)
	);
}

//小山さんのAABB衝突判定を移植
bool ObjectBase::CollisionAABB(ObjectBase* b1, ObjectBase* b2)
{
	//b1の箱形
	CAABB box1 = CAABB(
		CVector3D(b1->m_pos.x + b1->m_box.min.x, b1->m_pos.y + b1->m_box.min.y, b1->m_pos.z + b1->m_box.min.z),
		CVector3D(b1->m_pos.x + b1->m_box.max.x, b1->m_pos.y + b1->m_box.max.y, b1->m_pos.z + b1->m_box.max.z)
	);
	//b2の箱形
	CAABB box2 = CAABB(
		CVector3D(b2->m_pos.x + b2->m_box.min.x, b2->m_pos.y + b2->m_box.min.y, b2->m_pos.z + b2->m_box.min.z),
		CVector3D(b2->m_pos.x + b2->m_box.max.x, b2->m_pos.y + b2->m_box.max.y, b2->m_pos.z + b2->m_box.max.z)
	);

	//箱形同士の判定
	if ((box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
		(box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
		(box1.min.z <= box2.max.z && box1.max.z >= box2.min.z))
		return true;

	return false;
}
//キャラクター座標→画面上での座標を変換
CVector2D ObjectBase::GetScreenPos(const CVector3D& pos)
{
	//座標ースクロール値＝画面上での位置
	return CVector2D(pos.x + pos.z / 2 + 720, pos.y - pos.z / 2 + 1040) - m_scroll;
}