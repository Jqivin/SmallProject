#pragma once
#include <map>
#include <vector>
#include "QuestionClass.h"
#include "UserClass.h"
class TestSystem 
{

public:
	/*
	* �������
	* question ����
	*/
	void addQuestion(const QuestionClass& question);
	
	/*
	* ����û�
	* user �û�
	*/
	void addUser(UserClass& user);
	
	/*
	* չʾ����
	*/
	void showQuestion();

	/*
	* �޸�����
	*/
	void modifyQuestion(int index, const QuestionClass& newQuestion);


	/*
	* ��ʼ����
	*/
	void startTest();

	/*
	* չʾ�û�����
	*/
	void showUserScore();

	/*
	* չʾ�˵�
	*/
	void showMenu();
	
	/*
	* ִ��ѭ��
	*/
	void run(); 

private:
	// ����洢
	std::vector<QuestionClass> questionBank;
	// �û��洢
	std::map<std::string, UserClass> users;
};
