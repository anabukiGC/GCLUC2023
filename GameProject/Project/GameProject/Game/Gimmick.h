#pragma once
//ObjectBase使用
#include"ObjectBase.h"
class Hari : public ObjectBase{
public:
public:
	Hari(const CVector3D& pos);
	void Update(float deltatime);
	
};

//ObjectBase使用
class YIwa :public ObjectBase {
public:
public:
	YIwa(const CVector3D& pos);
	//Task仕様に変更
	void Update(float deltatime);
};

//ObjectBase仕様
class XIwa : public ObjectBase {
public:
public:
	XIwa(const CVector3D& pos);
	void Update(float deltatime);


};

//ObjectBase仕様
class Ana : public ObjectBase {
public:
public:
	Ana(const CVector3D& pos);
	void Update(float deltatime);


};