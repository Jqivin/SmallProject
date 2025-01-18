#include "TestSystemClass.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <sstream>

void TestSystem::addQuestion(const QuestionClass& question)
{
	questionBank.push_back(question);
}

void TestSystem::addUser(UserClass& user)
{
	users[user.GetUsername()] = user;
}

void TestSystem::TestSystem::showQuestion()
{
	for (int i = 0; i < questionBank.size(); ++i)
	{
		QuestionClass ques = questionBank[i];
		std::cout << "**********题目" << i + 1 << "**********" << std::endl;
		std::cout << "题目内容：" << ques.GetQuestion() << std::endl;
		std::cout << "题目选项：";
		for (int j = 0; j < ques.GetOptions().size(); ++j)
		{
			std::cout << j + 1 << ". " << ques.GetOptions()[j] << "    ";
		}
		std::cout << std::endl;
		std::cout << "题目答案：" << ques.GetCorrectAnswer() << std::endl;
		std::cout << std::endl;
	}

}

void TestSystem::modifyQuestion(int index, const QuestionClass& newQuestion)
{
	if (index >= 0 && index < questionBank.size()) {
		questionBank[index] = newQuestion;
	}
	else {
		std::cout << "无效的题目索引" << std::endl;
	}
}

void TestSystem::startTest()
{
	std::string username;
	std::cout << "共5题，每题20分: ";
	std::cout << "请输入用户名: ";
	std::cin >> username;

	if (users.find(username) == users.end()) {
		std::cout << "用户不存在，已注册" << std::endl;
		UserClass user;
		user.GetUsername() = username;
		addUser(user);

	}

	UserClass& user = users[username];
	user.SetScore(0);
	user.GetWrongQuestions().clear();

	std::srand(std::time(0));
	std::vector<int> usedIndices;

	for (int i = 0; i < 5; ++i) {
		int index;
		//do
		{
			index = std::rand() % questionBank.size();
		} //while (std::find(usedIndices.begin(), usedIndices.end(), index) != usedIndices.end());

		usedIndices.push_back(index);
		QuestionClass& q = questionBank[index];
		std::cout << "问题 " << i + 1 << ": " << q.GetQuestion() << std::endl;
		for (int j = 0; j < q.GetOptions().size(); ++j)
		{
			std::cout << j + 1 << ". " << q.GetOptions()[j] << std::endl;
		}

		int answer;
		std::cout << "请输入答案 (1-" << q.GetOptions().size() << "): ";
		std::cin >> answer;

		if (answer == q.GetCorrectAnswer())
		{
			int iScore = user.GetScore();
			user.SetScore(iScore += 20);
		}
		else
		{
			user.GetWrongQuestions().push_back(index);
		}
	}

	std::cout << "测试结束，你的得分是: " << user.GetScore() << std::endl;
}

void TestSystem::showUserScore() {
	std::string username;
	std::cout << "请输入用户名: ";
	std::cin >> username;

	if (users.find(username) == users.end()) {
		std::cout << "用户不存在，请先注册" << std::endl;
		return;
	}

	UserClass& user = users[username];
	std::cout << "用户: " << user.GetUsername() << " 得分: " << user.GetScore() << std::endl;
	if (!user.GetWrongQuestions().empty()) {
		std::cout << "错题: " << std::endl;
		for (int index : user.GetWrongQuestions()) {
			std::cout << questionBank[index].GetQuestion() << std::endl;
		}
	}
}

void TestSystem::showMenu()
{
	std::cout << "****************************************" << std::endl;
	std::cout << "              1. 录入题目                " << std::endl;
	std::cout << "              2. 修改题目                " << std::endl;
	std::cout << "              3. 查看题目                " << std::endl;
	std::cout << "              4. 开始测试                " << std::endl;
	std::cout << "              5. 查询得分                " << std::endl;
	std::cout << "              6. 退出                    " << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "请选择:";
}

void TestSystem::run() {
	int choice;
	while (true)
	{
		showMenu();
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string q;
			std::vector<std::string> opts;
			int ans;

			std::cout << "请输入问题: ";
			std::getline(std::cin, q);
			std::getline(std::cin, q);

			std::cout << "请输入选项 (用空格分隔): ";
			std::string optStr;
			std::getline(std::cin, optStr);
			std::istringstream iss(optStr);
			std::string opt;
			while (iss >> opt) {
				opts.push_back(opt);
			}

			std::cout << "请输入正确答案 (1-" << opts.size() << "): ";
			std::cin >> ans;

			addQuestion(QuestionClass(q, opts, ans));
			break;
		}
		case 2:
		{
			std::string q;
			std::vector<std::string> opts;
			int ans, index;

			std::cout << "请输入要修改的题目索引: ";
			std::cin >> index;

			std::cout << "请输入新的问题: ";
			std::getline(std::cin, q);
			std::getline(std::cin, q);

			std::cout << "请输入新的选项 (用空格分隔): ";
			std::string optStr;
			std::getline(std::cin, optStr);
			std::istringstream iss(optStr);
			std::string opt;
			while (iss >> opt) {
				opts.push_back(opt);
			}

			std::cout << "请输入新的正确答案 (1-" << opts.size() << "): ";
			std::cin >> ans;

			modifyQuestion(index, QuestionClass(q, opts, ans));
			break;
		}
		case 3:
			showQuestion();
			break;
		case 4:
			startTest();
			break;
		case 5:
			showUserScore();
			break;
		case 6:
			return;

		default:
			std::cout << "无效的选择" << std::endl;
		}
	}
}