#include "SeleteDialog.h"
#include <QMessageBox>

SeleteDialog::SeleteDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnSelect, &QPushButton::clicked, this, [=] {
		eType = SelectBy_Class;
		accept();
	});

	connect(ui.btnFailed, &QPushButton::clicked, this, [=] {
		eType = Select_Failed;
		accept();
	});

	connect(ui.btnSum, &QPushButton::clicked, this, [=] {
		eType = Select_Sum;
		QString strSql = GetSqlString();
		emit SignalGetSum(strSql);
		});
}

SeleteDialog::~SeleteDialog()
{}

QString SeleteDialog::GetSqlString()
{
	QString strSql;
	if (eType == SelectBy_Class)
	{
		strSql = QString("Select * from student_grade where class = '%1' and term = '%2'").arg(ui.lineEditClass->text()).arg(ui.lineEditTerm->text());
	}
	else if (eType == Select_Failed)
	{
		strSql = QString("Select * from student_grade where chinese < 60 OR math < 60 OR english < 60 OR conputer < 60");
	}
	else if (eType == Select_Sum)
	{
		strSql = QString("SELECT \
			(chinese + math + english + conputer) AS total_score,\
			(chinese + math + english + conputer) / 4.0 AS average_score\
			FROM student_grade\
			WHERE id = %1; ").arg(ui.lineEditID->text().toInt());
	}
	return strSql;
}

void SeleteDialog::SetSum(double sum, double aver)
{
	QMessageBox msgBox;
	msgBox.setText(QString("sum:%1\naverage:%2").arg(sum).arg(aver));
	msgBox.exec();
}

