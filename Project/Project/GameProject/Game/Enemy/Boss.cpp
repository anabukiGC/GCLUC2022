#include "Boss.h"
#include "Boss2.h"
#include"EnemyManager.h"
#include"Bullet.h"
#include"TaskManager.h"
#include "AttackObject.h"
const float Boss::speed = 3.0;//�ǂ��ł��g����悤��
Boss::Boss(const CVector3D& pos) :Base(eType_Boss, 1)
{

		m_img = COPY_RESOURCE("Boss1", CImage);
		m_max_hp = 1000;
		m_hp = m_max_hp;//�ύX�p
		m_shadow_size = CVector2D(512, 256);//�摜�T�C�Y�p
		m_pos = pos;
		m_b_hp = new BossHp(this);//�|�C���^�[�n���̂�this
		m_shadow = new Shadow(this,m_shadow_size);//�|�C���^�[�n���̂�this
		m_flip = false;
		m_debuff = true;
		m_on = false;
		m_attack_effect = false;
		m_img.ChangeAnimation(0);
		m_state = eIdle;
		m_img.SetCenter(128*2, 256*2);
		m_rect = RectBox(-128*2, 256*2, 128*2, 0, 32, -32);

}

int Boss::GetHp()
{
	return m_hp;
}

int Boss::GetMaxHp()
{
	return m_max_hp;
}

void Boss::StateIdle()
{
	m_img.ChangeAnimation(0);

	if (m_bound == false) {//�c�ړ�
		m_pos.z -= speed;
	}
	else if (m_bound == true) {
		m_pos.z += speed;
	}


	if (m_pos.z <= 0) {//���˂�����O�`GROUND�܂�
		m_bound = true;
	}
	else if (m_pos.z >= 500) {
		m_bound = false;
	}

}




void Boss::StateRun()
{
}

void Boss::StateAttack1()
{
	m_invin= true;
	m_img.ChangeAnimation(1, false);//�ߋ����U��

	if (m_img.GetIndex() >= 8) {//�ړ�
		new AttackObject(eType_BossAttack1,CVector3D (m_pos.x-500,m_pos.y,m_pos.z), m_rect);
	}
	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_invin = false;
		m_second=11;
	}

}

void Boss::StateAttack2()
{
	m_invin = true;
	m_img.ChangeAnimation(2, false);//�������U��


	if (m_img.CheckAnimationEnd()) {
		m_state = eIdle;
		m_invin = false;
		m_cnt = 0;
	}
}

void Boss::StateDamage()
{
	
	m_img.ChangeAnimation(3, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) {
		
		m_hp -= 200;
		m_state = eIdle;
	}
/*	if (m_img.CheckAnimationEnd() && m_hp <= 0) {
		m_state = eChange;
	}*/
	
}

void Boss::StateChange()
{
	m_invin = true;
	m_img.ChangeAnimation(4, false);


	if (m_img.CheckAnimationEnd()) {
		
		new Boss2(m_pos);
		SetKill();
		if (m_b_hp) {//�����������Ă���
			
			m_b_hp->SetKill();
			m_b_hp = NULL;//���������p
			
		}
	}
}


void Boss::Update()
{
	m_cnt++;
	m_second = m_cnt / 60;//�b���ɕϊ�
	//��Ԃɂ�镪�򐧌�
	switch (m_state) {
	case eIdle:
		StateIdle();
		break;
	case eRun:
		StateRun();
		break;
	case eAttack1:
		StateAttack1();
		break;
	case eAttack2:
		StateAttack2();
		break;
	case eDamage:
		StateDamage();
		break;
	case eChange:
		StateChange();
		break;
	}


	if (m_debuff == true && m_on == false) {//�f�o�t�A�C�R���\��
		m_b_debuff=new Debuff(CVector2D(this->m_pos.x,this->m_pos.y));
		m_on = true;
	}



	if (m_pos.y <= 0) {//���@�n�ʗp
		m_pos.y = 0;
		m_vec.y = 0;

	}

	





	if ( m_second==2) {//�b���ŏ�ԑJ��
		
		m_state = eAttack1;
	}
	if ( m_second==6) {//�b���ŏ�ԑJ��
		m_state = eAttack2;
	}


	if (m_hp <= 0) {
		m_state = eChange;

	}
	m_img.UpdateAnimation();
}

void Boss::Draw()
{
	if (m_b_hp) {//�����������Ă���NULL�΍��p

		m_b_hp->m_pos = CVector3D(m_pos.x-100,m_pos.y,m_pos.z);//�Q�[�W�Ɏ����̍��W�����Ă��钲���\

	}
	Base::Draw3D();
}

void Boss::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_NomalBullet:
		if (Bullet* bullet = dynamic_cast<Bullet*>(t))
		{
			if (CollisionRect(bullet, this))
			{
				if (m_invin == false) {
					m_state = eDamage;
				}else
					m_hp -= 200;
				
			}
		}
		break;
	}
}
