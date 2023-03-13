#pragma once

class Title : public Task {
public:
	DrawTask* m_drawTask;
	CImage m_title;
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update(float deltatime);
	void Draw();
};

