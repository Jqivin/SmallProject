#include "DeleteDialog.h"

DeleteDialog::DeleteDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &DeleteDialog::accept);
}

DeleteDialog::~DeleteDialog()
{}

QString DeleteDialog::GetSqlString()
{
	QString strSql = QString("DELETE FROM student_grade WHERE id = %1").arg(ui.lineEditID->text().toInt());
	return strSql;
}
