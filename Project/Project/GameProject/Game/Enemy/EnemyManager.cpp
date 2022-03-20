#include "EnemyManager.h"
#include"Enemy.h"
#include"Boss.h"
EnemyData _stage1[] = {//�o���f�[�^���܂Ƃ߂�
	/*{CVector3D(1600,0,500),0,EnemyData::eEnemy1,true},//�i���W�j�A���ԁi�t���[���j,����
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy2,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy2,true},
	{CVector3D(0,0,500),30,EnemyData::eEnemy1,false},
	{CVector3D(0,0,500),30,EnemyData::eEnemy1,false},*/
	{CVector3D(0,0,500),30,EnemyData::eEnemy3,false},
};
EnemyData _stage2[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,500),0,EnemyData::eEnemy1,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1,true},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1,true},
};
EnemyData _stage3[] = {//�o���f�[�^���܂Ƃ߂�
	{CVector3D(1600,0,250),0,EnemyData::eBoss},//�i���W�j�A���ԁi�t���[���j
	
};
EnemyWave wave_data[] = {
	{512,_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
	{1200,_stage2,sizeof(_stage2) / sizeof(_stage2[0])},
	{3000,_stage3,sizeof(_stage3) / sizeof(_stage3[0])}
};
EnemyManager::EnemyManager()
	:Base(eType_EnemyManager,1), m_cnt(0)//�������̕ʂ̗�
{
	m_wave_idx = 0;
	m_cnt = 0;
	m_idx = 0;
	m_wave_size = sizeof(wave_data) / sizeof(wave_data[0]);//�S�̂̃E�F�[�u�̌����v�Z
	m_img = COPY_RESOURCE("NomalBullet1", CImage);
	m_img.SetSize(500, 500);
}

void EnemyManager::Update()
{
	if (m_wave_idx >= m_wave_size) return;//�E�F�[�u�S�̂��I�������I��
	EnemyWave* wave = &wave_data[m_wave_idx];//�E�F�[�u�̒l�̓��e������
	if (m_scroll.x > wave->pos_x) {//�w��n�_�ɗ�����
		m_ivent = true;//�X�N���[���Œ�p
		if (m_idx < wave->size) {//�ݒ肵��1WAVE�̃f�[�^�𒴂�����I��
			m_cnt++;
			
			EnemyData* data = &wave->data[m_idx];
			if (m_cnt >= data->cnt) {//�o���ʒu���f�[�^������������Ă���data->pos.x,
				switch (data->type)//�o���Ǘ�
				{
				case EnemyData::eEnemy1:
				case EnemyData::eEnemy2:
				case EnemyData::eEnemy3:
					new Enemy(CVector3D(wave->pos_x + data->pos.x, data->pos.y, data->pos.z), data->type,data->flip);
					break;
				case EnemyData::eBoss:
 					new Boss(CVector3D(wave->pos_x + data->pos.x, data->pos.y, data->pos.z));
					break;
				}
				m_cnt = 0;
				m_idx++;
			}
		}
		else {
			if (isEnd()) {
				GetWave();
				m_ivent = false;
				m_wave_idx++;
				m_idx = 0;
			}
		}
	}
	
}

void EnemyManager::Draw()
{
	if (!GetWave()) {
		if (m_wave_idx >= m_wave_size) return;//�E�F�[�u�S�̂��I�������I��
		EnemyWave* wave = &wave_data[m_wave_idx];//�E�F�[�u�̒l�̓��e������
		m_pos.x = wave->pos_x;//�w��n�_�̒l������m_pos���Ŕ̏ꏊ
		Draw3D();
	}
}

bool EnemyManager::isEnd()//�܂��G���o�Ă��邩�ǂ����̔���p
{
	if (m_idx >= m_wave_size)
	{//�S���܂��̓E�F�[�u�I���o��������
		Task* t = TaskManager::GetInstance()->GetTask(eType_Enemy);//�G�����邩�ǂ�������
		Task* t2 = TaskManager::GetInstance()->GetTask(eType_Boss);//�G�����邩�ǂ�������
		if(t==NULL&&t2==NULL)//�G�����Ȃ��Ȃ�
		return true;


	}
		return false;

	
}

bool EnemyManager::GetWave()
{

	return m_ivent;
}
