#pragma once
#include<string>

class TaskManager;

enum class ETaskPrio
{
	eDefault,
	eScene,

	ePlayer,
	eGimmick,

	eGimmickManager,
	eObjectManager,
	eField,

	Num
};
//��ޓI�Ȃ���
enum class ETaskTag
{
	ePlayer,
	eGimick,
	eGimmickManager,
	eObjectManager,
	eField,
	eScene,
};
class Task
{
	friend TaskManager;

private:
	Task* m_prev;	//�O�̃^�X�N�̃|�C���^�[
	Task* m_next;	//���̃^�X�N�̃|�C���^�[
	int m_priority;	//�D��x
	int m_tag;
	bool m_kill;	//�폜�t���O

public:
	//�R���X�g���N�^
	Task(int prio,int tag);
	//�f�X�g���N�^
	virtual ~Task();
	int GetTag() const {
		return m_tag;
	}
	//�D��x�ݒ�
	void SetPriority(int prio);
	//�D��x�擾
	int GetPriority() const;
	//�^�X�N���폜
	void Delete();
	//�X�V����
	virtual void Update(float deltaTime) = 0;

};