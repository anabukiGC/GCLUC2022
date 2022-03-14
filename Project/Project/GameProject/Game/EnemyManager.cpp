#include "EnemyManager.h"
#include"Enemy.h"
#include"Boss.h"
EnemyData _stage1[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,500),0,EnemyData::eBoss},//�i���W�j�A���ԁi�t���[���j
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
};
EnemyData _stage2[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,500),0,EnemyData::eEnemy1},//�i���W�j�A���ԁi�t���[���j
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
};
EnemyData _stage3[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,500),0,EnemyData::eBoss},//�i���W�j�A���ԁi�t���[���j
	
};
EnemyWave wave_data[] = {
	{512,_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
	{1200,_stage2,sizeof(_stage2) / sizeof(_stage2[0])},
	{3000,_stage3,sizeof(_stage3) / sizeof(_stage3[0])}
};
EnemyManager::EnemyManager()
	:Base(eType_EnemyManager,0), m_cnt(0)//�������̕ʂ̗�
{
	m_wave_idx = 0;
	m_cnt = 0;
	m_idx = 0;
	m_wave_size = sizeof(wave_data) / sizeof(wave_data[0]);//�S�̂̃E�F�[�u�̌����v�Z
}

void EnemyManager::Update()
{
	if (m_wave_idx >= m_wave_size) return;//�E�F�[�u�S�̂��I�������I��
	EnemyWave* wave = &wave_data[m_wave_idx];//�E�F�[�u�̒l�̓��e������
	if (m_scroll.x > wave->pos_x) {//�w��n�_�ɗ�����
		m_ivent = true;
		if (m_idx < wave->size) {//�ݒ肵��1WAVE�̃f�[�^�𒴂�����I��
			m_cnt++;
			EnemyData* data = &_stage1[m_idx];
			if (m_cnt >= data->cnt) {//�o���ʒu���f�[�^������������Ă���data->pos.x,
				switch (data->type)//�o���Ǘ�
				{
				case EnemyData::eEnemy1:
				case EnemyData::eEnemy2:
					new Enemy(CVector3D(wave->pos_x + data->pos.x, data->pos.y, data->pos.z), data->type);
					break;
				case EnemyData::eBoss:
					new Boss(CVector3D(wave->pos_x + data->pos.x, data->pos.y, data->pos.z), data->type);
					break;
				}
				m_cnt = 0;
				m_idx++;
			}
		}
		else {
			if (isEnd()) {
				m_wave_idx++;
				m_idx = 0;
			}
		}
	}
	
}

void EnemyManager::Draw()
{
}

bool EnemyManager::isEnd()//�܂��G���o�Ă��邩�ǂ����̔���p
{
	if (m_idx >= m_wave_size)
	{//�S���܂��̓E�F�[�u�I���o��������
		Task* t = TaskManager::GetInstance()->GetTask(eType_Enemy);//�G�����邩�ǂ�������
		if(t==NULL)
		return true;
	}
		return false;

	
}

bool EnemyManager::GetWave()
{

	return m_ivent;
}
