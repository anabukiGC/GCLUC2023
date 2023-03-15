#pragma once

class UI :public Task {
	DrawTask* m_drawTask;
	int m_m;
	int m_km;
	CImage m_life;
	CFont m_title_text;
public:
	UI();
	~UI();
	void Update(float Deletetime);
	void Draw();
};