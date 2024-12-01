#include "PictrueView.h"
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QPixmap>
#include <QTranslator>
#include <QApplication>
#include <QSlider>

const int iPicWidth = 1000;
const int iPicHeight = 500;

PictrueView::PictrueView(QWidget *parent)
    : QMainWindow(parent)
    ,m_pImage(nullptr)
    , m_translator(nullptr)
    , bar(nullptr)
{
    ui.setupUi(this);

    m_pImage = new QImage();
    m_btns = new QButtonGroup(this);
    m_btns->addButton(ui.btnGray, 1);   // �Ҷ�
    m_btns->addButton(ui.btnBinary,2);
    m_btns->addButton(ui.btnMeanFilter,3);
    m_btns->addButton(ui.btnGamma, 4);
    m_btns->addButton(ui.btnEdgeDetect,5);

    ui.labelPic->setFixedSize(iPicWidth, iPicHeight);

    ui.sliderBinary->hide();
    ui.sliderGamma->hide();

    // ���Ӱ�ť����źźͲ�
    connect(m_btns, &QButtonGroup::buttonClicked, this, &PictrueView::onRadioButtonClicked);


    connect(ui.sliderBinary, &QSlider::valueChanged, this, &PictrueView::onSliderBinaryChanged);
    connect(ui.sliderGamma, &QSlider::valueChanged, this, &PictrueView::onslidergammaChanged);

    bar = menuBar();
    setMenuBar(bar);

    fileMenu = bar->addMenu(tr("file"));


    QAction* actionOpen = fileMenu->addAction(tr("open"));
    actionOpen->setShortcut(QKeySequence::Open);     // Ctrl+O
    actionOpen->setObjectName("open");
    connect(actionOpen, &QAction::triggered, this, [=] {
        QString strPath = QFileDialog::getOpenFileName(this, tr("open File"), ".", "(*.png)");
        if (strPath.isEmpty())
        {
            return;
        }
        else
        {
            m_pImage = new QImage(strPath);
            ui.labelPic->setPixmap(QPixmap::fromImage(*m_pImage).scaled(iPicWidth,iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    });


    pLanguage = bar->addMenu(tr("language"));
    QAction* actionChn = pLanguage->addAction(tr("chinese"));
    actionChn->setObjectName("chinese");
    connect(actionChn, &QAction::triggered, this, [=]{
        LanChanged(0);
    });

    QAction* actionEn = pLanguage->addAction(tr("english"));
    actionEn->setObjectName("english");
    connect(actionEn, &QAction::triggered, this, [=]{
        LanChanged(1);
    });

    pAbout = bar->addAction(tr("about"));
    connect(pAbout, &QAction::triggered, this, [=] {
        QMessageBox::about(this,"About",tr("namexxxxx"));
    });

    InitUI();

    LanChanged(0);

    connect(this,&PictrueView::signalLanChanged,this,[=]{
        pAbout->setText(tr("about"));
        actionEn->setText(tr("english"));
        actionChn->setText(tr("chinese"));
        pLanguage->setTitle(tr("language"));
        actionOpen->setText(tr("open"));
        fileMenu->setTitle(tr("file"));
    });

    emit signalLanChanged();

    setWindowIcon(QIcon("://app.ico"));
}


PictrueView::~PictrueView()
{
    if (m_pImage != nullptr)
        delete m_pImage;
}

void PictrueView::InitUI()
{
    ui.btnGray->setText(tr("Gray"));	// �ҶȻ�
    ui.btnBinary->setText(tr("Binary"));   // ��ֵ��
    ui.btnMeanFilter->setText(tr("meanFilter")); // ��ֵ�˲�
    ui.btnGamma->setText(tr("Gamma"));		// ٤���任
    ui.btnEdgeDetect->setText(tr("EdgeDetect"));  // ��Ե���

}

void PictrueView::LanChanged(int ilan)
{
    if(m_translator != nullptr)
    {
        QApplication::removeTranslator(m_translator);
    }
    else
    {
        m_translator = new QTranslator();
    }
    QString strFilename = "";
    if(ilan == 0)
    {
        // chinese
        strFilename = QCoreApplication::applicationDirPath() + "/translate/" +"PictrueView_zh_CN.qm";

    }
    else
    {
        // english
        strFilename = QCoreApplication::applicationDirPath() + "/translate/" + "PictrueView_en_AS.qm";
    }
    if(m_translator->load(strFilename))
    {
        QApplication::installTranslator(m_translator);
    }

    InitUI();

    emit signalLanChanged();
}

void PictrueView::onRadioButtonClicked(QAbstractButton* button)
{
    int id = m_btns->id(button);
    ui.sliderBinary->hide();
    ui.sliderGamma->hide();
    ui.labelPic->setPixmap(QPixmap::fromImage(*m_pImage).scaled(iPicWidth, iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    switch (id) {
    case 1: {
        gray();
        break;
    }
    case 2:
        ui.sliderBinary->show();
        ui.sliderBinary->setRange(0, 255);
        ui.sliderBinary->setValue(128);
        break;
    case 3:
        onBtnMeanFilter();
        break;
    case 4:
        ui.sliderGamma->show();
        ui.sliderGamma->setRange(0, 255);
        ui.sliderGamma->setValue(128);
        break;
    case 5:
        onBtnEdgeDetection();
        break;
    }
}
// �ҶȻ�
void PictrueView::gray()
{
    QImage originImage = *m_pImage;
    QImage newImage = originImage.convertToFormat(QImage::Format_ARGB32);
    QColor oldColor;

    for (int y = 0; y < newImage.height(); y++)
    {
        for (int x = 0; x < newImage.width(); x++)
        {
            oldColor = QColor(originImage.pixel(x, y));
            int average = (oldColor.red() + oldColor.green() + oldColor.blue()) / 3;
            newImage.setPixel(x, y, qRgb(average, average, average));
        }
    }

    ui.labelPic->setPixmap(QPixmap::fromImage(newImage).scaled(iPicWidth, iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

// ��ֵ��
void PictrueView::onSliderBinaryChanged(int threshold)
{
    QImage binarizedImage = m_pImage->copy();
    for (int y = 0; y < binarizedImage.height(); ++y)
    {
        for (int x = 0; x < binarizedImage.width(); ++x)
        {
            QRgb pixel = binarizedImage.pixel(x, y);
            int value = qGray(pixel);
            binarizedImage.setPixel(x, y, value > threshold ? 0xFFFFFFFF : 0xFF000000);
        }
    }
    ui.labelPic->setPixmap(QPixmap::fromImage(binarizedImage).scaled(iPicWidth, iPicHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

// ��ֵ�˲���
QImage PictrueView::applyMeanFilter(const QImage& srcImage)
{
    if (srcImage.isNull() || (srcImage.width() < 3) || (srcImage.height() < 3)) {
        return srcImage;
    }

    QImage filteredImage = srcImage;
    int kernel [3][3] = {
                        {1,1,1},
                        {1,1,1},
                        {1,1,1}};
    int sizeKernel = 3;
    int sumKernel = 9;
    QColor color;
    for(int x = sizeKernel/2;x<filteredImage.width() - sizeKernel/2;x++)
    {
        for(int y= sizeKernel/2;y<filteredImage.height() - sizeKernel/2;y++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            for(int i = -sizeKernel/2;i<=sizeKernel/2;i++)
            {
                for(int j = -sizeKernel/2;j<=sizeKernel/2;j++)
                {
                    color = QColor(filteredImage.pixel(x+i,y+j));
                    r+=color.red()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                    g+=color.green()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                    b+=color.blue()*kernel[sizeKernel/2+i][sizeKernel/2+j];
                }
            }
            r = qBound(0,r/sumKernel,255);
            g = qBound(0,g/sumKernel,255);
            b = qBound(0,b/sumKernel,255);
            filteredImage.setPixel(x,y,qRgb( r,g,b));
        }
    }
    return filteredImage;
}

// ����٤���任
QImage PictrueView::gammaCorrection(const QImage& inputImage, double gamma)
{
    // �������ͼ�񣬸�ʽΪ RGB32
    QImage outputImage(inputImage.size(), QImage::Format_RGB32);

    // ����٤��У������ֵ
    double inverseGamma = 1.0 / gamma;

    // ����ÿ������
    for (int y = 0; y < inputImage.height(); ++y) {
        for (int x = 0; x < inputImage.width(); ++x) {
            QColor color = inputImage.pixelColor(x, y);
            // ��ȡÿ��ͨ���ĻҶ�ֵ
            int r = color.red();
            int g = color.green();
            int b = color.blue();

            // ����٤���任
            int newR = static_cast<int>(255 * std::pow(r / 255.0, inverseGamma));
            int newG = static_cast<int>(255 * std::pow(g / 255.0, inverseGamma));
            int newB = static_cast<int>(255 * std::pow(b / 255.0, inverseGamma));

            // �����µ� RGB ֵ�� 0-255 ֮��
            newR = qBound(0, newR, 255);
            newG = qBound(0, newG, 255);
            newB = qBound(0, newB, 255);

            // �������ͼ�������
            outputImage.setPixel(x, y, qRgb(newR, newG, newB));
        }
    }

    return outputImage;
}
// ʹ��Sobel���ӽ��б�Ե���
QImage PictrueView::sobelEdgeDetection(const QImage& inputImage)
{
    int width = inputImage.width();
    int height = inputImage.height();
    QImage outputImage(width, height, QImage::Format_RGB32);

    // Sobel ��
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int sumX = 0;
            int sumY = 0;

            // Ӧ�� Sobel ����
            for (int ky = -1; ky <= 1; ++ky) {
                for (int kx = -1; kx <= 1; ++kx) {
                    QColor color = inputImage.pixelColor(x + kx, y + ky);
                    int intensity = qGray(color.rgb()); // ת��Ϊ�Ҷ�ֵ

                    sumX += intensity * Gx[ky + 1][kx + 1];
                    sumY += intensity * Gy[ky + 1][kx + 1];
                }
            }

            // �����ݶȷ�ֵ
            int magnitude = static_cast<int>(sqrt(sumX * sumX + sumY * sumY));
            magnitude = qBound(0, magnitude, 255); // ������ 0-255 ��Χ

            // �������ͼ�������
            outputImage.setPixel(x, y, qRgb(magnitude, magnitude, magnitude));
        }
    }

    return outputImage;
}

void PictrueView::onBtnEdgeDetection()
{
    QImage filteredImage = sobelEdgeDetection(*m_pImage);

    ui.labelPic->setPixmap(QPixmap::fromImage(filteredImage).scaled(iPicWidth, iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui.labelPic->update();
}

void PictrueView::onslidergammaChanged(int value)
{
    double gamma = value / 33;
    QImage filteredImage = gammaCorrection(*m_pImage, gamma);

    ui.labelPic->setPixmap(QPixmap::fromImage(filteredImage).scaled(iPicWidth, iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui.labelPic->update();
}

void PictrueView::onBtnMeanFilter()
{
    QImage filteredImage = applyMeanFilter(*m_pImage);

    ui.labelPic->setPixmap(QPixmap::fromImage(filteredImage).scaled(iPicWidth, iPicWidth, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui.labelPic->update();
}
