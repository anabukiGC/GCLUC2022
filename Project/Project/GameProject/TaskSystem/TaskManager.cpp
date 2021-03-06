#include "TaskManager.h"

TaskManager* TaskManager::mp_instance = nullptr;
TaskManager::TaskManager():mp_head(nullptr),mp_tail(nullptr), m_KillObuject(false)
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::Kill(Task* t)
{
}

Task* TaskManager::Remove(Task* t)
{
	Task* NextTask = t->mp_next;
	Task* PreviewTask = t->mp_prev;
	if (t->mp_next)
	{
		t->mp_next->mp_prev = PreviewTask;
	}
	else
	{
		mp_tail = t->mp_prev;
	}
	if (t->mp_prev)
	{
		t->mp_prev->mp_next = NextTask;
	}
	else
	{
		mp_head = t->mp_next;
	}
	t->mp_next = nullptr;
	t->mp_prev = nullptr;


	return NextTask;
}

void TaskManager::Add(Task* p)
{
	Task* t = mp_head;
	//t (次)の値がNULL以外
	while (t)
	{
		if (t->m_priority >= p->m_priority)
			break;
		t = t->mp_next;
	}

	if(!mp_head)
	mp_head = mp_tail = p;

	else
	{
		//末尾に追加
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

void TaskManager::UpdatePriority()
{
	Task* t = mp_head;
	while (t) 
	{
		if (t->m_priority == t->m_old_priority)
		{
			t = t->mp_next;
			continue;
		}
		Task* Nexttask = Remove(t);
		Add(t);
		t->m_old_priority = t->m_priority;
		t = Nexttask;
	}
}

void TaskManager::DrawAll()
{
	Task* t = mp_head;
	while (t) {
		t->Draw();
		t = t->mp_next;
	}
}

void TaskManager::KillCheckAll()
{
	Task* t = mp_head;
	while (t)
	{
		if (t->m_kill)
		{
			Task* NextTask = Remove(t);

			delete t;
			t = NextTask;
		}
		else
		{
			t = t->mp_next;
		}
	}
}

void TaskManager::SetKillAll()
{
	//全手のタスクへSetKill
	Task* t = mp_head;
	while (t) 
	{
		t->SetKill();
		t = t->mp_next;
	}
}

void TaskManager::CollisionAll()
{
	Task* t = mp_head;
	while (t)
	{
		Task* p = t->mp_next;
		while (p)
		{
			t->Collision(p);
			p->Collision(t);
			p = p->mp_next;
		}
		t = t->mp_next;
	}
}

Task* TaskManager::GetTask(int id) const
{
	Task* t = mp_head;
	while (t) 
	{
		if (t->m_id == id)
		{
			return t;
		}
		t = t->mp_next;
	}
	return nullptr;
}

std::list<Task*> TaskManager::GetTasks(int id) const
{
	std::list<Task*>ret;
	Task* t = mp_head;
	while (t)
	{
		if (t->m_id == id)
		{
			ret.push_back(t);
		}
		t = t->mp_next;
	}
	return ret;
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
