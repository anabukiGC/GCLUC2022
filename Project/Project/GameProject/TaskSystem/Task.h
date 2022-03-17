#pragma once

//��ނ̗�
enum  BaseType {
	eType_Field,
	eType_Player,
	eType_PlayerAttack1,
	eType_Enemy,
	eType_EnemyManager,
	eType_Boss,
	eType_Bullet,
	eType_Effect,
	eType_UI,
	eType_NomalBullet,
	eType_ChargeBullet,
	eType_NomalBullet2,
	eType_Scene,
};

//�D��x�̗�
enum
{
	ePriorityPlayer = 100,
	ePriorityEnemy = 100,
};

class Task
{
private:
	Task*	mp_next;				//���̃^�X�N
	Task*	mp_prev;				//�O�̃^�X�N
	int		m_id;					//�^�X�NID
	int		m_priority;				//�D��x
	bool	m_kill;					//�폜�t���O

	int m_old_priority;
public:

	Task(int id, int priority);
	virtual ~Task();
	virtual void Update();
	virtual void Draw();
	virtual void Kill();
	virtual void Collision(Task* t);

	void SetKill()							//�폜�t���OON 
	{
		m_kill = true;
	}
	void ChangePriority(int priority);		//�D��x�ύX

	int GetID() const						//�^�X�NID�擾 
	{
		return m_id;
	}

	//TaskManager�N���X���͂�private�����o�ɃA�N�Z�X�\
	friend class TaskManager;
};
