#include "DownloadImage.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QPixmap>
#include "ThreadPool/ThreadPool.h"
#include "ThreadPool/MyTask.h"

DownloadImage::DownloadImage(QWidget *parent)
    : QWidget(parent)
    , m_pNetWorkManager(nullptr)
    , m_iCount(0)
    , m_threadPool(nullptr)
{
    ui.setupUi(this);

    m_pNetWorkManager = new QNetworkAccessManager(this);
    ui.threadBar1->setValue(0);
    ui.threadBar2->setValue(0);
    connect(ui.btnDownload, &QPushButton::clicked, this, &DownloadImage::OnDownloadPic);

    m_threadPool = new ThreadPool(2);
    m_threadPool->Start();
}

DownloadImage::~DownloadImage()
{}

void DownloadImage::OnDownloadPic()
{
    QString str = "http://117.72.60.81/images/hello.png";
    std::shared_ptr<MyTask> pTask = std::make_shared<MyTask>();
    std::shared_ptr<DownloadInfo> info = std::make_shared<DownloadInfo>(str,m_iCount++);
    pTask->SetDownloadInfo(info);
    connect(pTask.get(), &MyTask::signalDownloadProgress, this, [=](qint64 iDownload, qint64 iTotal){
        int a = ui.threadBar1->value();
        int b = ui.threadBar2->value();
 
            ui.threadBar1->setValue(iDownload * 1.0 / iTotal * 100);
            return;
        
    });

    m_threadPool->AddTask(pTask);

}