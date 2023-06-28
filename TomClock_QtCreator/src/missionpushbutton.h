#ifndef MISSIONPUSHBUTTON_H
#define MISSIONPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLabel>
#include<QLineEdit>
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
      QPushButton *mChangeConfirm;
      QPushButton *mChangeCancel;
      QComboBox *workTime;
      QComboBox *relaxTime;
      QLineEdit *mName;
       QLabel name;
       QLabel wT;
        QLabel rT;
  signals:
    void deleteMission();
     void beginMission();
    void sentChange(Mission mi);
private   slots:
    void setAllNum();
    void change_clicked();
    void sentDelete();
    void sentBegin();
    void cancelChange();
    void confirmChange();
};

#endif // MISSIONPUSHBUTTON_H
