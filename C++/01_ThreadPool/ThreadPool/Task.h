#pragma once
#include <memory>
#include <atomic>

typedef enum PriorityLevel
{
	PRIORITY_LOW = 0,	// 低优先级任务
	PRIORITY_NORMAL,	// 中优先级任务
	PRIORITY_HIGH		// 高优先级任务
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

	// 定义优先级比较函数
	bool operator<(const Task& task)
	{
		if(m_priority != task.m_priority)
			return m_priority < task.m_priority;
		return m_iSequence > task.m_iSequence;
	}

private:
	int m_priority;		// 任务优先级
 
	int64_t	m_iSequence; // 任务序号
};


using TaskPtr = std::shared_ptr<Task>;

