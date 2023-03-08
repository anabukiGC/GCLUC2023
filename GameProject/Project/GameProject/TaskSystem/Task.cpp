#include"Task.h"
#include"TaskManager.h"

//�R���X�g���N�^
Task::Task(int prio)
	:m_prev(nullptr)
	,m_next(nullptr)
	,m_priority(prio)
{
	TaskManager::Instance()->AddTask(this);
}

//�f�X�g���N�^
Task::~Task()
{
	TaskManager::Instance()->RemoveTask(this);
}

//�D��x�ݒ�
void Task::SetPriority(int prio)
{
	m_priority = prio;
	TaskManager::Instance()->RemoveTask(this);
	TaskManager::Instance()->AddTask(this);
}

//�D��x�擾
int Task::GetPriority() const
{
	return m_priority;
}

//�^�X�N���폜
void Task::Delete()
{
	TaskManager::Instance()->DeleteTask(this);
}
