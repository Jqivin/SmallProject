#pragma once

#include <QDialog>
#include "ui_DeleteDialog.h"

class DeleteDialog : public QDialog
{
	Q_OBJECT

public:
	DeleteDialog(QWidget *parent = nullptr);
	~DeleteDialog();

	QString GetSqlString();

private:
	Ui::DeleteDialogClass ui;
};
