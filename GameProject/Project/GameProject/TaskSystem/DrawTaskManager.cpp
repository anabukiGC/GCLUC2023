#include"DrawTaskManager.h"

DrawTaskManager* DrawTaskManager::ms_instance = nullptr;

//コンストラクタ
DrawTaskManager::DrawTaskManager()
	:m_head(nullptr)
{

}

//デストラクタ
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

//DrawTaskManagerのインスタンスを取得
DrawTaskManager* DrawTaskManager::Instance()
{
	if (ms_instance == nullptr)
	{
		ms_instance = new DrawTaskManager;
	}
	return ms_instance;
}

//DrawTaskManagerのインスタンスを破棄
void DrawTaskManager::ClearInstance()
{
	if (ms_instance != nullptr)
	{
		delete ms_instance;
		ms_instance = nullptr;
	}
}

//リストにタスクを追加
void DrawTaskManager::AddDrawTask(DrawTask* task)
{
	//リストにタスクが1つもない状態
	if (m_head == nullptr)
	{
		m_head = task;
	}
	//リストに既にタスクがある状態
	else
	{
		DrawTask* prev = nullptr;
		DrawTask* next = m_head;
		while (next != nullptr)
		{
			//優先度を比較する
			if (next->m_priority > task->m_priority)
			{
				break;
			}

			//追加するタスクより優先度が低いタスクが見つかってないので、次のタスクを調べる
			prev = next;
			next = next->m_next;
		}
		//追加するタスクのm_prevの設定
		task->m_prev = prev;
		//追加するタスクのm_nextに優先度が低いタスクを設定
		task->m_next = next;

		if (prev != nullptr)
		{
			//追加するタスクより優先度が高いタスクのm_nextに追加するタスクを設定
			prev->m_next = task;
		}
		//先頭タスクより優先度が高い場合
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
void DrawTaskManager::RemoveDrawTask(DrawTask* task)
{
	if (m_head == task)
	{
		m_head = task->m_next;
	}

	//取り除くタスクの前後のタスクを接続してやる
	DrawTask* prev = task->m_prev;
	DrawTask* next = task->m_next;

	if (prev != nullptr)
	{
		prev->m_next = task->m_next;
	}
	//バグ修正
	if (next != nullptr)
	{
		next->m_prev = task->m_prev;
	}

	//取り除くタスクの接続先は空にする
	task->m_prev = nullptr;
	task->m_next = nullptr;
}

//タスクを削除する
void DrawTaskManager::DeleteDrawTask(DrawTask* task)
{

}

//描画処理
void DrawTaskManager::Draw()
{
	DrawTask* next = m_head;
	while (next != nullptr)
	{
		next->Draw();
		next = next->m_next;
	}
}