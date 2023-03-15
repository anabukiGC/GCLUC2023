#include"TaskManager.h"


TaskManager* TaskManager::ms_instance = nullptr;

//�R���X�g���N�^
TaskManager::TaskManager()
	:m_head(nullptr)
{
}

//�f�X�g���N�^
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

//TaskManager�̃C���X�^���X���擾
TaskManager* TaskManager::Instance()
{
	if (ms_instance == nullptr)
	{
		ms_instance = new TaskManager();
	}
	return ms_instance;
}

//TaskManager�̃C���X�^���X��j��
void TaskManager::ClearInstance()
{
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//���X�g�Ƀ^�X�N��ǉ�
void TaskManager::AddTask(Task* task)
{
	//���X�g�Ƀ^�X�N������Ȃ���
	if (m_head == nullptr)
	{
		m_head = task;
	}
	//���X�g�Ɋ��Ƀ^�X�N�����鎞
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

//���X�g����^�X�N����菜��
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

//�X�V����
void TaskManager::Update()
{
	Task* next = m_head;
	while (next != nullptr)
	{
		//�X�V���ɑ������Ƃ����Ńo�O��̂�,Kill�t���OON->�폜�ƃ����N�b�V�����u��
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