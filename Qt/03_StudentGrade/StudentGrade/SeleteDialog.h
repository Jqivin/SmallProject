#pragma once

#include <QDialog>
#include "ui_SeleteDialog.h"

enum SelectType
{
	SelectBy_Class = 0,
	Select_Sum,
	Select_Failed,
};
class SeleteDialog : public QDialog
{
	Q_OBJECT

public:
	SeleteDialog(QWidget *parent = nullptr);
	~SeleteDialog();

	QString GetSqlString();

	void SetSum(double sum, double aver);

signals:
	void SignalGetSum(QString);

private:
	Ui::SeleteDialogClass ui;

	SelectType eType;

};
