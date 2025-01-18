#pragma once

#include <QDialog>
#include "ui_UpdateDialog.h"

class UpdateDialog : public QDialog
{
	Q_OBJECT

public:
	UpdateDialog(QWidget *parent = nullptr);
	~UpdateDialog();

	QString GetSqlString();

private:
	Ui::UpdateDialogClass ui;
};
