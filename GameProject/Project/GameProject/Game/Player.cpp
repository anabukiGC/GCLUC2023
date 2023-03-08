#include "Player.h"
#include "AnimData.h"
#include "Field.h"

Player::Player(const CVector3D& p, bool flip)
	:Base(eType_Player)
{
		//画像複製
		m_img = COPY_RESOURCE("Player", CImage);
		//再生アニメーション設定
		m_img.ChangeAnimation(0);
		//座標設定
		//m_pos_old = m_pos = p ;
		m_pos = p ;
		//中心位置設定
		m_img.SetCenter(267/2, 450);
		//反転フラグ
		m_flip = flip;
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
		m_hp = 100;
}


void Player::Update()
{
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
}

void Player::StateRun()
{
	static int move_speed = 6;
	static int jump_pow = 15;
	//m_pos_old = m_pos;
	m_pos.x += move_speed;
	//移動
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
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
	if (PUSH(CInput::eButton5))
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//デバッグ用
	if (PUSH(CInput::eButton1))
	{
		m_state = eState_Damage;
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
		m_state = eState_Run;//走行状態に戻る
	}
	m_scroll.x += 6/2;
}

void Player::StateDown()
{
}

void Player::Collision(Base* b)
{

}

void Player::Draw()
{//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形の表示
	//DrawRect();
}