#pragma once
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <memory>
#include <vector>
#include "Task.h"

// 自定义比较器，用于shared_ptr的优先级比较
class TaskPtrComparator
{
public:
	bool operator()(const TaskPtr& lhs, const TaskPtr& rhs)
	{
		return *lhs < *rhs;
	}
};

class SyncQueue
{
public:
	SyncQueue();
	~SyncQueue();

	void Put(const TaskPtr& t);

	bool Take(TaskPtr& t);

	void Stop();

	bool IsEmpty();

	size_t Size();

private:
	bool NotEmpty();

	void AddTask(const TaskPtr& task);

	std::priority_queue<TaskPtr,std::vector<TaskPtr>, TaskPtrComparator>	m_queue;
	std::mutex m_mutex;
	std::condition_variable m_notEmptyCV;
	std::atomic<bool> m_bNeedStop;
};


