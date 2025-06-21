#pragma once

#include "ThreadPool.h"


ThreadPool::ThreadPool(int threadNums)
	:m_iThreadNums(threadNums)
{
}
ThreadPool::~ThreadPool()
{
	//���û��ֹͣ������ֹͣ
	Stop();
}

void ThreadPool::Stop()
{
	//ֻ�ܵ���һ��
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
	//�����߳���
	for (int i = 0; i < m_iThreadNums; i++)
	{
		m_threadGroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
	}
}
void ThreadPool::RunInThread()			//�̵߳��ض�����
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
	m_queue.Stop();					//��ͬ��������ֹͣ������Put,Takeֹͣ������
	m_bRunning = false;				//��Ϊfalse�����ڲ����߳�����ѭ�����˳�����RunINThread��
	for (auto thread : m_threadGroup)
	{
		if (thread)
		{
			thread->join(); 
		}
	}
	m_threadGroup.clear();
}