#include"DrawTask.h"
#include"DrawTaskManager.h"
#include"Task.h"
//�R���X�g���N�^
DrawTask::DrawTask(Task* task, DrawFunc func, int prio)
	:m_prev(nullptr)
	,m_next(nullptr)
	,m_priority(prio)
	,m_task(task)
	,m_func(func)

{

	DrawTaskManager::Instance()->AddDrawTask(this);
}


//�f�X�g���N�^
DrawTask::~DrawTask()
{
	DrawTaskManager::Instance()->RemoveDrawTask(this);
}

//�D��x�ݒ�
void DrawTask::SetPriority(int prio)
{
	m_priority = prio;
	DrawTaskManager::Instance()->RemoveDrawTask(this);
	DrawTaskManager::Instance()->AddDrawTask(this);
}

//�D��x�擾
int DrawTask::GetPriority() const
{
	return m_priority;
}

//�^�X�N�폜
void DrawTask::Delete()
{
	DrawTaskManager::Instance()->DeleteDrawTask(this);
}

//�`�揈��
void DrawTask::Draw()
{
	if (m_task == nullptr)return;
	if (m_func == nullptr)return;

	(m_task->*m_func)();
}