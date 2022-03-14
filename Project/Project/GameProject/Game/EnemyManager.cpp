#include "EnemyManager.h"
#include"Enemy.h"
#include"Boss.h"
EnemyData _stage1[] = {//出現データをまとめる
	{CVector3D(1600,0,500),0,EnemyData::eBoss},//（座標）、時間（フレーム）
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
};
EnemyData _stage2[] = {//出現データをまとめる
	{CVector3D(1600,0,500),0,EnemyData::eEnemy1},//（座標）、時間（フレーム）
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
	{CVector3D(1600,0,500),30,EnemyData::eEnemy1},
};
EnemyData _stage3[] = {//出現データをまとめる
	{CVector3D(1600,0,500),0,EnemyData::eBoss},//（座標）、時間（フレーム）
	
};
EnemyWave wave_data[] = {
	{512,_stage1,sizeof(_stage1) / sizeof(_stage1[0])},
	{1200,_stage2,sizeof(_stage2) / sizeof(_stage2[0])},
	{3000,_stage3,sizeof(_stage3) / sizeof(_stage3[0])}
};
EnemyManager::EnemyManager()
	:Base(eType_EnemyManager,0), m_cnt(0)//初期化の別の例
{
	m_wave_idx = 0;
	m_cnt = 0;
	m_idx = 0;
	m_wave_size = sizeof(wave_data) / sizeof(wave_data[0]);//全体のウェーブの個数を計算
}

void EnemyManager::Update()
{
	if (m_wave_idx >= m_wave_size) return;//ウェーブ全体が終わったら終了
	EnemyWave* wave = &wave_data[m_wave_idx];//ウェーブの値の内容を入れる
	if (m_scroll.x > wave->pos_x) {//指定地点に来たら
		m_ivent = true;
		if (m_idx < wave->size) {//設定した1WAVEのデータを超えたら終了
			m_cnt++;
			EnemyData* data = &_stage1[m_idx];
			if (m_cnt >= data->cnt) {//出現位置をデータから引っ張ってくるdata->pos.x,
				switch (data->type)//出現管理
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

bool EnemyManager::isEnd()//まだ敵が出てくるかどうかの判定用
{
	if (m_idx >= m_wave_size)
	{//全部またはウェーブ終了出現したら
		Task* t = TaskManager::GetInstance()->GetTask(eType_Enemy);//敵がいるかどうか判別
		if(t==NULL)
		return true;
	}
		return false;

	
}

bool EnemyManager::GetWave()
{

	return m_ivent;
}
