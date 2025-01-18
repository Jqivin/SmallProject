#include "StudentGrade.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include "AddInfoDialog.h"
#include <QDialog>
#include "DeleteDialog.h"
#include <QSqlError>
#include <QDebug>
#include "UpdateDialog.h"
#include "SeleteDialog.h"

#define Table_name "studentGrade"

StudentGrade::StudentGrade(QWidget *parent)
    : QMainWindow(parent)
    , m_pModel(nullptr)
{
    ui.setupUi(this);
    Init();

    connect(ui.btnAdd, &QPushButton::clicked, this, &StudentGrade::AddInfo);
    connect(ui.btnDelete, &QPushButton::clicked, this, &StudentGrade::DeleteInfo);
    connect(ui.btnShowAll, &QPushButton::clicked, this, &StudentGrade::SelectAll);
    connect(ui.btnUpdate, &QPushButton::clicked, this, &StudentGrade::UpdateInfo);
    connect(ui.btnQuery, &QPushButton::clicked, this, &StudentGrade::SeleteInfo);

}

StudentGrade::~StudentGrade()
{
    
}

void StudentGrade::Init()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("student.db"); // 你可以更改为任何你想要的名称
    if (!m_db.open())
    {
        qDebug() << "connect error";
    }
    else
    {
        qDebug() << "connect success";
    }

    // 创建数据表
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS student_grade (id INTEGER PRIMARY KEY AUTOINCREMENT,\
        name TEXT,\
        term INTEGER, \
        class TEXT,\
        chinese REAL,\
        math REAL,\
        english REAL,\
        conputer REAL)");

    if (!success)
    {
        qDebug() << "create table error";
    }
    else
    {
        qDebug() << "create table success";
    }
    

    m_pModel = new QSqlTableModel(this);
    m_pModel->setTable("employees");  // 设置要操作的表名
    m_pModel->setEditStrategy(QSqlTableModel::OnRowChange);  // 设置编辑策略

    // 设置表头标题
    m_pModel->setHeaderData(0, Qt::Horizontal, "ID");
    m_pModel->setHeaderData(1, Qt::Horizontal, "姓名");
    m_pModel->setHeaderData(2, Qt::Horizontal, "Class");
    m_pModel->setHeaderData(3, Qt::Horizontal, "Term");
    m_pModel->setHeaderData(4, Qt::Horizontal, "Chinese");
    m_pModel->setHeaderData(5, Qt::Horizontal, "Math");
    m_pModel->setHeaderData(6, Qt::Horizontal, "English");
    m_pModel->setHeaderData(7, Qt::Horizontal, "Computer");

    ui.tableView->setModel(m_pModel);
    ui.tableView->show();

    SelectAll();
}

void StudentGrade::SelectAll()
{
    QString strSql = QString("select * from student_grade");
    m_pModel->setQuery(strSql);
}

void StudentGrade::AddInfo()
{
    AddInfoDialog addDialog;

    if (QDialog::Accepted == addDialog.exec())
    {
        QString strSql = addDialog.GetSqlString();
        m_pModel->setQuery(strSql);
        QSqlError err = m_pModel->lastError();
        qDebug() << err;
        SelectAll();
    }
}

void StudentGrade::DeleteInfo()
{
    DeleteDialog deleteDialog(this);
    if (QDialog::Accepted == deleteDialog.exec())
    {
        QString strSql = deleteDialog.GetSqlString();
        m_pModel->setQuery(strSql);
        QSqlError err = m_pModel->lastError();
        qDebug() << err;
        SelectAll();
    }

}

void StudentGrade::UpdateInfo()
{
    UpdateDialog updateDialog;

    if (QDialog::Accepted == updateDialog.exec())
    {
        QString strSql = updateDialog.GetSqlString();
        m_pModel->clear();
        m_pModel->setQuery(strSql);
        QSqlError err = m_pModel->lastError();
        qDebug() << err;
        
        SelectAll();
    }
}

void StudentGrade::SeleteInfo()
{
    SeleteDialog selectDlg;
    connect(&selectDlg, &SeleteDialog::SignalGetSum, this, [&](QString strSql) {
        QSqlQuery query(m_db);

        // 执行查询
        if (!query.exec(strSql)) {
            qDebug() << "Query failed:" << query.lastError().text();
            return;
        }

        // 处理查询结果
        double total_score;
        double average_score;
        while (query.next()) {
            total_score = query.value(0).toDouble();
            average_score = query.value(1).toDouble();
        }

        selectDlg.SetSum(total_score, average_score);
    });


    if (QDialog::Accepted == selectDlg.exec())
    {
        QString strSql = selectDlg.GetSqlString();
        m_pModel->clear();
        m_pModel->setQuery(strSql);
        QSqlError err = m_pModel->lastError();
        qDebug() << err;

    }
}
