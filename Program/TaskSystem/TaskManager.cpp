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
	Task* t = mp_head;
	//t (Ÿ)‚Ì’l‚ªNULLˆÈŠO
	while (t)
	{
		if (t->m_priority > p->m_priority)
			break;
		t = t->mp_next;
	}

	if(!mp_head)
	mp_head = mp_tail = p;

	else
	{
		//––”ö‚É’Ç‰Á
		if (!t)
		{
			mp_tail->mp_next = p;
			p->mp_prev = mp_tail;
			mp_tail = p;
		}
		else if (!t->mp_prev)
		{
			p->mp_next = t;
			t->mp_prev = p;
			mp_head = p;
		}
		else
		{
			t->mp_prev->mp_next = p;
			p->mp_prev = t->mp_prev;
			p->mp_next = t;
			t->mp_prev = p;
		}
	}
}


void TaskManager::UpdateAll()
{
	Task* t = mp_head;
	while (t) {
		t->Update();
		t = t->mp_next;
	}
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
