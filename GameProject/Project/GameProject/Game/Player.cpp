#include "Player.h"
#include "AnimData.h"
#include "Field.h"

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
		m_img.SetCenter(267/2, 450);
		//���]�t���O
		m_flip = flip;
		//���`����̐ݒ�(�����͗]����)
		m_box = CAABB(CVector3D(-267 / 2 + 21, -450, 0), CVector3D(267 / 2 - 36, -19, 267 / 8));
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
		m_hp = 100;
}

//Task�g�p
void Player::Update(float deltatime)
{
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
	static int move_speed = 6;
	static int jump_pow = 15;
	//m_pos_old = m_pos;
	m_pos.x += move_speed;
	//�ړ�
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
	//�W�����v
	if (PUSH(CInput::eButton5)&&m_is_ground)
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
		

	//�_���[�W���[�V�����m�F�p(��ŏ���)
	if (PUSH(CInput::eButton1))
	{
		m_state = eState_Damage;
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
		m_state = eState_Run;//���s��Ԃɖ߂�
		//Delete();//�폜�e�X�g
	}
	m_scroll.x += 6/2;
}

void Player::StateDown()
{
}
//Base����ObjectBase�d�l�ɕύX
void Player::Collision(ObjectBase* b)
{

	switch (b->GetTag())
	{
	case (int)ETaskTag::eGimick:
		if (CollisionAABB(this, b))
		{
			m_state = eState_Damage;
		}
		break;
	}
}
