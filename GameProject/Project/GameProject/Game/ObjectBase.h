#pragma once
#include"../TaskSystem/Task.h"
#include"../TaskSystem/DrawTask.h"
//重力加速度
#define GRAVITY (9.8f/20)
#define X_MIN (-640)
#define X_MAX (900/2)
#define Z_MIN (0)
#define Z_MAX (400)
class ObjectManager;

class ObjectBase :public Task
{
	friend ObjectManager;

private:
	ObjectBase* m_prev;
	ObjectBase* m_next;
	//COPY_RESOUCEを使用するので実体で
	CImage m_shadowImage;

	DrawTask* m_drawTask;
	DrawTask* m_shadowDrawTask;

protected:
	//COPY_RESOUCEを使用するので実体で
	CImage m_img;
	CVector2D m_imgePos;

	CVector3D m_pos;
	//Baseクラスから移植
	CVector3D m_vec;
	bool m_flip;

	//箱型
	CAABB m_box;
public:
	//スクロール値
	static CVector2D m_scroll;
	//コンストラクタ
	ObjectBase(int prio,int tag);
	//デストラクタ
	virtual ~ObjectBase();

	//キャラクターの位置を取得
	const CVector3D& GetPos() const;
	//キャラクターの描画優先度を変更
	void SetDrawPriority(int prio);

	//更新
	virtual void Update(float deltaTime);
	//描画
	virtual void Draw();
	//衝突検証
	virtual void Collision(ObjectBase* b){}
	// 影を描画
	virtual void DrawShadow();

	void DrawRect();
	//矩形同士の判定
	static bool CollisionAABB(ObjectBase* b1, ObjectBase* b2);
	static CVector2D GetScreenPos(const CVector3D& pos);

};