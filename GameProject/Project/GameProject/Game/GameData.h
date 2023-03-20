#pragma once

class GameData {
public:
	static float life;
	static float score;
	static int UIwa;
	static float PXtoM(float p) { return p / 225; }
};