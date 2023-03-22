#pragma once

class GameData {
public:
	static float life;
	static float score;
	static int Max;
	static int juel_score[];
	static int UIwa;
	static const int Goal = 1000;
	static float PXtoM(float p) { return p / 225; }
	static bool Clear;
};