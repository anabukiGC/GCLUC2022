#include <stdio.h>
#include "Task.h"
#include "TaskManager.h"

Task::Task(int id, int priority):m_id(id),m_priority(priority)
{
	//�����ǉ�
	TaskManager::GetInstance()->Add(this);
}

Task::~Task()
{
}

void Task::Update()
{
	printf("TaskUpdate[%d]\n", m_priority);
}

void Task::Draw()
{
}

void Task::ChangePriority(int priority)
{
	m_priority = priority;
	//���X�g���̕��ёւ����K�v

}
