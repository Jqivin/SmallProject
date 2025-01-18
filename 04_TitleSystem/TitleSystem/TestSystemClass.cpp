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
		std::cout << "**********��Ŀ" << i + 1 << "**********" << std::endl;
		std::cout << "��Ŀ���ݣ�" << ques.GetQuestion() << std::endl;
		std::cout << "��Ŀѡ�";
		for (int j = 0; j < ques.GetOptions().size(); ++j)
		{
			std::cout << j + 1 << ". " << ques.GetOptions()[j] << "    ";
		}
		std::cout << std::endl;
		std::cout << "��Ŀ�𰸣�" << ques.GetCorrectAnswer() << std::endl;
		std::cout << std::endl;
	}

}

void TestSystem::modifyQuestion(int index, const QuestionClass& newQuestion)
{
	if (index >= 0 && index < questionBank.size()) {
		questionBank[index] = newQuestion;
	}
	else {
		std::cout << "��Ч����Ŀ����" << std::endl;
	}
}

void TestSystem::startTest()
{
	std::string username;
	std::cout << "��5�⣬ÿ��20��: ";
	std::cout << "�������û���: ";
	std::cin >> username;

	if (users.find(username) == users.end()) {
		std::cout << "�û������ڣ���ע��" << std::endl;
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
		std::cout << "���� " << i + 1 << ": " << q.GetQuestion() << std::endl;
		for (int j = 0; j < q.GetOptions().size(); ++j)
		{
			std::cout << j + 1 << ". " << q.GetOptions()[j] << std::endl;
		}

		int answer;
		std::cout << "������� (1-" << q.GetOptions().size() << "): ";
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

	std::cout << "���Խ�������ĵ÷���: " << user.GetScore() << std::endl;
}

void TestSystem::showUserScore() {
	std::string username;
	std::cout << "�������û���: ";
	std::cin >> username;

	if (users.find(username) == users.end()) {
		std::cout << "�û������ڣ�����ע��" << std::endl;
		return;
	}

	UserClass& user = users[username];
	std::cout << "�û�: " << user.GetUsername() << " �÷�: " << user.GetScore() << std::endl;
	if (!user.GetWrongQuestions().empty()) {
		std::cout << "����: " << std::endl;
		for (int index : user.GetWrongQuestions()) {
			std::cout << questionBank[index].GetQuestion() << std::endl;
		}
	}
}

void TestSystem::showMenu()
{
	std::cout << "****************************************" << std::endl;
	std::cout << "              1. ¼����Ŀ                " << std::endl;
	std::cout << "              2. �޸���Ŀ                " << std::endl;
	std::cout << "              3. �鿴��Ŀ                " << std::endl;
	std::cout << "              4. ��ʼ����                " << std::endl;
	std::cout << "              5. ��ѯ�÷�                " << std::endl;
	std::cout << "              6. �˳�                    " << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "��ѡ��:";
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

			std::cout << "����������: ";
			std::getline(std::cin, q);
			std::getline(std::cin, q);

			std::cout << "������ѡ�� (�ÿո�ָ�): ";
			std::string optStr;
			std::getline(std::cin, optStr);
			std::istringstream iss(optStr);
			std::string opt;
			while (iss >> opt) {
				opts.push_back(opt);
			}

			std::cout << "��������ȷ�� (1-" << opts.size() << "): ";
			std::cin >> ans;

			addQuestion(QuestionClass(q, opts, ans));
			break;
		}
		case 2:
		{
			std::string q;
			std::vector<std::string> opts;
			int ans, index;

			std::cout << "������Ҫ�޸ĵ���Ŀ����: ";
			std::cin >> index;

			std::cout << "�������µ�����: ";
			std::getline(std::cin, q);
			std::getline(std::cin, q);

			std::cout << "�������µ�ѡ�� (�ÿո�ָ�): ";
			std::string optStr;
			std::getline(std::cin, optStr);
			std::istringstream iss(optStr);
			std::string opt;
			while (iss >> opt) {
				opts.push_back(opt);
			}

			std::cout << "�������µ���ȷ�� (1-" << opts.size() << "): ";
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
			std::cout << "��Ч��ѡ��" << std::endl;
		}
	}
}