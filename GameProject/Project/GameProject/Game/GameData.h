#pragma once

class GameData {
public:
	static float life;
	static float score;
	static int juel_score[];
	static int UIwa;
	static float PXtoM(float p) { return p / 225; }
	static bool Clear;
};