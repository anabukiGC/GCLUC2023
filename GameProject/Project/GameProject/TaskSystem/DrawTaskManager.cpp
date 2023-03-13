#include"DrawTaskManager.h"

DrawTaskManager* DrawTaskManager::ms_instance = nullptr;

//�R���X�g���N�^
DrawTaskManager::DrawTaskManager()
	:m_head(nullptr)
{

}

//�f�X�g���N�^
DrawTaskManager::~DrawTaskManager()
{
	DrawTask* next = m_head;
	while (next != nullptr)
	{
		DrawTask* deleteTask = next;
		next = next->m_next;
		delete deleteTask;
	}
}

//DrawTaskManager�̃C���X�^���X���擾
DrawTaskManager* DrawTaskManager::Instance()
{
	if (ms_instance == nullptr)
	{
		ms_instance = new DrawTaskManager;
	}
	return ms_instance;
}

//DrawTaskManager�̃C���X�^���X��j��
void DrawTaskManager::ClearInstance()
{
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//���X�g�Ƀ^�X�N��ǉ�
void DrawTaskManager::AddDrawTask(DrawTask* task)
{
	//���X�g�Ƀ^�X�N��1���Ȃ����
	if (m_head == nullptr)
	{
		m_head = task;
	}
	//���X�g�Ɋ��Ƀ^�X�N��������
	else
	{
		DrawTask* prev = nullptr;
		DrawTask* next = m_head;
		while (next != nullptr)
		{
			//�D��x���r����
			if (next->m_priority > task->m_priority)
			{
				break;
			}

			//�ǉ�����^�X�N���D��x���Ⴂ�^�X�N���������ĂȂ��̂ŁA���̃^�X�N�𒲂ׂ�
			prev = next;
			next = next->m_next;
		}
		//�ǉ�����^�X�N��m_prev�̐ݒ�
		task->m_prev = prev;
		//�ǉ�����^�X�N��m_next�ɗD��x���Ⴂ�^�X�N��ݒ�
		task->m_next = next;

		if (prev != nullptr)
		{
			//�ǉ�����^�X�N���D��x�������^�X�N��m_next�ɒǉ�����^�X�N��ݒ�
			prev->m_next = task;
		}
		//�擪�^�X�N���D��x�������ꍇ
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
void DrawTaskManager::RemoveDrawTask(DrawTask* task)
{
	if (m_head == task)
	{
		m_head = task->m_next;
	}

	//��菜���^�X�N�̑O��̃^�X�N��ڑ����Ă��
	DrawTask* prev = task->m_prev;
	DrawTask* next = task->m_next;

	if (prev != nullptr)
	{
		prev->m_next = task->m_next;
	}
	//�o�O�C��
	if (next != nullptr)
	{
		next->m_prev = task->m_prev;
	}

	//��菜���^�X�N�̐ڑ���͋�ɂ���
	task->m_prev = nullptr;
	task->m_next = nullptr;
}

//�^�X�N���폜����
void DrawTaskManager::DeleteDrawTask(DrawTask* task)
{

}

//�`�揈��
void DrawTaskManager::Draw()
{
	DrawTask* next = m_head;
	while (next != nullptr)
	{
		next->Draw();
		next = next->m_next;
	}
}