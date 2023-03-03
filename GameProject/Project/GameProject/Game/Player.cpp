#include "Player.h"
#include "AnimData.h"
#include "Field.h"

Player::Player(const CVector2D& p, bool flip):
	Base(eType_Player) {
		//�摜����
		m_img = COPY_RESOURCE("Player", CImage);
		//�Đ��A�j���[�V�����ݒ�
		m_img.ChangeAnimation(0);
		//���W�ݒ�
		//m_pos_old = m_pos = p ;
		m_pos = p ;
		//���S�ʒu�ݒ�
		m_img.SetCenter(128, 224);
		//���]�t���O
		m_flip = flip;
		//��`����̐ݒ�
		m_rect = CRect(-32, -128, 32, 0);
		//�ʏ��Ԃ�
		m_state = eState_Idle;
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
	//m_pos_old = m_pos;
	m_pos.x += 6;
	m_img.ChangeAnimation(eAnimRun);
		//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//�X�N���[���ݒ�
	m_scroll.x = m_pos.x - 1280 / 2;
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

void Player::Collision(Base* b)
{
	
}