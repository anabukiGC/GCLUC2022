#pragma once

class Task
{
private:
	Task*	mp_next;				//次のタスク
	Task*	mp_prev;				//前のタスク
	int		m_id;					//タスクID
	int		m_priority;				//優先度
	bool	m_kill;					//削除フラグ

public:
	Task(int id, int priority);
	virtual ~Task();
	virtual void Update();
	virtual void Draw();

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
