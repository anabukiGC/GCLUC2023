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
	m_filta.Draw();
}

Filta2::Filta2() :Task((int)ETaskPrio::eFilta, (int)ETaskTag::eFilta)
{
	m_filta = COPY_RESOURCE("filta2", CImage);
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&Filta::Draw,
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
	m_filta.Draw();
}