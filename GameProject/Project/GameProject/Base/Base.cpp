#include "Base.h"
std::list<Base*> Base::m_list;
//�X�N���[���l�̒�`
CVector2D Base::m_scroll(0, 0);


Base::Base(int type):m_type(type),m_pos(0,0,0),m_vec(0,0,0), m_rad(0),m_kill(false) {

}

void Base::DrawRect()
{
	//���`��x��y������\��
	CRect rect = CRect(
		m_pos.x + m_box.min.x,//��
		m_pos.y + m_box.min.y,//��
		m_pos.x + m_box.max.x,//�E
		m_pos.y + m_box.max.y//��
	);
	Utility::DrawQuad(
		CVector2D(rect.m_left + 720, rect.m_top + 1040) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f)
	);
}

CVector2D Base::GetScreenPos(const CVector3D& pos) {
	//���W�[�X�N���[���l����ʏ�ł̈ʒu
	return CVector2D(pos.x+pos.z/2+720,pos.y-pos.z/2+1040) - m_scroll;
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	if (l < b1->m_rad + b2->m_rad) {
		return true;
	}
	return false;
}
Base* Base::FindObject(int type)
{
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		if((*it)->m_type==type){
		//�������I�u�W�F�N�g�̕ԋp
		return(*it);
	}
	it++;
}
	return nullptr;
}
Base::~Base() {

}
void Base::Update() {
	
}
void Base::Collision(Base* b)
{

}

bool Base::CollisionAABB(Base* b1, Base* b2)
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

void Base::Draw() {

}
void Base::UpdateAll()
{
	//�S�ẴI�u�W�F�N�g�̍X�V
for (auto& b : m_list) {
		b->Update();
	}
}

void Base::DrawAll()
{
	//�S�ẴI�u�W�F�N�g�̕`�揈��
	for (auto& b : m_list) {
		b->Draw();
	}
	
}

void Base::CollisionAll()
{
	auto it1 = m_list.begin();
	auto last = m_list.end();
	while (it1 != last) {
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		it1++;
	}
}
void Base::CheckKillAll()
{
	auto it = m_list.begin();
	auto last = m_list.end();
	while (it != last) {
		if ((*it)->m_kill) {
			delete(*it);
			it = m_list.erase(it);
		}
		else {
			//����
			it++;
		}
	}
}
void Base::Add(Base* b)
{
	//
	auto itr = m_list.begin();
	while (itr != m_list.end()) {
		if ((*itr)->m_type > b->m_type) {
			m_list.insert(itr, b);
			return;
		}
		itr++;
	}
	//�I�u�W�F�N�g�̖����ɒǉ�
	m_list.push_back(b);
}

void Base::KillAll()
{
	std::list<Base*>ret;
	for (auto& b : m_list) {
		b->SetKill();
	}
}
