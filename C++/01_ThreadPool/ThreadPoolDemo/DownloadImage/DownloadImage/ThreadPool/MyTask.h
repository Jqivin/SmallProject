#pragma once
#include "Task.h"
#include <memory>
#include <QtCore/QObject>

class QNetworkAccessManager;

struct DownloadInfo
{
	QString		strUrl;
	int id;

	DownloadInfo(QString strUrlParam, int idParam)
		: strUrl(strUrlParam)
		, id(idParam) 
	{
	}

};

class MyTask : public QObject,public Task
{
	Q_OBJECT

public:
	MyTask( int priority = PRIORITY_NORMAL,QObject* parent = nullptr);
	virtual ~MyTask();

	virtual void run();

	void SetDownloadInfo(const std::shared_ptr<DownloadInfo>& info) { m_pInfo = info; }
signals:
	void signalDownloadProgress(qint64 iDownload, qint64 iTotal);

private:
	QNetworkAccessManager* m_pNetWorkManager;
	std::shared_ptr<DownloadInfo> m_pInfo;
};

