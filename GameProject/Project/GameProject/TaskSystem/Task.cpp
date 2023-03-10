#include"Task.h"
#include"TaskManager.h"

//コンストラクタ
Task::Task(int prio,int tag)
	:m_prev(nullptr)
	,m_next(nullptr)
	,m_priority(prio)
	,m_tag(tag)
	,m_kill(false)
{
	TaskManager::Instance()->AddTask(this);
}

//デストラクタ
Task::~Task()
{
	TaskManager::Instance()->RemoveTask(this);
}

//優先度設定
void Task::SetPriority(int prio)
{
	m_priority = prio;
	TaskManager::Instance()->RemoveTask(this);
	TaskManager::Instance()->AddTask(this);
}

//優先度取得
int Task::GetPriority() const
{
	return m_priority;
}

//タスクを削除
void Task::Delete()
{
	m_kill = true;
}
