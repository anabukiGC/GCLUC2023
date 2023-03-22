#pragma once

class GimmickManager : public Task
{
	float m_time;
	int m_time2;
	int m_Itemtime;
public:
	GimmickManager();
	void Update(float deletetime);
};