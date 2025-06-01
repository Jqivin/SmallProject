#include "MyTask.h"
#include <iostream>
#include <thread>

MyTask::MyTask(int id,int priority)
	: Task(priority)
	, id_(id)
{

}
MyTask::~MyTask()
{

}

void MyTask::run()
{
	auto theId = std::this_thread::get_id();
	if (id_ == 1)
	{
		std::cout << "hello";
	}
	std::cout << "task download m3u8_id is " << id_ << " xxx thread id is " << theId <<   std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}