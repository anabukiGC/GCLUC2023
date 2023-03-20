#include"Filta.h"
#include"ObjectBase.h"

Filta::Filta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_filta = COPY_RESOURCE("filta", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Filta::Draw,
		(int)EDrawPrio::eFilta
	);
}

Filta::~Filta()
{
	if (m_drawTask)delete m_drawTask;
}

void Filta::Update(float deltatime)
{
	
}

void Filta::Draw()
{
	float a = 1.0 - pow( ObjectBase::m_scroll.x / 200000,4);
	m_filta.SetColor(1, 1, 1, a);
	m_filta.Draw();
}


Filta2::Filta2() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_filta2 = COPY_RESOURCE("filta2", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Filta2::Draw,
		(int)EDrawPrio::eFilta
	);
}

Filta2::~Filta2()
{
	if (m_drawTask)delete m_drawTask;
}

void Filta2::Update(float deltatime)
{
	
}

void Filta2::Draw()
{
	float a = pow(ObjectBase::m_scroll.x / 200000, 4);
	m_filta2.SetColor(1, 1, 1, a);
	m_filta2.Draw();
}

ClearFilta::ClearFilta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_clearfilta = COPY_RESOURCE("clearfilta", CImage);
	m_clearlogo = COPY_RESOURCE("clearlogo", CImage);
	m_drawTask = new DrawTask
	(this,
		(DrawFunc)&ClearFilta::Draw,
		(int)EDrawPrio::eFilta
	);
}

ClearFilta::~ClearFilta()
{
	if (m_drawTask)delete m_drawTask;
}

void ClearFilta::Update(float deltatime)
{
}

void ClearFilta::Draw()
{
	m_clearfilta.Draw();
	m_clearlogo.Draw();
}


OverFilta::OverFilta() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_overfilta = COPY_RESOURCE("overfilta", CImage);
	m_overlogo = COPY_RESOURCE("overlogo", CImage);
	m_drawTask = new DrawTask
	(this,
		(DrawFunc)&OverFilta::Draw,
		(int)EDrawPrio::eFilta
	);
}

OverFilta::~OverFilta()
{
	if (m_drawTask)delete m_drawTask;
}

void OverFilta::Update(float deltatime)
{
}

void OverFilta::Draw()
{
	m_overfilta.Draw();
	m_overlogo.SetPos(250, 0);
	m_overlogo.Draw();
}