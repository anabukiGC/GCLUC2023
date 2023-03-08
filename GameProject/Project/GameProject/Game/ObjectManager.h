#pragma once

class ObjectManager : public Task
{
private:
	static ObjectManager* ms_instance;
	ObjectBase* m_head;
	int m_charaCount;
	bool m_isSort;

public:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* Instance();

	void AddObject(ObjectBase*);
};