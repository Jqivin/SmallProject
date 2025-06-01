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
    // 查询所有
    void SelectAll();
    // 增加
    void AddInfo();
    // 删除
    void DeleteInfo();
    // 修改
    void UpdateInfo();

    void SeleteInfo();

private:
    Ui::StudentGradeClass ui;

    QSqlTableModel* m_pModel;
    QSqlDatabase m_db;   // 数据库
};
