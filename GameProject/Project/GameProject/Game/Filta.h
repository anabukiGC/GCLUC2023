#pragma once

class Filta : public Task {
private:
	CImage m_filta;
	DrawTask* m_drawTask;
public:
	//コンストラクタ
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
	//コンストラクタ
	Filta2();
	~Filta2();
	void Update(float deltatime);
	void Draw();
};

class ClearFilta : public Task {
private:
	CImage m_clearfilta;
	CImage m_clearlogo;
	DrawTask* m_drawTask;
public:
	ClearFilta();
	~ClearFilta();
	void Update(float deltatime);
	void Draw();
};

class OverFilta : public Task {
private:
	CImage m_overfilta;
	CImage m_overlogo;
	DrawTask* m_drawTask;
public:
	OverFilta();
	~OverFilta();
	void Update(float deltatime);
	void Draw();
};