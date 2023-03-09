#include"ObjectManager.h"

ObjectManager* ObjectManager::ms_instance = nullptr;

//コンストラクタ
ObjectManager::ObjectManager()
	:Task((int)ETaskPrio::eObjectManager)
	,m_head(nullptr)
	,m_objectCount(0)
	,m_isSort(false)
{
}

//デストラクタ
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
	//リストにタスクが1つもない状態
	if (m_head == nullptr)
	{
		m_head = object;
	}
	//リストに既にタスクがある状態
	else
	{
		ObjectBase* prev = nullptr;
		ObjectBase* next = m_head;
		while (next != nullptr)
		{
			//追加するタスクより優先度が低いタスクが
			//見つかってないので、次のタスクを調べる
			prev = next;
			next = next->m_next;
		}
		//追加するタスクのm_prevの設定
		object->m_prev = prev;
		//追加するタスクのm_nextに優先度が低いタスクを設定
		object->m_next = next;
		if (prev != nullptr)
		{
			//追加するタスクより優先度が高いタスクのm_nextに追加するタスクを設定
			prev->m_next = object;
		}
		//先頭タスクより優先度が高い場合
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

	//取り除くタスクの前後のタスクを接続してやる
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

	//取り除くタスクの接続先は空にする
	object->m_prev = nullptr;
	object->m_next = nullptr;

}

void ObjectManager::Sort()
{
	//キャラクター数が2人以上で無ければ、ソートはできない
	if (m_objectCount < 2)return;

	//シンプルなバブルソート
	// シンプルなバブルソート
	for (int i = 0; i < m_objectCount - 1; i++)
	{
		ObjectBase* left = m_head;
		ObjectBase* right = m_head->m_next;
		int loopCount = m_objectCount - 1 - i;
		while (right != nullptr && loopCount > 0)
		{
			//キャラクターのZ座標を見てソート
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
		//優先度が同じ場合、後から追加したタスクが末尾に追加されるので
		//設定する優先度事態は同じ値でOK
		next->SetDrawPriority((int)EDrawPrio::eChara);
		next = next->m_next;
	}
}

//更新処理
void ObjectManager::Update(float deltaTime)
{
	Sort();
}