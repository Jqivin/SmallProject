#include "UserClass.h"
#include <string>
UserClass::UserClass()
{
	// ¹¹Ôìº¯Êý
}

UserClass::UserClass(const std::string& name)
	: username(name)
	, score(0)
{

}

int UserClass::GetScore()
{
	return score;
}

void UserClass::SetScore(int iscore)
{
	score = iscore;
}

std::string UserClass::GetUsername()
{
	return username;
} 

std::vector<int> UserClass::GetWrongQuestions()
{
	return wrongQuestions;
}
