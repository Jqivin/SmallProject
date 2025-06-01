#include "AddInfoDialog.h"

AddInfoDialog::AddInfoDialog(QWidget *parent)
	: QDialog(parent)
	, etype(AddInfo_Type)
{
	ui.setupUi(this);

	connect(ui.btnAdd, &QPushButton::clicked, this, &AddInfoDialog::accept);
}

AddInfoDialog::~AddInfoDialog()
{}

void AddInfoDialog::ClearAllInfo()
{
	ui.lineEditID->setText("");
	ui.lineEditName->setText("");
	ui.lineEditClass->setText("");
	ui.lineEditTerm->setText("");

	ui.spinBoxChinese->setValue(0);
	ui.spinBoxMath->setValue(0);
	ui.spinBoxEnglish->setValue(0);
	ui.spinBoxComputer->setValue(0);
}

QString AddInfoDialog::GetSqlString()
{
	int ID = ui.lineEditID->text().toInt();
	QString strName = ui.lineEditName->text();
	QString strClass = ui.lineEditClass->text();
	QString strTerm = ui.lineEditTerm->text();

	double gradeChinese = ui.spinBoxChinese->value();
	double gradeMath = ui.spinBoxMath->value();
	double gradeEnglish = ui.spinBoxEnglish->value();
	double gradeComputer = ui.spinBoxComputer->value();
	QString strSql;

	if (etype == AddInfo_Type)
	{

		strSql = QString("INSERT INTO student_grade (id, name, term, class,chinese,math,english,conputer) \
			VALUES(%1, '%2', '%3', '%4',%5,%6,%7,%8);").arg(ID).arg(strName).arg(strClass).arg(strTerm).arg(gradeChinese).arg(gradeMath).arg(gradeEnglish).arg(gradeComputer);

	}

	return strSql;
}

void AddInfoDialog::SetType(AddType type)
{
	etype = type;
}
