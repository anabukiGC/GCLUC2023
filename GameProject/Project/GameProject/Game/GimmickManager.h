#pragma once

class GimmickManager : public Task
{
	int m_time;
public:
	GimmickManager();
	void Update(float deletetime);
};