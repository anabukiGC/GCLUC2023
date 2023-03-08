#pragma once
#include<string>

class TaskManager;



class Task
{
	friend TaskManager;

private:
	Task* m_prev;	//�O�̃^�X�N�̃|�C���^�[
	Task* m_next;	//���̃^�X�N�̃|�C���^�[
	int m_priority;	//�D��x


public:
	//�R���X�g���N�^
	Task(int prio);
	//�f�X�g���N�^
	~Task();

	//�D��x�ݒ�
	void SetPriority(int prio);
	//�D��x�擾
	int GetPriority() const;
	//�^�X�N���폜
	void Delete();
	//�X�V����
	virtual void Update(float deltaTime) = 0;

};