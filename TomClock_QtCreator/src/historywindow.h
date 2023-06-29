#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include"history.h"
#include<QVector>
#include<QTime>
#include<QPushButton>
#include<QLabel>
#include<QGridLayout>
namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();
    QString caculateTotalTime();//计算总时长
    QString historyRecord(History h);//获取历史纪录
    int caculateTotalTomato();
private:
    Ui::HistoryWindow *ui;
    QVector<History>histories;
     QGridLayout *pLayout;
signals:
    void BacktoMain();
private slots:
    void MaintoHistory();
    void on_backToMain_clicked();
    void createHistory(History history);
};

#endif // HISTORYWINDOW_H
