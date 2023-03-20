#pragma once

class GimmickManager : public Task
{
	int m_time;
	int m_time2;
public:
	GimmickManager();
	void Update(float deletetime);
};