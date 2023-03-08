#pragma once
#include"../TaskSystem/Task.h"
#include"../TaskSystem/DrawTask.h"
#include <GLLibrary.h>


class ObjectManager;

class ObjectBase :public Task
{
	friend ObjectManager;

private:
	ObjectBase* m_prev;
	ObjectBase* m_next;
	CImage* m_shadowImage;

	DrawTask* m_drawTask;
	DrawTask* m_shadowDrawTask;

protected:
	CImage* m_image;
	CVector2D m_imgePos;

	CVector3D m_pos;

public:
	//�R���X�g���N�^
	ObjectBase(int prio);
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
	// �e��`��
	void DrawShadow();
};