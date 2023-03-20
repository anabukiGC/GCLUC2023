#pragma once

class Title : public Task {
public:
	DrawTask* m_drawTask;
	CImage m_title;
	CImage m_titlelogo;
	CImage m_titlebotan;
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update(float deltatime);
	void Draw();
};

