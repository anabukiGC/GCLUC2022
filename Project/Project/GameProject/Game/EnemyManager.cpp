#include "EnemyManager.h"
#include"Enemy.h"
EnemyData _stage1[] = {//出現データをまとめる
	{CVector3D(1600,0,500),0},//（座標）、時間（フレーム）
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),120},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
	{CVector3D(1600,0,500),60},
};
EnemyManager::EnemyManager()
	:Base(0,0), m_cnt(0)//初期化の別の例
{
	m_cnt = 0;
	m_idx = 0;
	m_size = sizeof(_stage1) / sizeof(_stage1[0]);//配列の端÷サイズの０番目で容量を計算
}

void EnemyManager::Update()
{
	if (m_idx < m_size) {//設定したデータを超えたら終了
		m_cnt++;
		EnemyData* data = &_stage1[m_idx];
		if (m_cnt >= data->cnt) {//出現位置をデータから引っ張ってくる
			new Enemy(CVector3D(data->pos), 1);
			m_cnt = 0;
			m_idx++;
		}
	}
}

void EnemyManager::Draw()
{
}

bool EnemyManager::isEnd()//まだ敵が出てくるかどうかの判定用
{
	if (m_idx >= m_size)//まだ残っているなら
		return true;
	else//全部出現したら
		return false;
}
