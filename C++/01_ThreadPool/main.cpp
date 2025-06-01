
#include <iostream>
#include "SyncQueue.h"
#include "ThreadPool.h"
#include "MyTask.h"
#include "Task.h"


using namespace std;


int main()
{
	ThreadPool pool(2);

	auto theId = this_thread::get_id();
	cout << "主线程的id:" << theId << endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "main add " << i << std::endl;
		
		if (i % 2 == 0)
		{
            TaskPtr task(new MyTask(i, PriorityLevel_e::PRIORITY_HIGH));
			pool.AddTask(task);
		}
		else
		{
            TaskPtr task(new MyTask(i, PriorityLevel_e::PRIORITY_NORMAL));
			pool.AddTask(task);
		}
	}

    pool.Start();

	std::this_thread::sleep_for(std::chrono::seconds(25));

	return 0;
}


/*

#include <iostream>
#include <queue>
#include <memory>
#include <vector>

static std::atomic<int64_t> seqCounter(0);

// 优先级任务类
class PrioritizedTask {
public:
    PrioritizedTask(int p, const std::string& desc = "")
        : priority(p), description(desc),  m_iSequence(seqCounter++) {}

    // 执行任务
    void operator()() const {
        std::cout << "执行优先级 " << priority << " 的任务: " << description << "\n";
    }

    // 比较运算符（最大堆）
    bool operator<(const PrioritizedTask& other) const {
        if (priority != other.priority)
            return priority < other.priority;
        else
            return m_iSequence > other.m_iSequence;
    }

private:
    int priority;
    std::string description;
    int64_t	m_iSequence; // 任务序号
};

// 使用智能指针管理任务
using TaskPtr = std::shared_ptr<PrioritizedTask>;

// 自定义比较器，用于shared_ptr的优先级比较
struct TaskComparator {
    bool operator()(const TaskPtr& lhs, const TaskPtr& rhs) const {
        return *lhs < *rhs;  // 使用PrioritizedTask的比较运算符
    }
};

int main() {
    // 创建优先级队列，使用自定义比较器
    std::priority_queue<TaskPtr,
        std::vector<TaskPtr>,
        TaskComparator> task_queue;

    // 添加不同优先级的任务
    task_queue.push(std::make_shared<PrioritizedTask>(1, "1低优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "2低优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "3低优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "4低优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "5低优先级任务"));
   task_queue.push(std::make_shared<PrioritizedTask>(3, "中优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(5, "高优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(2, "次低优先级任务"));
    task_queue.push(std::make_shared<PrioritizedTask>(4, "次高优先级任务"));

    // 执行任务（按优先级从高到低）
    std::cout << "=== 开始执行任务 ===\n";
    while (!task_queue.empty()) {
        auto task = task_queue.top();
        (*task)();  // 执行任务
        task_queue.pop();
    }
    std::cout << "=== 所有任务执行完毕 ===\n";

    return 0;
}
*/