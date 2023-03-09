#pragma once
#include<string>

class Task;
class DrawTaskManager;

enum class EDrawPrio
{
	eShadow,
	eChara,

	Num

};

typedef void(Task::* DrawFunc)();

class DrawTask
{
	friend DrawTaskManager;
private:
	DrawTask* m_prev;
	DrawTask* m_next;
	int m_priority;

	Task* m_task;
	DrawFunc m_func;


public:
	//コンストラクタ
	DrawTask(Task* task,DrawFunc func,int prio);
	//デストラクタ
	~DrawTask();

	//優先度設定
	void SetPriority(int prio);
	//優先度取得
	int GetPriority() const;

	//タスク削除
	void Delete();

	//描画処理
	void Draw();

};