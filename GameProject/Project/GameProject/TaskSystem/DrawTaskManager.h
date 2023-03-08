#pragma once
#include"DrawTask.h"

class DrawTaskManager
{
private:
	static DrawTaskManager* ms_instance;
	DrawTask* m_head;

public:
	//コンストラクタ
	DrawTaskManager();
	//デストラクタ
	~DrawTaskManager();

	//DrawTaskManagerのインスタンスを取得
	static DrawTaskManager* Instance();
	//DrawTaskManagerのインスタンスを破棄
	static void ClearInstance();

	//リストにタスクを追加
	void AddDrawTask(DrawTask* Task);
	//リストからタスクを取り除く
	void RemoveDrawTask(DrawTask* Task);
	//タスクを削除する
	void DeleteDrawTask(DrawTask* Task);
	//描画処理
	void Draw();

};