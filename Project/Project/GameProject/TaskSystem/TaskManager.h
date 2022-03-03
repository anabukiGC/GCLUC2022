#pragma once

#include "Task.h"
#include <list>

class TaskManager
{
private:

	Task* mp_head;					//新先頭ポインタ
	Task* mp_tail;					//末尾ポインタ
private:
	static TaskManager* mp_instance;			//自身ポインタ
	void Kill(Task* t);							//タスク削除関数
public:
	TaskManager();
	~TaskManager();
	void Add(Task* p);							//リスト追加関数
	void UpdateAll();							//リスト更新関数
	void DrawAll();								//リスト描画関数
	void KillCheckAll();						//リスト削除チェック関数
	void SetKillAll();							//リスト削除関数
	void CollisionAll();						//リスト当たり判定完成
	Task* GetTask(int id) const;				//タスク取得関数
	std::list<Task*> GetTasks(int id) const;	//タスクリスト取得関数
	static TaskManager* GetInstance();			//インスタンス生成取得
	static void ClearInstance();				//格納されているものを削除
};
