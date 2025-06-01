#include "SyncQueue.h"

SyncQueue::SyncQueue() 
	:m_bNeedStop(false) 
{
}

SyncQueue::~SyncQueue() 
{

}

void SyncQueue::Put(const TaskPtr& task)
{
	AddTask(task);
}

bool SyncQueue::Take(TaskPtr& task)	
{
	std::unique_lock<std::mutex> locker(m_mutex);
	while (!m_bNeedStop && !NotEmpty())
	{
		m_notEmptyCV.wait(locker);
	}
	if (m_bNeedStop)
		return false;
	task = m_queue.top();
	m_queue.pop();
	return true;
}

void SyncQueue::Stop()
{
	m_bNeedStop = true;
	m_notEmptyCV.notify_all();
}

bool SyncQueue::IsEmpty()
{
	std::unique_lock<std::mutex> locker(m_mutex);
	return m_queue.empty();
}

size_t SyncQueue::Size()
{
	std::lock_guard<std::mutex> locker(m_mutex);
	return m_queue.size();
}


bool SyncQueue::NotEmpty()
{
	// ��Ҫ��������������Ǳ�Add���õģ�Take���Ѿ�������
	bool res = m_queue.empty();
	if (res)
		std::cout << "ͬ������Ϊ�գ���Ҫ�ȴ����첽�̵߳�idΪ��" << std::this_thread::get_id() << std::endl;
	return !res;
}

void SyncQueue::AddTask(const TaskPtr& task)
{
	if (m_bNeedStop)   
	{
		return;
	}

	std::unique_lock<std::mutex> locker(m_mutex);
	m_queue.push(task);
	m_notEmptyCV.notify_one();
}