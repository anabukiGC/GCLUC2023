#include"TaskManager.h"


TaskManager* TaskManager::ms_instance = nullptr;

//コンストラクタ
TaskManager::TaskManager()
	:m_head(nullptr)
{
}

//デストラクタ
TaskManager::~TaskManager()
{
	Task* next = m_head;
	while (next != nullptr)
	{
		Task* deleteTask = next;
		next = next->m_next;
		delete deleteTask;
	}
}

//TaskManagerのインスタンスを取得
TaskManager* TaskManager::Instance()
{
	if (ms_instance == nullptr)
	{
		ms_instance = new TaskManager();
	}
	return ms_instance;
}

//TaskManagerのインスタンスを破棄
void TaskManager::ClearInstance()
{
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//リストにタスクを追加
void TaskManager::AddTask(Task* task)
{
	//リストにタスクが一つもない時
	if (m_head == nullptr)
	{
		m_head = task;
	}
	//リストに既にタスクがある時
	else
	{
		Task* prev = nullptr;
		Task* next = m_head;
		while (next != nullptr)
		{
			if (next->m_priority < task->m_priority) 
			{
				break;
			}
			prev = next;
			next = next->m_next;
		}
		task->m_prev = prev;
		task->m_next = next;
		if (prev != nullptr)
		{
			prev->m_next = task;
		}
		else
		{
			m_head = task;
		}
		if (next != nullptr)
		{
			next->m_prev = task;
		}
	}
}

//リストからタスクを取り除く
void TaskManager::RemoveTask(Task* task)
{
	if (m_head == task)
	{
		m_head = task->m_next;
	}
	Task* prev = task->m_prev;
	Task* next = task->m_next;

	if (prev != nullptr)
	{
		prev->m_next = task->m_next;
	}
	if (next != nullptr)
	{
		next->m_prev = task->m_prev;
	}

	task->m_prev = nullptr;
	task->m_next = nullptr;
}

void TaskManager::AllRemoveTask()
{
	Task* next = m_head;
	while (next != nullptr)
	{
		next->m_kill = true;
		next = next->m_next;
	}
}

//更新処理
void TaskManager::Update()
{
	Task* next = m_head;
	while (next != nullptr)
	{
		//更新中に即消すとここでバグるので,KillフラグON->削除とワンクッション置く
		if (next->m_kill) {
			Task* tmp = next;
			next = next->m_next;
			delete tmp;
		}
		else {
			next->Update(CFPS::GetDeltaTime());
			next = next->m_next;
		}
	}
}