#pragma once

#include"../TaskSystem/Task.h"

class Game : public Task {
private:
public:
	Game();
		void  Update(float deltatime);
};