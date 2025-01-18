#include "UpdateDialog.h"

UpdateDialog::UpdateDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnUpdate, &QPushButton::clicked, this, &UpdateDialog::accept);
}

UpdateDialog::~UpdateDialog()
{}


QString UpdateDialog::GetSqlString()
{
	int ID = ui.lineEditID->text().toInt();
	QString strName = ui.lineEditName->text();
	QString strClass = ui.lineEditClass->text();
	QString strTerm = ui.lineEditTerm->text();

	double gradeChinese = ui.spinBoxChinese->value();
	double gradeMath = ui.spinBoxMath->value();
	double gradeEnglish = ui.spinBoxEnglish->value();
	double gradeComputer = ui.spinBoxComputer->value();
	QString strCondi;
	bool bAddSet = false;
	if (ui.rbName->isChecked())
	{
		
		if (!bAddSet)
		{
			strCondi += QString("SET name = '%1' ").arg(strName);
		}
		else
		{
			strCondi += QString(", name = '%1' ").arg(strName);
		}
		bAddSet = true;
	}
	if (ui.rbClass->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET class = '%1' ").arg(strClass);
		}
		else
		{
			strCondi += QString(", class = '%1' ").arg(strClass);
		}
		bAddSet = true;
	}
	if (ui.rbTerm->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET term = '%1' ").arg(strTerm);
		}
		else
		{
			strCondi += QString(", term = '%1' ").arg(strTerm);
		}
		bAddSet = true;
	}
	if (ui.rbChinese->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET chinese = %1 ").arg(gradeChinese);
		}
		else
		{
			strCondi += QString(", chinese = %1 ").arg(gradeChinese);
		}
		bAddSet = true;
	}
	if (ui.rbMath->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET math = %1 ").arg(gradeMath);
		}
		else
		{
			strCondi += QString(", math = %1 ").arg(gradeMath);
		}
		bAddSet = true;
	}
	if (ui.rbEnglish->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET english = %1 ").arg(gradeEnglish);
		}
		else
		{
			strCondi += QString(", english = %1 ").arg(gradeEnglish);
		}
		bAddSet = true;
	}
	if (ui.rbComputer->isChecked())
	{
		if (!bAddSet)
		{
			strCondi += QString("SET conputer = %1 ").arg(gradeComputer);
		}
		else
		{
			strCondi += QString(", conputer = %1 ").arg(gradeComputer);
		}
		bAddSet = true;
	}



	QString strSql = QString("UPDATE student_grade %1 where id = %2").arg(strCondi).arg(ID);

	return strSql;
}