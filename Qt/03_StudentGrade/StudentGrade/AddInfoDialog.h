#pragma once

#include <QDialog>
#include "ui_AddInfoDialog.h"
enum AddType {
	AddInfo_Type = 0,
	UpdateInfo_Type,
};
class AddInfoDialog : public QDialog
{
	Q_OBJECT

public:
	AddInfoDialog(QWidget *parent = nullptr);
	~AddInfoDialog();

	void ClearAllInfo();

	QString GetSqlString();

	void SetType(AddType type);

private:
	Ui::AddInfoDialogClass ui;
	AddType  etype;
};
