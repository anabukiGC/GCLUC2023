#pragma once
#include<string>

class TaskManager;

enum class ETaskPrio
{
	eDefault,
	eScene,

	ePlayer,
	eGimmick,

	eGimmickManager,
	eObjectManager,
	eField,

	Num
};
//種類的なもの
enum class ETaskTag
{
	ePlayer,
	eGimick,
	eGimmickManager,
	eObjectManager,
	eField,
	eScene,
};
class Task
{
	friend TaskManager;

private:
	Task* m_prev;	//前のタスクのポインター
	Task* m_next;	//次のタスクのポインター
	int m_priority;	//優先度
	int m_tag;
	bool m_kill;	//削除フラグ

public:
	//コンストラクタ
	Task(int prio,int tag);
	//デストラクタ
	virtual ~Task();
	int GetTag() const {
		return m_tag;
	}
	//優先度設定
	void SetPriority(int prio);
	//優先度取得
	int GetPriority() const;
	//タスクを削除
	void Delete();
	//更新処理
	virtual void Update(float deltaTime) = 0;

};