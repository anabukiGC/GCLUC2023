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
		//�摜����
		m_img = COPY_RESOURCE("Player", CImage);
		//�Đ��A�j���[�V�����ݒ�
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		//m_pos_old = m_pos = p ;
		m_pos = p ;
		//���S�ʒu�ݒ�
		//��m_img.SetCenter(267/2, 450);
		m_img.SetCenter(267/2, 430);
		//���]�t���O
		m_flip = flip;
		//���`����̐ݒ�(�����͗]����)
		//��m_box = CAABB(CVector3D(-267 / 2 + 21, -450, 0), CVector3D(267 / 2 - 36, -19, 267 / 8));
		m_box = CAABB(CVector3D(-267 / 2 + 21, -410, 0), CVector3D(267 / 2 - 36, -19, 267 / 8));
		//��`����̐ݒ�
		//m_rect = CRect(-32, -128, 32, 0);
		//�ʏ��Ԃ�
		m_state = eState_Run;
		//���n�t���O
		m_is_ground = true;
		//�U���ԍ�
		m_attack_no = rand();
		//�_���[�W�ԍ�
		m_damage_no = -1;
		//�q�b�g�|�C���g
		m_hp = 2;
		//���G����
		invincibility = 0;
}

Player::~Player()
{
	SOUND("BGM_Game")->Pause();
}

//Task�g�p
void Player::Update(float deltatime)
{
	invincibility--;
	switch (m_state)
	{
	case eState_Run://���s���
		StateRun();
		break;
	case eState_Damage://�_���[�W���
		StateDamage();
		break;
	case eState_Down://�_�E�����
		StateDown();
		break;
	case eState_Fall://�������
		StateFall();
		break;
	}
	
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	m_vec.y += GRAVITY;
	m_pos += m_vec;
	//�ړ�����
	if (m_pos.y > 0)
	{
		//���n
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
	static int jump_pow = 13;//��15
	//m_pos_old = m_pos;
	m_pos.x += move_speed;
	//�ړ�
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
	//�W�����v
	if (PUSH(CInput::eButton5)&&m_is_ground)
	{
		SOUND("SE_Jump")->Play(false);
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//�W�����v��
	if (!m_is_ground)
	{
		if (m_vec.y < 0)	//�㏸��
		{
			m_img.ChangeAnimation(eAnimJumpUp, false);
		}
		else	//���~��
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
	//�X�N���[���ݒ�
	m_scroll.x += move_speed;
}

void Player::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage,false);
	//�A�j���[�V�����I����
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 1;
		}
		m_hp -= 1;
		m_state = eState_Run;//���s��Ԃɖ߂�
		//Delete();//�폜�e�X�g
	}
	m_scroll.x += 6/2;
}

void Player::StateDown()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	//�A�j���[�V�����I����
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 1;
		}
		Delete();//�폜�e�X�g
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
	//�A�j���[�V�����I����
	if (m_img.CheckAnimationEnd())
	{
		if (GameData::life > 0) {
			GameData::life -= 3;
		}
		Delete();//�폜�e�X�g
		new OverFilta();
	}
	m_scroll.x += 0;
}

//Base����ObjectBase�d�l�ɕύX
void Player::Collision(ObjectBase* b)
{
	GameData::UIwa = 1;
	switch (b->GetTag())
	{
	case (int)ETaskTag::eGimick:
		if (CollisionAABB(this, b) && invincibility <= 0)
		{
			invincibility = 120+34;//���G����+�_���[�W���[�V��������
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
