#include"DrawTask.h"
#include"Task.h"
#include"DrawTaskManager.h"

//コンストラクタ
DrawTask::DrawTask(Task* task, DrawFunc func, int prio)
	:m_prev(nullptr)
	,m_next(nullptr)
	,m_priority(prio)
	,m_task(task)
	,m_func(func)

{
}

//デストラクタ
DrawTask::~DrawTask()
{
}

//優先度設定
void DrawTask::SetPriority(int prio)
{
	m_priority = prio;
}

//優先度取得
int DrawTask::GetPriority() const
{
	return m_priority;
}

//タスク削除
void DrawTask::Delete()
{
}

//描画処理
void DrawTask::Draw()
{
	if (m_task == nullptr)return;
	if (m_func == nullptr)return;

	(m_task->*m_func)();
}