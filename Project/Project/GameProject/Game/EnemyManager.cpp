#include "EnemyManager.h"
#include"Enemy.h"
EnemyData _stage1[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,500),0},//�i���W�j�A���ԁi�t���[���j
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),120},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
};
EnemyManager::EnemyManager()
	:Base(0,0), m_cnt(0)//�������̕ʂ̗�
{
	m_cnt = 0;
	m_idx = 0;
	m_size = sizeof(_stage1) / sizeof(_stage1[0]);//�z��̒[���T�C�Y�̂O�Ԗڂŗe�ʂ��v�Z
}

void EnemyManager::Update()
{
	if (m_idx < m_size) {//�ݒ肵���f�[�^�𒴂�����I��
		m_cnt++;
		EnemyData* data = &_stage1[m_idx];
		if (m_cnt >= data->cnt) {//�o���ʒu���f�[�^������������Ă���
			new Enemy(CVector3D(data->pos), 1);
			m_cnt = 0;
			m_idx++;
		}
	}
}

void EnemyManager::Draw()
{
}

bool EnemyManager::isEnd()//�܂��G���o�Ă��邩�ǂ����̔���p
{
	if (m_idx >= m_size)//�܂��c���Ă���Ȃ�
		return true;
	else//�S���o��������
		return false;
}
