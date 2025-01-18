#pragma once
#include <map>
#include <vector>
#include "QuestionClass.h"
#include "UserClass.h"
class TestSystem 
{

public:
	/*
	* 添加问题
	* question 问题
	*/
	void addQuestion(const QuestionClass& question);
	
	/*
	* 添加用户
	* user 用户
	*/
	void addUser(UserClass& user);
	
	/*
	* 展示问题
	*/
	void showQuestion();

	/*
	* 修改问题
	*/
	void modifyQuestion(int index, const QuestionClass& newQuestion);


	/*
	* 开始测试
	*/
	void startTest();

	/*
	* 展示用户分数
	*/
	void showUserScore();

	/*
	* 展示菜单
	*/
	void showMenu();
	
	/*
	* 执行循环
	*/
	void run(); 

private:
	// 问题存储
	std::vector<QuestionClass> questionBank;
	// 用户存储
	std::map<std::string, UserClass> users;
};
