#pragma once
#include "../Base/Base.h"
class Hari :public Base {
public:
	CImage m_img;
public:
	Hari(const CVector3D& pos);
	void Draw();
};

class YIwa :public Base {
public:
	CImage m_img;
	CImage m_img2;
	CImage m_img3;
public:
	YIwa(const CVector3D& pos);
	void Update();
	void Draw();
};

class XIwa :public Base {
public:
	CImage m_img;
public:
	XIwa(const CVector3D& pos);
	void Draw();
};
