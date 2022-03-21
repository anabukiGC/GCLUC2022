#pragma once

//種類の列挙
enum  BaseType {
	eType_Field,
	eType_Player,
	eType_PlayerAttack1,
	eType_Enemy,
	eType_EnemyAttack1,
	eType_EnemyBullet,
	eType_EnemyManager,
	eType_Boss,
	eType_BossAttack1,
	eType_BossBullet1,
	eType_Boss_Meteo,
	eType_Bullet,
	eType_Effect,
	eType_UI,
	eType_NomalBullet,
	eType_ChargeBullet,
	eType_NomalBullet2,
	eType_ChargeBullet2,
	eType_Laser,
	eType_Scene,
	eType_PlayerEffect1,
	eType_PlayerEffect2,
	eType_PlayerEffect3,
};

//優先度の列挙
enum
{
	ePriorityPlayer = 100,
	ePriorityPlayerEffect = 100,
	ePriorityEnemy = 100,
};

class Task
{
private:
	Task*	mp_next;				//次のタスク
	Task*	mp_prev;				//前のタスク
	int		m_id;					//タスクID
	int		m_priority;				//優先度
	bool	m_kill;					//削除フラグ

	int m_old_priority;
public:

	Task(int id, int priority);
	virtual ~Task();
	virtual void Update();
	virtual void Draw();
	virtual void Kill();
	virtual void Collision(Task* t);

	void SetKill()							//削除フラグON 
	{
		m_kill = true;
	}
	void ChangePriority(int priority);		//優先度変更

	int GetID() const						//タスクID取得 
	{
		return m_id;
	}

	//TaskManagerクラスかはらprivateメンバにアクセス可能
	friend class TaskManager;
};
