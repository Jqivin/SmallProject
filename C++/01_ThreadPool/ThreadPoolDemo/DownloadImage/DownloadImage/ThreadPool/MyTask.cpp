#include "MyTask.h"
#include <iostream>
#include <thread>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "Task.h"
#include <QApplication>
#include <QFile>
#include <QNetworkAccessManager>
#include <QEventLoop>

MyTask::MyTask( int priority, QObject* parent)
    : QObject(parent),
    Task(priority)
    , m_pNetWorkManager(nullptr)
{
    m_pNetWorkManager = new QNetworkAccessManager();
}
MyTask::~MyTask()
{
    delete m_pNetWorkManager;
}

void MyTask::run()
{
    QNetworkRequest req;
    req.setUrl(m_pInfo->strUrl);
    QEventLoop loop;
    QNetworkReply* reply = m_pNetWorkManager->get(req);

    QObject::connect(reply, &QNetworkReply::finished, this,[=] {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray imageData = reply->readAll();

            QString strPath = QApplication::applicationDirPath() + QString("/image/jqivin%1.png").arg(m_pInfo->id);
            QFile file(strPath);
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(imageData);
                file.close();
                qDebug() << "success:" << strPath;
            }
            else {
                qDebug() << "failed��";
            }
        }
        else
        {
            qDebug() << "����ʧ�ܣ�" << reply->errorString();
        }

    });

    QObject::connect(reply, &QNetworkReply::downloadProgress,this, [=](qint64 iDownload, qint64 iTotal) {
        double iDownProcess = iDownload * 1.0 / iTotal;
        //ui.threadBar1->setValue(iDownProcess * 100);
        //ui.threadBar1->update();
        qDebug() << "jqivinDownload:" << iDownload;
        emit signalDownloadProgress(iDownload, iTotal);
     });

    loop.exec(); // �ȴ��������

    // ����ظ�
    reply->deleteLater();
}