#pragma once
#include <string>
#include <vector>
class QuestionClass
{
public:
	QuestionClass();
	QuestionClass(const std::string& q, const std::vector<std::string>& opts, int ans);

	std::string GetQuestion();

	std::vector<std::string> GetOptions();

	int GetCorrectAnswer();
private:
	// 问题
	std::string question;

	// 选项
	std::vector<std::string> options;

	// 答案
	int correctAnswer;
};

