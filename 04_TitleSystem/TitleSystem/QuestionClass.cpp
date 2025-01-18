#include "QuestionClass.h"

QuestionClass::QuestionClass()
{
}

QuestionClass::QuestionClass(const std::string& q, const std::vector<std::string>& opts, int ans)
	: question(q)
	, options(opts)
	, correctAnswer(ans) 
{

}

std::string QuestionClass::GetQuestion()
{
	return question;
}

std::vector<std::string> QuestionClass::GetOptions()
{
	return options;
}

int QuestionClass::GetCorrectAnswer()
{
	return correctAnswer;
}
