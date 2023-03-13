#include "GimmickManager.h"
#include "ObjectBase.h"
#include "Gimmick.h"

GimmickManager::GimmickManager()
	:Task((int)ETaskPrio::eGimmickManager,(int)ETaskTag::eGimmickManager)
	,m_time(0)
{

}

void GimmickManager::Update(float deletetime){
	m_time++;
	if (m_time > 120) {
		int type = rand() % 3;
		int r = rand() % 3;
		float z[3] = { 0,200,400 };
		switch (type) {
		case 0:
			new YIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r]));
			break;
		}
		m_time = 0;
	}
}
