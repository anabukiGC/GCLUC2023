#pragma once
#include "ObjectBase.h"

class ObjectManager : public Task
{
private:
	static ObjectManager* ms_instance;
	ObjectBase* m_head;
	int m_objectCount;
	bool m_isSort;

public:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* Instance();

	void AddObject(ObjectBase* object);
	void RemoveObject(ObjectBase* object);

	void Sort();
	void Update(float deltaTime);
	//ObjectBase“¯m‚ÌÕ“ËŒŸØ
	void Collision();


};