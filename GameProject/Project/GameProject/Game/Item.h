#pragma once
#include"ObjectBase.h"

class Item :public ObjectBase {
private:
	int m_juel_type;//•óÎ‚Ìí—Ş
public:
	Item(const CVector3D& pos, int juel_type);
	void Update(float deltatime);
};