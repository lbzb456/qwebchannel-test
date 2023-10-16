#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webView = new QWebEngineView(ui->centralwidget);
    webView->load(QUrl::fromLocalFile("F:\\qt_pro\\build-qwebchannel_test-Desktop_Qt_5_9_9_MSVC2015_32bit-Debug\\debug\\test.html"));
    //mainLayout->addWidget(webView);
    webChannel = new QWebChannel;
    webobj = new WebClass();
    webChannel->registerObject("webobj", webobj);
    webView->page()->setWebChannel(webChannel);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    webobj->setProperty("content","111");
    qDebug() << webobj->getContent() << endl;

}
