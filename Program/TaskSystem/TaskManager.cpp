#include "TaskManager.h"

TaskManager* TaskManager::mp_instance = nullptr;
TaskManager::TaskManager():mp_head(nullptr),mp_tail(nullptr)
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::Kill(Task* t)
{
}

void TaskManager::Add(Task* p)
{
}


void TaskManager::UpdateAll()
{
}

void TaskManager::DrawAll()
{
}

void TaskManager::KillCheckAll()
{
}

void TaskManager::SetKillAll()
{
}

Task* TaskManager::GetTask(int id) const
{
	return nullptr;
}

std::list<Task*> TaskManager::GetTasks(int id) const
{
	return std::list<Task*>();
}

TaskManager* TaskManager::GetInstance()
{
	if (!mp_instance) mp_instance = new TaskManager();
	return mp_instance;
}

void TaskManager::ClearInstance()
{
	if (!mp_instance) return;
	delete mp_instance;
	mp_instance = nullptr;
}
