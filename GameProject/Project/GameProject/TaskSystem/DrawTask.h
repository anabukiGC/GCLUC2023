#pragma once
#include<string>

class Task;
class DrawTaskManager;

enum class EDrawPrio
{
	eShadow,
	eChara,

	Num

};

typedef void(Task::* DrawFunc)();

class DrawTask
{
	friend DrawTaskManager;
private:
	DrawTask* m_prev;
	DrawTask* m_next;
	int m_priority;

	Task* m_task;
	DrawFunc m_func;


public:
	//�R���X�g���N�^
	DrawTask(Task* task,DrawFunc func,int prio);
	//�f�X�g���N�^
	~DrawTask();

	//�D��x�ݒ�
	void SetPriority(int prio);
	//�D��x�擾
	int GetPriority() const;

	//�^�X�N�폜
	void Delete();

	//�`�揈��
	void Draw();

};