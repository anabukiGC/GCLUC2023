#pragma once

class Filta : public Task {
private:
	CImage m_filta;
	DrawTask* m_drawTask;
public:
	//�R���X�g���N�^
	Filta();
	~Filta();
	void Update(float deltatime);
	void Draw();
};

class Filta2 : public Task {
private:
	CImage m_filta2;
	DrawTask* m_drawTask;
public:
	//�R���X�g���N�^
	Filta2();
	~Filta2();
	void Update(float deltatime);
	void Draw();
};