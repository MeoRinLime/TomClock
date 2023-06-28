#ifndef MISSIONPUSHBUTTON_H
#define MISSIONPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>

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
    static void setAN(int n);
private:
    Ui::MissionPushButton *ui;
    int num;

    static int allNum;
    QPushButton *pBtn;
     QPushButton *mBegin;
     QPushButton *mChange;
      QPushButton *mDelete;
    QHBoxLayout *hBlt;

  signals:
    void deleteMission();
     void beginMission();
private   slots:
    void setAllNum();

    void sentDelete();
    void sentBegin();
};

#endif // MISSIONPUSHBUTTON_H
