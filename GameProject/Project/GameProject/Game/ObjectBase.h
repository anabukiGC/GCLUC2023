#pragma once
#include"../TaskSystem/Task.h"
#include"../TaskSystem/DrawTask.h"
//�d�͉����x
#define GRAVITY (9.8f/20)
#define X_MIN (-640)
#define X_MAX (900/2)
#define Z_MIN (0)
#define Z_MAX (400)
class ObjectManager;

class ObjectBase :public Task
{
	friend ObjectManager;

private:
	ObjectBase* m_prev;
	ObjectBase* m_next;
	//COPY_RESOUCE���g�p����̂Ŏ��̂�
	CImage m_shadowImage;

	DrawTask* m_drawTask;
	DrawTask* m_shadowDrawTask;

protected:
	//COPY_RESOUCE���g�p����̂Ŏ��̂�
	CImage m_img;
	CVector2D m_imgePos;

	CVector3D m_pos;
	//Base�N���X����ڐA
	CVector3D m_vec;
	bool m_flip;

	//���^
	CAABB m_box;
public:
	//�X�N���[���l
	static CVector2D m_scroll;
	//�R���X�g���N�^
	ObjectBase(int prio,int tag);
	//�f�X�g���N�^
	virtual ~ObjectBase();

	//�L�����N�^�[�̈ʒu���擾
	const CVector3D& GetPos() const;
	//�L�����N�^�[�̕`��D��x��ύX
	void SetDrawPriority(int prio);

	//�X�V
	virtual void Update(float deltaTime);
	//�`��
	virtual void Draw();
	//�Փˌ���
	virtual void Collision(ObjectBase* b){}
	// �e��`��
	virtual void DrawShadow();

	void DrawRect();
	//��`���m�̔���
	static bool CollisionAABB(ObjectBase* b1, ObjectBase* b2);
	static CVector2D GetScreenPos(const CVector3D& pos);

};