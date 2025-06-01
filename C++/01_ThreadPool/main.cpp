
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
	cout << "���̵߳�id:" << theId << endl;

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

// ���ȼ�������
class PrioritizedTask {
public:
    PrioritizedTask(int p, const std::string& desc = "")
        : priority(p), description(desc),  m_iSequence(seqCounter++) {}

    // ִ������
    void operator()() const {
        std::cout << "ִ�����ȼ� " << priority << " ������: " << description << "\n";
    }

    // �Ƚ�����������ѣ�
    bool operator<(const PrioritizedTask& other) const {
        if (priority != other.priority)
            return priority < other.priority;
        else
            return m_iSequence > other.m_iSequence;
    }

private:
    int priority;
    std::string description;
    int64_t	m_iSequence; // �������
};

// ʹ������ָ���������
using TaskPtr = std::shared_ptr<PrioritizedTask>;

// �Զ���Ƚ���������shared_ptr�����ȼ��Ƚ�
struct TaskComparator {
    bool operator()(const TaskPtr& lhs, const TaskPtr& rhs) const {
        return *lhs < *rhs;  // ʹ��PrioritizedTask�ıȽ������
    }
};

int main() {
    // �������ȼ����У�ʹ���Զ���Ƚ���
    std::priority_queue<TaskPtr,
        std::vector<TaskPtr>,
        TaskComparator> task_queue;

    // ��Ӳ�ͬ���ȼ�������
    task_queue.push(std::make_shared<PrioritizedTask>(1, "1�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "2�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "3�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "4�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(1, "5�����ȼ�����"));
   task_queue.push(std::make_shared<PrioritizedTask>(3, "�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(5, "�����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(2, "�ε����ȼ�����"));
    task_queue.push(std::make_shared<PrioritizedTask>(4, "�θ����ȼ�����"));

    // ִ�����񣨰����ȼ��Ӹߵ��ͣ�
    std::cout << "=== ��ʼִ������ ===\n";
    while (!task_queue.empty()) {
        auto task = task_queue.top();
        (*task)();  // ִ������
        task_queue.pop();
    }
    std::cout << "=== ��������ִ����� ===\n";

    return 0;
}
*/