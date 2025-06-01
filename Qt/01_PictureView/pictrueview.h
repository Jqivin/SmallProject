#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PictrueView.h"
#include <QButtonGroup>
#include <QTranslator>
#include <QMenuBar>
#include <QMenu>

class PictrueView : public QMainWindow
{
    Q_OBJECT

public:
    PictrueView(QWidget *parent = nullptr);
    ~PictrueView();

    void InitUI();

public slots:
    void onRadioButtonClicked(QAbstractButton* button);
    // �ҶȻ�
    void gray();
    // ��ֵ��
    void onSliderBinaryChanged(int threshold);
    // ��ֵ�˲�
    void onBtnMeanFilter();
    // ٤���仯slider
    void onslidergammaChanged(int value);
    //��Ե����
    void onBtnEdgeDetection();

signals:
    void signalLanChanged();

private:
    // ��ֵ�˲���
    QImage applyMeanFilter(const QImage& srcImage);
    // ٤���任
    QImage gammaCorrection(const QImage& inputImage, double gamma);
    // ��Ե����
    QImage sobelEdgeDetection(const QImage& inputImage);
    void LanChanged(int ilan);
private:
    Ui::PictrueViewClass ui;

    QImage* m_pImage;
    QButtonGroup* m_btns;
    QTranslator*  m_translator;
    QMenuBar* bar;
    QMenu* fileMenu;
    QMenu* pLanguage;
    QAction* pAbout;
};
