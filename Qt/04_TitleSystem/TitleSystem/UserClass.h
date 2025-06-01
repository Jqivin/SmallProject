#pragma once
#include <string>
#include <vector>


class UserClass {
private:
	// 用户名
	std::string username;

	//分数
	int score;

	// 错误问题
	std::vector<int> wrongQuestions;


public:

	UserClass();
	UserClass(const std::string& name);

	int GetScore();
	void SetScore(int iscore);

	std::string GetUsername();

	std::vector<int> GetWrongQuestions();
};

