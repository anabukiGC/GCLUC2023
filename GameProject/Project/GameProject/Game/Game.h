#pragma once

#include"../TaskSystem/Task.h"

class Game : public Task {
public:
	DrawTask* m_drawTask;
	int m_next;
public:
	Game();
	~Game();
		void  Update(float deltatime);
};