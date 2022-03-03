#include "Base.h"

CVector2D Base::m_scroll(0, 0);
std::list<Base*> Base::m_list;

Base::Base(BaseType type)
	:m_type(type), m_pos(0,0,0),m_vec(0,0,0),m_jump(false),m_flip(false),m_rad(0),m_kill(false)
{
	
}

Base::~Base()
{
}

void Base::Update()
{
}

void Base::Draw()
{
}

void Base::Draw3D()
{
	CVector2D pos2D(m_pos.x - m_scroll.x - m_pos.z / 8 , m_pos.y - m_scroll.y + m_pos.z / 2 + GROUND);
	m_img.SetPos(pos2D);
	m_img.SetFlipH(m_flip);
	m_img.Draw();


	//�f�o�b�O�p�@��`�̕\��
	CRect rect = CRect(
		m_pos.x + m_rect.m_left,
		m_pos.y + m_rect.m_top,
		m_pos.x + m_rect.m_right,
		m_pos.y + m_rect.m_bottom);
	/*
	Utility::DrawQuad(
		CVector2D(rect.m_left, rect.m_top) - m_scroll,
		CVector2D(rect.m_width, rect.m_height),
		CVector4D(1, 0, 0, 0.5f));
	*/
}


void Base::Collision(Base* b)
{
}

void Base::UpdateAll()
{
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		//�`��
		(*it)->Update();
		//����
		it++;
	}
}

void Base::DrawAll()
{
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		//�`��
		(*it)->Draw();
		//����
		it++;
	}

}

void Base::CollisionAll()
{
	//�擪�̗v�f
	auto it1 = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it1 != last) {
		//it2��it1�̎��̗v�f
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			//�����蔻�茟��
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		//����
		it1++;
	}

}

void Base::CheckKillAll()
{
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		//�폜�t���OON
		if ((*it)->m_kill) {
			//���̂��폜
			delete (*it);
			//���X�g�����菜��
			//�X�V��̃C�e���[�^���󂯎��
			it = m_list.erase(it);
		} else {
			//����
			it++;
		}
	}
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
	//2�_�Ԃ̋���
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	//�~���m�̓����蔻��
	if (l < b1->m_rad + b2->m_rad) {
		return true;
	}
	return false;
}

void Base::Add(Base* b)
{
	m_list.push_back(b);
}

Base* Base::FindObject(BaseType type)
{
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		//�Ώۂ̃I�u�W�F�N�g���������
		if ((*it)->m_type == type) 
			//�������I�u�W�F�N�g�̕ԋp
			return (*it);
		//����
		it++;
	}

	return nullptr;
}

std::list<Base*> Base::FindObjects(BaseType type)
{
	std::list<Base*> ret;
	//�擪�̗v�f
	auto it = m_list.begin();
	//�����̗v�f
	auto last = m_list.end();
	//it�������łȂ����
	while (it != last) {
		//�Ώۂ̃I�u�W�F�N�g���������
		if ((*it)->m_type == type)
			//�������I�u�W�F�N�g�����X�g�ɒǉ�
			ret.push_back(*it);
		//����
		it++;
	}
	return ret;
}

