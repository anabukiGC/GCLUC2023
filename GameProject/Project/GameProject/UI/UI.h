#pragma once

class UI :public Task {
	DrawTask* m_drawTask;
	int m_m;
	int m_score;
	int m_km;
	CImage m_life;
	CFont m_title_text;
public:
	UI();
	~UI();
	void Update(float Deletetime);
	void Draw();
};

class UI2 : public Task {
	DrawTask* m_drawTask;
	CImage m_clear;
	CImage m_over;
	int UI_Type;
public:
	UI2(int ui_type);
	~UI2();
	void Update(float Deletetime);
	void Draw();
};