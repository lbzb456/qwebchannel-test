#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QtWebChannel>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WebClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content MEMBER m_content NOTIFY contentChanged );
private:
    QString m_content;

public slots:
    void jscallme()
    {
        QMessageBox::information(NULL, "jscallme", m_content);
    }
signals:
    void contentChanged(QString nc);
public:
    QString getContent(){return m_content;}

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView *webView;
    QWebChannel *webChannel ;
    WebClass *webobj;
//    QJsonObject *m_jsonData;
};


#endif // MAINWINDOW_H
