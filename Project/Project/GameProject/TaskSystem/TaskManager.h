#pragma once

#include "Task.h"
#include <list>

class TaskManager
{
private:

	Task* mp_head;					//�V�擪�|�C���^
	Task* mp_tail;					//�����|�C���^
private:
	static TaskManager* mp_instance;			//���g�|�C���^
	void Kill(Task* t);							//�^�X�N�폜�֐�
public:
	TaskManager();
	~TaskManager();
	void Add(Task* p);							//���X�g�ǉ��֐�
	void UpdateAll();							//���X�g�X�V�֐�
	void DrawAll();								//���X�g�`��֐�
	void KillCheckAll();						//���X�g�폜�`�F�b�N�֐�
	void SetKillAll();							//���X�g�폜�֐�
	void CollisionAll();						//���X�g�����蔻�芮��
	Task* GetTask(int id) const;				//�^�X�N�擾�֐�
	std::list<Task*> GetTasks(int id) const;	//�^�X�N���X�g�擾�֐�
	static TaskManager* GetInstance();			//�C���X�^���X�����擾
	static void ClearInstance();				//�i�[����Ă�����̂��폜
};
