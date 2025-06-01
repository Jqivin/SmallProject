#pragma once
#include "Task.h"
class MyTask : public Task
{
public:
	MyTask(int id, int priority = PRIORITY_NORMAL);
	virtual ~MyTask();

	virtual void run();

private:
	int id_;
};

