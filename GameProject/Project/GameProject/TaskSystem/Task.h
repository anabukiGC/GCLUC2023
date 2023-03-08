#pragma once
#include<string>

class TaskManager;



class Task
{
	friend TaskManager;

private:
	Task* m_prev;	//前のタスクのポインター
	Task* m_next;	//次のタスクのポインター
	int m_priority;	//優先度


public:
	//コンストラクタ
	Task(int prio);
	//デストラクタ
	~Task();

	//優先度設定
	void SetPriority(int prio);
	//優先度取得
	int GetPriority() const;
	//タスクを削除
	void Delete();
	//更新処理
	virtual void Update(float deltaTime) = 0;

};