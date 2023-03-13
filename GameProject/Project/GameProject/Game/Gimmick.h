#pragma once
//ObjectBase使用
#include"ObjectBase.h"
class Hari : public ObjectBase{
public:
public:
	Hari(const CVector3D& pos);
	void Update(float deltatime);
	//影を描画しないためオーバーライド
	void DrawShadow();
};

//ObjectBase使用
class YIwa :public ObjectBase {
public:
public:
	YIwa(const CVector3D& pos);
	//Task仕様に変更
	void Update(float deltatime);
	//影を使用しないためオーバーライド
	void DrawShadow();
};

//ObjectBase仕様
class XIwa : public ObjectBase {
public:
public:
	XIwa(const CVector3D& pos);
	void Update(float deltatime);
//影を使用しないためオーバーライド
	void DrawShadow();

};

