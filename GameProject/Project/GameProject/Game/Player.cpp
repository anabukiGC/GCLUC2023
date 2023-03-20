#include "Player.h"
#include "AnimData.h"
#include "Field.h"
#include "GameData.h"
#include"Filta.h"
#include"../UI/UI.h"
#include"../TaskSystem/TaskManager.h"
#include"../Title/Title.h"
#include "Effect.h"

Player::Player(const CVector3D& p, bool flip)
	:ObjectBase((int)ETaskPrio::ePlayer, (int)ETaskTag::ePlayer)
{
		//画像複製
		m_img = COPY_RESOURCE("Player", CImage);
		//再生アニメーション設定
		m_img.ChangeAnimation(0);
		//座標設定
		//m_pos_old = m_pos = p ;
		m_pos = p ;
		//中心位置設定
		//元m_img.SetCenter(267/2, 450);
		m_img.SetCenter(267/2, 430);
		//反転フラグ
		m_flip = flip;
		//箱形判定の設定(増減は余白分)
		//元m_box = CAABB(CVector3D(-267 / 2 + 21, -450, 0), CVector3D(267 / 2 - 36, -19, 267 / 8));
		m_box = CAABB(CVector3D(-267 / 2 + 21, -410, 0), CVector3D(267 / 2 - 36, -19, 267 / 8));
		//矩形判定の設定
		//m_rect = CRect(-32, -128, 32, 0);
		//通常状態へ
		m_state = eState_Run;
		//着地フラグ
		m_is_ground = true;
		//攻撃番号
		m_attack_no = rand();
		//ダメージ番号
		m_damage_no = -1;
		//ヒットポイント
		m_hp = 2;
		//無敵時間
		invincibility = 0;
}

Player::~Player()
{
	SOUND("BGM_Game")->Pause();
}

//Task使用
void Player::Update(float deltatime)
{
	invincibility--;
	switch (m_state)
	{
	case eState_Run://走行状態
		StateRun();
		break;
	case eState_Damage://ダメージ状態
		StateDamage();
		break;
	case eState_Down://ダウン状態
		StateDown();
		break;
	case eState_Fall://落下状態
		StateFall();
		break;
	}
	
	//アニメーション更新
	m_img.UpdateAnimation();

	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//移動制限
	if (m_pos.y > 0)
	{
		//着地
		m_pos.y = 0;
		m_vec.y = 0;
		m_is_ground = true;
	}
	if (m_scroll.x + X_MIN > m_pos.x)
		m_pos.x = m_scroll.x + X_MIN;
	if (m_scroll.x + X_MAX < m_pos.x)
		m_pos.x = m_scroll.x + X_MAX;
	if (m_pos.z > Z_MAX)
		m_pos.z = Z_MAX;
	if (m_pos.z < Z_MIN)
		m_pos.z = Z_MIN;
	ObjectBase::Update(deltatime);
}

void Player::StateRun()
{
	GameData::UIwa = 0;
	static int move_speed = 20;
	static int jump_pow = 13;//元15
	//m_pos_old = m_pos;
	m_pos.x += move_speed;
	//移動
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed/2;
	else if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	if (HOLD(CInput::eUp))
	{
		m_pos.z += move_speed;
	}
	else if (HOLD(CInput::eDown))
	{
		m_pos.z -= move_speed;
	}
	//ジャンプ
	if (PUSH(CInput::eButton5)&&m_is_ground)
	{
		SOUND("SE_Jump")->Play(false);
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//ジャンプ中
	if (!m_is_ground)
	{
		if (m_vec.y < 0)	//上昇中
		{
			m_img.ChangeAnimation(eAnimJumpUp, false);
		}
		else	//下降中
		{
			m_img.ChangeAnimation(eAnimJumpDown, false);
		}
	}
	else
	{
		m_img.ChangeAnimation(eAnimRun);
		static int c = 0;
		if (c++ % 15 == 0) {
			new Effect(m_pos);
			new Effect(m_pos);
			new Effect(m_pos);
			new Effect(m_pos);
		}
	}
	//スクロール設定
	m_scroll.x += move_speed;
}

void Player::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage,false);
	//アニメーション終了時
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 1;
		}
		m_hp -= 1;
		m_state = eState_Run;//走行状態に戻る
		//Delete();//削除テスト
	}
	m_scroll.x += 6/2;
}

void Player::StateDown()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	//アニメーション終了時
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 1;
		}
		Delete();//削除テスト
		new OverFilta();
	}
	m_scroll.x += 6 / 2;
}

void Player::StateFall()
{
	m_img.ChangeAnimation(eAnimFall, false);
	if (m_img.GetIndex() == 3)
	{
		SOUND("SE_Fall")->Play(false);
	}
	//アニメーション終了時
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 3;
		}
		Delete();//削除テスト
		new OverFilta();
	}
	m_scroll.x += 0;
}

//BaseからObjectBase仕様に変更
void Player::Collision(ObjectBase* b)
{
	GameData::UIwa = 1;
	switch (b->GetTag())
	{
	case (int)ETaskTag::eGimick:
		if (CollisionAABB(this, b) && invincibility <= 0)
		{
			invincibility = 120+34;//無敵時間+ダメージモーション時間
			SOUND("SE_Damage")->Play(false);
			if (m_hp > 0) {
				m_state = eState_Damage;
			}
			else {
				m_state = eState_Down;
			}
			
		}
		break;
	case (int)ETaskTag::eFall:
		if (CollisionAABB(this, b))
		{
			m_state = eState_Fall;
		}
		break;
	}
}
