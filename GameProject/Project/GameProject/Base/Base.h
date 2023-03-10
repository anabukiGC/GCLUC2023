#pragma once
#include<GLLibrary.h>
//重力加速度
#define GRAVITY (9.8f/20)
#define X_MIN (-640)
#define X_MAX (900/2)
#define Z_MIN (0)
#define Z_MAX (400)
enum { 
	eType_Field,
	eType_Gimmick,
    eType_Player,
    eType_UI,
	eType_Scene,
	
};

class Base {
public:
	//オブジェクトの種類
	int m_type;
	//座標データ
	CVector3D m_pos; 
	CVector3D m_pos_old;
	//半径
	float m_rad;
	//移動ベクトル
	CVector3D m_vec;
	//スクロール値
	static CVector2D m_scroll;
	//削除フラグ
	bool m_kill;
	//オブジェクトのリスト
	static std::list<Base*>m_list;
	//短形
	//CRect m_rect;
	//箱形
	CAABB m_box;

public:
	//typeオブジェクトの種類
	Base(int type); //コンストラクタ
	virtual~Base(); //デストラクタ
	virtual void Update(); //更新処理
	virtual void Draw(); //描画処理
	virtual void Collision(Base* b);
	//削除フラグON
	void SetKill() { m_kill = true; }
	//短形同士の判定
	static bool CollisionAABB(Base* b1, Base* b2);
	//短形の表示
	void DrawRect();

	static CVector2D GetScreenPos(const CVector3D& pos);
	//全てのオブジェクトの更新
	static void UpdateAll();
	//全てのオブジェクトの描画
	static void DrawAll();
	//全てのオブジェクトの当たり判定検証
	   static void CollisionAll();
	   //削除チェック
	   static void CheckKillAll();
	//オブジェクトの追加
 static void Add(Base* b);
 //全オブジェクトの削除
 static void KillAll();
 //円同士の衝突
 static bool CollisionCircle(Base* b1, Base* b2);
 Base* Base::FindObject(int type);
};