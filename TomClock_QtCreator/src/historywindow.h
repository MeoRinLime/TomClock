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
    explicit HistoryWindow(const QVector<History> &histories, QWidget *parent = nullptr);
    ~HistoryWindow();
    QString caculateTotalTime();//计算总时长
    QString historyRecord(History h);//历史纪录信息
    int caculateTotalTomato();//计算总番茄数
private:
    Ui::HistoryWindow *ui;
    QVector<History> histories;//历史数据容器
    QGridLayout *pLayout;//网格布局
    void closeEvent(QCloseEvent *event);
signals:
    void BacktoMain();//回到主页面

private slots:
    void MaintoHistory(QVector<History> histories);//从主界面到历史界面
    void on_backToMain_clicked();//回到主界面
    void createHistory(History history);//获取新历史记录添加到容器中
};

#endif // HISTORYWINDOW_H
