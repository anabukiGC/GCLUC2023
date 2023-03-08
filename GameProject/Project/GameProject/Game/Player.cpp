#include "Player.h"
#include "AnimData.h"
#include "Field.h"

Player::Player(const CVector3D& p, bool flip)
	:Base(eType_Player)
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


void Player::Update()
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
	if (PUSH(CInput::eButton5))
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}

	//�f�o�b�O�p
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
{//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�̕\��
	//DrawRect();
}