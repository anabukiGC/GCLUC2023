#include"ObjectBase.h"
#include"ObjectManager.h"
#define Z_CENTER 432
//�X�N���[���l�͂����ֈڐA
CVector2D ObjectBase::m_scroll(0, 0);

//tag���I�u�W�F�N�g�̎��
//�R���X�g���N�^
ObjectBase::ObjectBase(int prio,int tag)
	:Task(prio, tag)
	, m_prev(nullptr)
	, m_next(nullptr)
	, m_imgePos(0.0f, 0.0f)
	,m_pos(0.0f,0.0f,0.0f)
{
	//�I�u�W�F�N�g�̃��X�g�֒ǉ�
	ObjectManager::Instance()->AddObject(this);
	//�L�����N�^�[�`���o�^
	m_drawTask = new DrawTask
	(
		this,
		(DrawFunc)&ObjectBase::Draw,
		(int)EDrawPrio::eChara
	);
	//�e�`���o�^
	m_shadowDrawTask = new DrawTask
	(
		this,
		(DrawFunc)&ObjectBase::DrawShadow,
		(int)EDrawPrio::eShadow
	);
	//�e�̐ݒ�(�e�̉摜���ύX����)
	CVector2D shadowSize = CVector2D(192, 48);
	m_shadowImage = COPY_RESOURCE("Statekage", CImage);
	m_shadowImage.SetSize(shadowSize);
	m_shadowImage.SetCenter(CVector2D(shadowSize.x * 0.5f, shadowSize.y * 0.5f));
}

ObjectBase::~ObjectBase()
{
	//�I�u�W�F�N�g���X�g�����菜��
	ObjectManager::Instance()->RemoveObject(this);
	//�`��^�X�N�j��
	if (m_shadowDrawTask) delete m_shadowDrawTask;
	if (m_drawTask) delete m_drawTask;

}

const CVector3D& ObjectBase::GetPos() const
{
	return m_pos;
}

void ObjectBase::SetDrawPriority(int prio)
{
	m_drawTask->SetPriority(prio);
}

void ObjectBase::Update(float deltaTime)
{
	//�e�̈ʒu(������0�Ōv�Z)
	CVector3D shadowPos(m_pos.x, 0, m_pos.z);
	//�L�����N�^�[�Ɠ����v�Z
	m_shadowImage.SetPos(GetScreenPos(shadowPos));
}

void ObjectBase::Draw()
{
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
#ifdef _DEBUG
	//�����蔻���`�̕\��
	//DrawRect()
#endif
}

void ObjectBase::DrawShadow()
{
	//�e�̕`��
	m_shadowImage.Draw();
}
//���R����̃f�o�b�O��`�`����ڐA
void ObjectBase::DrawRect()
{
	//���W+Box�̕��A�����A���s
	CAABB box = CAABB(m_pos + m_box.min, m_pos + m_box.max);
	//��O�̋�`
	Utility::DrawQuad(
		GetScreenPos(box.min),
		CVector2D(box.max.x - box.min.x, box.max.y - box.min.y),
		CVector4D(1, 0, 0, 0.5f)
	);
	//���̋�`
	Utility::DrawQuad(
		GetScreenPos(CVector3D(box.min.x, box.min.y, box.max.z)),
		CVector2D(box.max.x - box.min.x, box.max.y - box.min.y),
		CVector4D(1, 0, 0, 0.5f)
	);
}

//���R�����AABB�Փ˔�����ڐA
bool ObjectBase::CollisionAABB(ObjectBase* b1, ObjectBase* b2)
{
	//b1�̔��`
	CAABB box1 = CAABB(
		CVector3D(b1->m_pos.x + b1->m_box.min.x, b1->m_pos.y + b1->m_box.min.y, b1->m_pos.z + b1->m_box.min.z),
		CVector3D(b1->m_pos.x + b1->m_box.max.x, b1->m_pos.y + b1->m_box.max.y, b1->m_pos.z + b1->m_box.max.z)
	);
	//b2�̔��`
	CAABB box2 = CAABB(
		CVector3D(b2->m_pos.x + b2->m_box.min.x, b2->m_pos.y + b2->m_box.min.y, b2->m_pos.z + b2->m_box.min.z),
		CVector3D(b2->m_pos.x + b2->m_box.max.x, b2->m_pos.y + b2->m_box.max.y, b2->m_pos.z + b2->m_box.max.z)
	);

	//���`���m�̔���
	if ((box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
		(box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
		(box1.min.z <= box2.max.z && box1.max.z >= box2.min.z))
		return true;

	return false;
}
//�L�����N�^�[���W����ʏ�ł̍��W��ϊ�
CVector2D ObjectBase::GetScreenPos(const CVector3D& pos)
{
	//���W�[�X�N���[���l����ʏ�ł̈ʒu
	return CVector2D(pos.x + pos.z / 2 + 720, pos.y - pos.z / 2 + 1040) - m_scroll;
}