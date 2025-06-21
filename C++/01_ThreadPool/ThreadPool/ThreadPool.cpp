#pragma once

#include "ThreadPool.h"


ThreadPool::ThreadPool(int threadNums)
	:m_iThreadNums(threadNums)
{
}
ThreadPool::~ThreadPool()
{
	//如果没有停止，调用停止
	Stop();
}

void ThreadPool::Stop()
{
	//只能调动一次
	std::call_once(m_flag, [this] {
		StopThreadGroup(); 
	});	
}

void ThreadPool::AddTask(const TaskPtr& task)
{
	m_queue.Put(task);
}

void ThreadPool::Start()
{
	m_bRunning = true;
	//创建线程组
	for (int i = 0; i < m_iThreadNums; i++)
	{
		m_threadGroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
	}
}
void ThreadPool::RunInThread()			//线程的特定函数
{
	while (m_bRunning)
	{
		TaskPtr task;
		m_queue.Take(task);
		if (!m_bRunning)
		{
			return;
		}
		task->run();
	}
}
void ThreadPool::StopThreadGroup()
{
	m_queue.Stop();					//让同步队列中停止工作（Put,Take停止工作）
	m_bRunning = false;				//置为false。让内部的线程跳出循环并退出，（RunINThread）
	for (auto thread : m_threadGroup)
	{
		if (thread)
		{
			thread->join(); 
		}
	}
	m_threadGroup.clear();
}