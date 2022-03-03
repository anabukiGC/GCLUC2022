#include <stdio.h>
#include "Task.h"
#include "TaskManager.h"

Task::Task(int id, int priority):m_id(id),m_priority(priority)
{
	//自動追加
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
	//リスト内の並び替えが必要

}
