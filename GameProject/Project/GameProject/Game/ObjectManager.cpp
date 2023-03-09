#include"ObjectManager.h"

ObjectManager* ObjectManager::ms_instance = nullptr;

//�R���X�g���N�^
ObjectManager::ObjectManager()
	:Task((int)ETaskPrio::eObjectManager)
	,m_head(nullptr)
	,m_objectCount(0)
	,m_isSort(false)
{
}

//�f�X�g���N�^
ObjectManager::~ObjectManager()
{
	ms_instance = nullptr;
}

ObjectManager* ObjectManager::Instance()
{
	if (ms_instance == nullptr)
	{
		ms_instance = new ObjectManager();
	}
	return ms_instance;
}

void ObjectManager::AddObject(ObjectBase* object)
{
	m_objectCount++;
	//���X�g�Ƀ^�X�N��1���Ȃ����
	if (m_head == nullptr)
	{
		m_head = object;
	}
	//���X�g�Ɋ��Ƀ^�X�N��������
	else
	{
		ObjectBase* prev = nullptr;
		ObjectBase* next = m_head;
		while (next != nullptr)
		{
			//�ǉ�����^�X�N���D��x���Ⴂ�^�X�N��
			//�������ĂȂ��̂ŁA���̃^�X�N�𒲂ׂ�
			prev = next;
			next = next->m_next;
		}
		//�ǉ�����^�X�N��m_prev�̐ݒ�
		object->m_prev = prev;
		//�ǉ�����^�X�N��m_next�ɗD��x���Ⴂ�^�X�N��ݒ�
		object->m_next = next;
		if (prev != nullptr)
		{
			//�ǉ�����^�X�N���D��x�������^�X�N��m_next�ɒǉ�����^�X�N��ݒ�
			prev->m_next = object;
		}
		//�擪�^�X�N���D��x�������ꍇ
		else
		{
			m_head = object;
		}

		if (next != nullptr)
		{
			next->m_prev = object;
		}

	}
}

void ObjectManager::RemoveObject(ObjectBase* object)
{
	m_objectCount--;
	if (m_head == object)
	{
		m_head = object->m_next;
	}

	//��菜���^�X�N�̑O��̃^�X�N��ڑ����Ă��
	ObjectBase* prev = object->m_prev;
	ObjectBase* next = object->m_next;

	if (prev != nullptr)
	{
		prev->m_next = object->m_next;
	}
	if (prev != nullptr)
	{
		next->m_prev = object->m_prev;
	}

	//��菜���^�X�N�̐ڑ���͋�ɂ���
	object->m_prev = nullptr;
	object->m_next = nullptr;

}

void ObjectManager::Sort()
{
	//�L�����N�^�[����2�l�ȏ�Ŗ�����΁A�\�[�g�͂ł��Ȃ�
	if (m_objectCount < 2)return;

	//�V���v���ȃo�u���\�[�g
	// �V���v���ȃo�u���\�[�g
	for (int i = 0; i < m_objectCount - 1; i++)
	{
		ObjectBase* left = m_head;
		ObjectBase* right = m_head->m_next;
		int loopCount = m_objectCount - 1 - i;
		while (right != nullptr && loopCount > 0)
		{
			//�L�����N�^�[��Z���W�����ă\�[�g
			if (left->m_pos.z > right->m_pos.z)
			{
				left->m_next = right->m_next;
				right->m_prev = left->m_prev;
				if (left->m_prev != nullptr)
				{
					left->m_prev->m_next = right;
				}
				if (right->m_next != nullptr)
				{
					right->m_next->m_prev = left;
				}
				left->m_prev = right;
				right->m_next = left;
				if (left == m_head)
				{
					m_head = right;
				}

				right = left->m_next;
			}
			else
			{
				left = right;
				right = right->m_next;
			}
			loopCount--;
		}
	}

	ObjectBase* next = m_head;
	while (next != nullptr)
	{
		//�D��x�������ꍇ�A�ォ��ǉ������^�X�N�������ɒǉ������̂�
		//�ݒ肷��D��x���Ԃ͓����l��OK
		next->SetDrawPriority((int)EDrawPrio::eChara);
		next = next->m_next;
	}
}

//�X�V����
void ObjectManager::Update(float deltaTime)
{
	Sort();
}