#pragma once
#include"Task.h"

class TaskManager 
{
private:
	static TaskManager* ms_instance;	//TaskManagerのインスタンス
	Task* m_head;

public:
	//コンストラクタ
	TaskManager();
	//デストラクタ
	~TaskManager();

	//TaskManagerのインスタンスを取得
	static TaskManager* Instance();
	//TaskManagerのインスタンスを破壊
	static void ClearInstance();

	//リストにタスクを追加
	void AddTask(Task* task);
	//リストからタスクを取り除く
	void RemoveTask(Task* task);
	//即削除はしない
	//更新処理
	void Update();


};