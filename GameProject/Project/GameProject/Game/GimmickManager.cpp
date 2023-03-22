#include "GimmickManager.h"
#include "ObjectBase.h"
#include "Gimmick.h"
#include "Item.h"
#include "GameData.h"

GimmickManager::GimmickManager()
	:Task((int)ETaskPrio::eGimmickManager,(int)ETaskTag::eGimmickManager)
	,m_time(0)
	, m_time2(0)
	, m_Itemtime(0)
{

}

void GimmickManager::Update(float deletetime) {
	if (GameData::Clear || GameData::life <= 0)return;
	m_time += GameData::PXtoM(ObjectBase::m_scroll.x)/400+1;
	
	if (m_time > 240) {
		int type = rand() % 4;
		int htype = rand() % 3;
		int ytype = rand() % 4;
		int jtype = rand() % 5;//•óÎ‚ÌŽí—Þ
		int jtype2 = 2 + rand() % 3;//•óÎ‚ÌŽí—Þ
		int r = rand() % 3;
		int xr = rand() % 3;
		int rx = rand() % 3;
		int rz = rand() % 3;
		int jr = rand() % 3;
		float x[3] = { 500,650,800 };
		float z[3] = { 0,200,400 };
		float xz[3] = { 0 + 112,200 + 112,400 + 112 };
		int axr = rand() % 2;
		int azr = rand() % 2;
		float ax[2] = { 600,1200 };
		float az[3] = { 1000,800,600 };
		switch (type) {
		case 0://YŠâ
			if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 750) {//750
				new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
				new Item(CVector3D(ObjectBase::m_scroll.x + 1350, 0, z[(r + rz) % 3]), jtype2);
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 500) {//500
				switch (ytype) {
				case 0:
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[(r + rz) % 3]));
					break;
				case 1:
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[(r + rz) % 3]));
					break;
				case 2:
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					break;
				case 3:
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[(xr + rx) % 3], 0, az[(r + rz) % 3]));
					break;
				}
				break;
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 250) {//250
				new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
				new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[(r + rz) % 3]));
			}
			else {
				new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[r]));
			}
			break;
		case 1://XŠâ
			if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 750) {//750
				//new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
				new Item(CVector3D(ObjectBase::m_scroll.x + 1350, 0, z[r]), jtype2);
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 500) {//500
				switch (ytype) {
				case 0:
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[(r + rz) % 3]));
					break;
				case 1:
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[(xr + rx) % 3], -800, z[(r + rz) % 3]));
					break;
				case 2:
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					break;
				case 3:
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[(xr + rx) % 3], 0, az[(r + rz) % 3]));
					break;
				}
				break;
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 250) {//250
				new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
				new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[(r + rz) % 3]));
			}
			else {
				new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
			}
			break;
		case 2://j
			if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 750) {//750
				switch (htype) {
				case 0:
					for (int j = 0; j <= 1; j++) {
						for (int i = 0; i <= 15; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
						}
					}
					break;
				case 1:
					for (int j = 0; j <= 5; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				case 2:
					for (int j = 0; j <= 2; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				}
				break;
				new Item(CVector3D(ObjectBase::m_scroll.x + 1350, 0, z[(r + rz) % 3]), jtype2);
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 500) {//500
				switch (ytype) {
				case 0:
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[(r + rz) % 3]));
					break;
				case 1:
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[(xr + rx) % 3], -800, z[(r + rz) % 3]));
					break;
				case 2:
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr], 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr], 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr] + 100, 0, z[(r + rz) % 3] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr] + 100, 0, z[(r + rz) % 3] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr], 0, z[(r + rz) % 3] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr], 0, z[(r + rz) % 3] + 100 - (50 * i)));
							}
						}
						break;
					}
					break;
				case 3:
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[(xr + rx) % 3], 0, az[(r + rz) % 3]));
					break;
				}
				break;
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 250) {//250
				switch (htype) {
				case 0:
					for (int j = 0; j <= 1; j++) {
						for (int i = 0; i <= 15; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
						}
					}
					break;
				case 1:
					for (int j = 0; j <= 5; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				case 2:
					for (int j = 0; j <= 2; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				}
				switch (htype) {
				case 0:
					for (int j = 0; j <= 1; j++) {
						for (int i = 0; i <= 15; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr], 0, z[1] + 350 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr], 0, z[1] + 350 - (50 * i)));
						}
					}
					break;
				case 1:
					for (int j = 0; j <= 5; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr] + 100, 0, z[(r + rz) % 3] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr] + 100, 0, z[(r + rz) % 3] + 100 - (50 * i)));
						}
					}
					break;
				case 2:
					for (int j = 0; j <= 2; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100) + x[xr], 0, z[(r + rz) % 3] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100) + x[xr], 0, z[(r + rz) % 3] + 100 - (50 * i)));
						}
					}
					break;
				}
				break;
			}
			else {
				switch (htype) {
				case 0:
					for (int j = 0; j <= 1; j++) {
						for (int i = 0; i <= 15; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
						}
					}
					break;
				case 1:
					for (int j = 0; j <= 5; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				case 2:
					for (int j = 0; j <= 2; j++) {
						for (int i = 0; i <= 4; i++) {
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
							new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
						}
					}
					break;
				}
				break;
			}
			break;
		case 3://—Ž‚Æ‚µŒŠ
			if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 750) {//750
				new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
				new Item(CVector3D(ObjectBase::m_scroll.x + 1350, 0, z[(r + rz) % 3]), jtype2);
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 500) {//500
				switch (ytype) {
				case 0:
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
					break;
				case 1:
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
					new YIwa(CVector3D(ObjectBase::m_scroll.x + x[xr], -800, z[(r + rz) % 3]));
					break;
				case 2:
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
					new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[(r + rz) % 3]));
					break;
				case 3:
					new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
					switch (htype) {
					case 0:
						for (int j = 0; j <= 1; j++) {
							for (int i = 0; i <= 15; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[1] + 350 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[1] + 350 - (50 * i)));
							}
						}
						break;
					case 1:
						for (int j = 0; j <= 5; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					case 2:
						for (int j = 0; j <= 2; j++) {
							for (int i = 0; i <= 4; i++) {
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1900 + (j * 100), 0, z[r] + 100 - (50 * i)));
								new Hari(CVector3D(ObjectBase::m_scroll.x + 1950 + (j * 100), 0, z[r] + 100 - (50 * i)));
							}
						}
						break;
					}
					break;
				}
				break;
			}
			else if (GameData::PXtoM(ObjectBase::m_scroll.x) >= 250) {//250
				new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
				new Ana(CVector3D(ObjectBase::m_scroll.x + ax[(azr + rx) % 3], 0, az[(azr + rz) % 3]));
			}
			else {
				new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
			}
			break;
		//case 4:
		//	//new XIwa(CVector3D(ObjectBase::m_scroll.x + 1900, 0, xz[r]));
		//	new Ana(CVector3D(ObjectBase::m_scroll.x + ax[axr], 0, az[azr]));
		//	new Ana(CVector3D(ObjectBase::m_scroll.x + ax[(azr + rx) % 3], 0, az[(azr + rz) % 3]));
		//	break;
		}
		m_time = 0;
	}

	m_Itemtime++;
	if (m_Itemtime>=120) {
		int jtype = rand() % 5;//•óÎ‚ÌŽí—Þ
		int jr = rand() % 3;
		int r = rand() % 3;
		float z[3] = { 0,200,400 };
		if (jr == 0) {
			new Item(CVector3D(ObjectBase::m_scroll.x + 1350, 0, z[r]), jtype);
		}
		m_Itemtime = 0;
	}

	m_time2++;
	if (m_time2 > 30) {
		int r2 = rand() % 3;
		int ry2 = rand() % 3;
		int rz2 = rand() % 2;
		//float x2[3] = { 500,650,800 };
		float x2[3] = { -200,-100,0 };
		float y2[3] = { -1000,-1200,-1400 };
		float z2[2] = { 800,0 };
		new UIwa(CVector3D(ObjectBase::m_scroll.x + -500, y2[ry2], z2[rz2]));
		//new UIwa(CVector3D(ObjectBase::m_scroll.x + -100, -1000, z2[rz2]));
		m_time2 = 0;
	}

}
