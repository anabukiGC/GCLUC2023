#pragma once
//ObjectBase�g�p
#include"ObjectBase.h"

class UIwa :public ObjectBase {
public:
	UIwa(const CVector3D& pos);
	void Update(float deltatime);
	//�e��`�悵�Ȃ����߃I�[�o�[���C�h
	void DrawShadow();
};

class Hari : public ObjectBase{
public:
public:
	Hari(const CVector3D& pos);
	void Update(float deltatime);
	
};

//ObjectBase�g�p
class YIwa :public ObjectBase {
public:
public:
	YIwa(const CVector3D& pos);
	//Task�d�l�ɕύX
	void Update(float deltatime);
};

//ObjectBase�d�l
class XIwa : public ObjectBase {
public:
public:
	XIwa(const CVector3D& pos);
	void Update(float deltatime);


};

//ObjectBase�d�l
class Ana : public ObjectBase {
public:
public:
	Ana(const CVector3D& pos);
	void Update(float deltatime);
	//�e��`�悵�Ȃ����߃I�[�o�[���C�h
	void DrawShadow();

};