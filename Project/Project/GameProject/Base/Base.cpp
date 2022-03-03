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


	//デバッグ用　矩形の表示
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
	//先頭の要素
	auto it = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it != last) {
		//描画
		(*it)->Update();
		//次へ
		it++;
	}
}

void Base::DrawAll()
{
	//先頭の要素
	auto it = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it != last) {
		//描画
		(*it)->Draw();
		//次へ
		it++;
	}

}

void Base::CollisionAll()
{
	//先頭の要素
	auto it1 = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it1 != last) {
		//it2はit1の次の要素
		auto it2 = it1;
		it2++;
		while (it2 != last) {
			//当たり判定検証
			(*it1)->Collision(*it2);
			(*it2)->Collision(*it1);
			it2++;
		}
		//次へ
		it1++;
	}

}

void Base::CheckKillAll()
{
	//先頭の要素
	auto it = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it != last) {
		//削除フラグON
		if ((*it)->m_kill) {
			//実体を削除
			delete (*it);
			//リストから取り除く
			//更新後のイテレータを受け取る
			it = m_list.erase(it);
		} else {
			//次へ
			it++;
		}
	}
}

bool Base::CollisionCircle(Base* b1, Base* b2)
{
	//2点間の距離
	CVector3D v = b1->m_pos - b2->m_pos;
	float l = v.Length();
	//円同士の当たり判定
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
	//先頭の要素
	auto it = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it != last) {
		//対象のオブジェクトが見つかれば
		if ((*it)->m_type == type) 
			//見つけたオブジェクトの返却
			return (*it);
		//次へ
		it++;
	}

	return nullptr;
}

std::list<Base*> Base::FindObjects(BaseType type)
{
	std::list<Base*> ret;
	//先頭の要素
	auto it = m_list.begin();
	//末尾の要素
	auto last = m_list.end();
	//itが末尾でなければ
	while (it != last) {
		//対象のオブジェクトが見つかれば
		if ((*it)->m_type == type)
			//見つけたオブジェクトをリストに追加
			ret.push_back(*it);
		//次へ
		it++;
	}
	return ret;
}

