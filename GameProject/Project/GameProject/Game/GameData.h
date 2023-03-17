#pragma once

class GameData {
public:
	static float life;
	static float score;
	static float PXtoM(float p) { return p / 225; }
};