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
	int											m_iThreadNums;		// �̸߳���
	std::list<std::shared_ptr<std::thread>>		m_threadGroup;		// �߳���
	SyncQueue									m_queue;			// ͬ������
	std::atomic<bool>							m_bRunning;			// �Ƿ�ֹͣ�ı�־
	std::once_flag								m_flag;
};


