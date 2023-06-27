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
    void LightTheme();
    void DarkTheme();
    void BackToMain();

private slots:
    void MaintoSettings();
    void on_themeChange_currentTextChanged(const QString &arg1);
    void on_backToMain_clicked();
    void ChangeToLight();
    void ChangeToDark();
};

#endif // SETTINGS_H
