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
	// ����
	std::string question;

	// ѡ��
	std::vector<std::string> options;

	// ��
	int correctAnswer;
};

