#pragma once
#include <functional>
#include <thread>
#include <mutex>
#include <list>
#include <memory>

#include "SyncQueue.h"
#include "Task.h"

class ThreadPool
{
public:
	ThreadPool(int threadNums = std::thread::hardware_concurrency());
	~ThreadPool();

	void Start();
	void Stop();

	void AddTask(const TaskPtr& task);

private:
	void RunInThread();
	void StopThreadGroup();
private:
	int											m_iThreadNums;		// 线程个数
	std::list<std::shared_ptr<std::thread>>		m_threadGroup;		// 线程组
	SyncQueue									m_queue;			// 同步队列
	std::atomic<bool>							m_bRunning;			// 是否停止的标志
	std::once_flag								m_flag;
};


