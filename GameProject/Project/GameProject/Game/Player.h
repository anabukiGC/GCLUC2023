#pragma once
#include "ObjectBase.h"
//ObjectBaseを継承
class Player : public ObjectBase {
private:
	//状態
	enum {
		eState_Run,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Fall,
		eState_Clear,
	};
	//状態変数
	int m_state;
	//反転フラグ
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
    //ダメージ番号
	int m_damage_no;
	//ヒットポイント
	int m_hp;
	//無敵時間
	int invincibility;

	//各状態での挙動
	void StateRun();
	void StateDamage();
	void StateDown();
	void StateFall();
	void StateClear();

public:
	Player(const CVector3D& p, bool flip);
	~Player();
	//Task仕様
	void Update(float deltatime);
	//ObjectBase仕様
	void Collision(ObjectBase* b);
	//XIwaの影を描画しないためオーバーライド
	void DrawShadow2();
};