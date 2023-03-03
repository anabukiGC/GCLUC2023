#include "Player.h"
#include "AnimData.h"
#include "Field.h"

Player::Player(const CVector2D& p, bool flip):
	Base(eType_Player) {
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
		m_rect = CRect(-32, -128, 32, 0);
		//通常状態へ
		m_state = eState_Idle;
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
	static int move_speed = 6;
	static int jump_pow = 15;
	//m_pos_old = m_pos;
	m_pos.x += move_speed;
	//移動
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	else if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	if (HOLD(CInput::eUp)) {
		m_pos.z += move_speed;
	}
	else if (HOLD(CInput::eDown)) {
		m_pos.z -= move_speed;
	}
	//ジャンプ
	if (PUSH(CInput::eButton5))
		m_vec.y = -jump_pow;
	m_img.ChangeAnimation(eAnimRun);
		//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール設定
	m_scroll.x += move_speed;
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	if (m_pos.y > 0) {
		m_pos.y = 0;
		m_vec.y = 0;
	}
	if (m_pos.z > Z_MAX)
		m_pos.z = Z_MAX;
	if (m_pos.z < Z_MIN)
		m_pos.z = Z_MIN;
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

void Player::Collision(Base* b)
{
	
}