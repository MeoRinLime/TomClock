#ifndef MISSIONPUSHBUTTON_H
#define MISSIONPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include"mission.h"
namespace Ui {
class MissionPushButton;
}

class MissionPushButton : public QWidget
{
    Q_OBJECT

public:
    explicit MissionPushButton(QWidget *parent = nullptr);
    ~MissionPushButton();
    void setNum(int n);
    static int getallNum();
    QHBoxLayout *getHBlt();
    QPushButton *getPBtn();
    void disapearChoice();

private:
    Ui::MissionPushButton *ui;
    int num;
    static int allNum;
    QPushButton *pBtn;
     QPushButton *mBegin;
     QPushButton *mChange;
      QPushButton *mDelete;
    QHBoxLayout *hBlt;

private   slots:
    void setAllNum();
    //void changeMission();


};

#endif // MISSIONPUSHBUTTON_H
