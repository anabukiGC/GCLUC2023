#pragma once
#include"../Base/Base.h"

class Player : public Base {
private:
	//���
	enum {
		eState_Run,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	//��ԕϐ�
	int m_state;
	//���]�t���O
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
    //�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;
	CImage m_img;

	//�e��Ԃł̋���
	void StateRun();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	Player(const CVector3D& p, bool flip);
	void Update();
	void Collision(Base* b);
	void Draw();
};