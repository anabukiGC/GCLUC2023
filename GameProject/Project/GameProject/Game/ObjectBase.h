#pragma once
#include"../TaskSystem/Task.h"
#include"../TaskSystem/DrawTask.h"
#include <GLLibrary.h>


class ObjectManager;

class ObjectBase :public Task
{
	friend ObjectManager;

private:
	ObjectBase* m_prev;
	ObjectBase* m_next;
	CImage* m_shadowImage;

	DrawTask* m_drawTask;
	DrawTask* m_shadowDrawTask;

protected:
	CImage* m_image;
	CVector2D m_imgePos;

	CVector3D m_pos;

public:
	//コンストラクタ
	ObjectBase(int prio);
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
	// 影を描画
	void DrawShadow();
};