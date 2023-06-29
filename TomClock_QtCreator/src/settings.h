#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;

signals:
    void currentIndexChanged(int);
    void BacktoMain();

private slots:
    void closeEvent(QCloseEvent *event);
    void MaintoSettings();
    void on_backToMain_clicked();
    void on_themeChange_currentIndexChanged(int index);
};

#endif // SETTINGS_H
