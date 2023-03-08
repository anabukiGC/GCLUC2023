#include"ObjectBase.h"
#include"ObjectManager.h"

#define Z_CENTER 432

//コンストラクタ
ObjectBase::ObjectBase(int prio)
	:Task(prio)
	, m_prev(nullptr)
	, m_next(nullptr)
	, m_shadowImage(nullptr)
	, m_image(nullptr)
	, m_imgePos(0.0f, 0.0f)
	,m_pos(0.0f,0.0f,0.0f)
{

}

ObjectBase::~ObjectBase()
{
	if (m_shadowImage != nullptr)
	{
		delete m_shadowImage;
	}

	if (m_image != nullptr)
	{
		delete m_image;
	}

}

const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

void ObjectBase::SetDrawPriority(int prio)
{
	
}

void ObjectBase::Update(float deltaTime)
{
	if (m_image != nullptr)
	{
		CVector2D shadowPos(m_pos.x, Z_CENTER + m_pos.z);
		shadowPos.x = roundf(shadowPos.x);
		shadowPos.y = roundf(shadowPos.y);
		m_shadowImage->SetPos(shadowPos);
	}
}

void ObjectBase::Draw()
{
	if (m_image != nullptr)
	{
		m_image->Draw();
	}
}

void ObjectBase::DrawShadow()
{
	if (m_image != nullptr)
	{
		m_shadowImage->Draw();
	}
}