#pragma once

class Task
{
private:
	Task*	mp_next;				//���̃^�X�N
	Task*	mp_prev;				//�O�̃^�X�N
	int		m_id;					//�^�X�NID
	int		m_priority;				//�D��x
	bool	m_kill;					//�폜�t���O

public:
	Task(int id, int priority);
	virtual ~Task();
	virtual void Update();
	virtual void Draw();

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
