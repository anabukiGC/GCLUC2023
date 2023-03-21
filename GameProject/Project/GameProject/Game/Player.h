#pragma once
#include "ObjectBase.h"
//ObjectBase���p��
class Player : public ObjectBase {
private:
	//���
	enum {
		eState_Run,
		eState_Attack,
		eState_Damage,
		eState_Down,
		eState_Fall,
		eState_Clear,
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
	//���G����
	int invincibility;

	//�e��Ԃł̋���
	void StateRun();
	void StateDamage();
	void StateDown();
	void StateFall();
	void StateClear();

public:
	Player(const CVector3D& p, bool flip);
	~Player();
	//Task�d�l
	void Update(float deltatime);
	//ObjectBase�d�l
	void Collision(ObjectBase* b);
	//XIwa�̉e��`�悵�Ȃ����߃I�[�o�[���C�h
	void DrawShadow2();
};