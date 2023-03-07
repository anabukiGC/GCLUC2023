#include "Title.h"

Title::Title():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("title", CImage);
}

Title::~Title()
{
}

void Title::Update()
{
}

void Title::Draw()
{
}
