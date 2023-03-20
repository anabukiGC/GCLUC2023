#pragma once

#include "ObjectBase.h"
class Effect :public ObjectBase {
public:
	Effect(const CVector3D& pos);
	void Update(float deltatime);
	virtual void DrawShadow();
private:
	float m_alppha;
};