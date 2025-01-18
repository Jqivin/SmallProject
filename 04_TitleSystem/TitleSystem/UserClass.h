#pragma once
#include <string>
#include <vector>


class UserClass {
private:
	// �û���
	std::string username;

	//����
	int score;

	// ��������
	std::vector<int> wrongQuestions;


public:

	UserClass();
	UserClass(const std::string& name);

	int GetScore();
	void SetScore(int iscore);

	std::string GetUsername();

	std::vector<int> GetWrongQuestions();
};

