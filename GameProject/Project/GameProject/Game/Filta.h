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

//ゲームクリアのフィルター
class ClearFilta : public Task {
private:
	CImage m_clearfilta;
	CImage m_clearlogo;
	CImage m_end;
	CImage m_continue;
	CImage s_score;
	int m_score;
	DrawTask* m_drawTask;
public:
	ClearFilta();
	~ClearFilta();
	void Update(float deltatime);
	void Draw();
};

//ゲームオーバのフィルター
class OverFilta : public Task {
private:
	CImage m_overfilta;
	CImage m_overlogo;
	CImage m_end;
	CImage m_continue;
	CImage s_score;
	int m_score;
	DrawTask* m_drawTask;
public:
	OverFilta();
	~OverFilta();
	void Update(float deltatime);
	void Draw();
};