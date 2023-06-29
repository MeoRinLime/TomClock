#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>
#include"history.h"
#include<QVector>
#include<QTime>
#include<QPushButton>
#include<QLabel>
namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(const QVector<History> &histories, QWidget *parent = nullptr);
    ~HistoryWindow();
    QString caculateTotalTime();//计算总时长
    QString historyRecord(History h);//获取历史纪录
private:
    Ui::HistoryWindow *ui;
    QVector<History> histories;
signals:
    void BacktoMain();
private slots:
    void MaintoHistory(QVector<History> histories);
    void on_backToMain_clicked();
};

#endif // HISTORYWINDOW_H
