#pragma once

#include <QtWidgets/QWidget>
#include "ui_DownloadImage.h"
#include <atomic>

class QNetworkAccessManager;
class ThreadPool;

class DownloadImage : public QWidget
{
    Q_OBJECT

public:
    DownloadImage(QWidget *parent = nullptr);
    ~DownloadImage();

public slots:
    void  OnDownloadPic();

private:
    Ui::DownloadImageClass ui;

    QNetworkAccessManager* m_pNetWorkManager;
    std::atomic<int>       m_iCount;

    // Ïß³Ì³Ø
    ThreadPool* m_threadPool;
};

