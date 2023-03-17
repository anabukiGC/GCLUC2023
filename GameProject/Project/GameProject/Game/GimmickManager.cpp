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
	if (m_time > 60) {
		int type = rand() % 3;
		int htype = rand() % 3;
		int r = rand() % 3;
		int xr = rand() % 3;
		float x[3] = { 800,1300,1800 };
		float z[3] = { 0,200,400 };
		switch (type) {
		case 0:
			new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
			break;
		case 1:
			new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r]));
			break;
		case 2:
			switch (htype) {
			case 0:
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[1] - 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[1] - 350));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 150));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 200));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 250));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 300));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[1] - 350));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[1] - 350));
				break;
			case 1:
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2200, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2250, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2200, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2250, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2200, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2250, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2200, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2250, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2200, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2250, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2300, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2350, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2300, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2350, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2300, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2350, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2300, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2350, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2300, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2350, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2400, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2450, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2400, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2450, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2400, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2450, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2400, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2450, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2400, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2450, 0, z[r] - 100));
				
				break;
			case 2:
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1900, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 1950, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2000, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2050, 0, z[r] - 100));

				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] + 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] + 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r]));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] - 50));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2100, 0, z[r] - 100));
				new Hari(CVector3D(ObjectBase::m_scroll.x + 2150, 0, z[r] - 100));
				break;
			}
			break;
		}
		m_time = 0;
	}
}
