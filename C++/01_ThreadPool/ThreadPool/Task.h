#pragma once
#include <memory>
#include <atomic>

typedef enum PriorityLevel
{
	PRIORITY_LOW = 0,	// �����ȼ�����
	PRIORITY_NORMAL,	// �����ȼ�����
	PRIORITY_HIGH		// �����ȼ�����
}PriorityLevel_e;

static std::atomic<int64_t> seqCounter(0);

class Task
{
public:
	Task(int priority = PRIORITY_NORMAL)
		: m_priority(priority)
		, m_iSequence(seqCounter++)
	{}
	virtual ~Task() {};

	virtual void run() = 0;

	int getPriority() { return m_priority; }

	// �������ȼ��ȽϺ���
	bool operator<(const Task& task)
	{
		if(m_priority != task.m_priority)
			return m_priority < task.m_priority;
		return m_iSequence > task.m_iSequence;
	}

private:
	int m_priority;		// �������ȼ�
 
	int64_t	m_iSequence; // �������
};


using TaskPtr = std::shared_ptr<Task>;

