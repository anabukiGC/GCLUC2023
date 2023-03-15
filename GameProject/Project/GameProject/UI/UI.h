#pragma once

class UI :public Task {
	int m_km;
public:
	UI(const CVector2D& pos);
	void Update(float Deletetime);
};