#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StudentGrade.h"
#include <QSqlTableModel>
#include"AddInfoDialog.h"
class StudentGrade : public QMainWindow
{
    Q_OBJECT

public:
    StudentGrade(QWidget *parent = nullptr);
    ~StudentGrade();

private:
    void Init();
   

private slots:
    // ��ѯ����
    void SelectAll();
    // ����
    void AddInfo();
    // ɾ��
    void DeleteInfo();
    // �޸�
    void UpdateInfo();

    void SeleteInfo();

private:
    Ui::StudentGradeClass ui;

    QSqlTableModel* m_pModel;
    QSqlDatabase m_db;   // ���ݿ�
};
