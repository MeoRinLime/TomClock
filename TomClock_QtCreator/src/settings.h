#ifndef SETTINGS_H
#define SETTINGS_H

#include <QTranslator>
#include <QWidget>
#include <QComboBox>

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
    QComboBox* languageComboBox;

signals:
    void currentIndexChanged(int);
    void currentIndexChanged(QString);
    void BacktoMain();


private slots:
    void closeEvent(QCloseEvent *event);
    void MaintoSettings();
    void on_backToMain_clicked();
    void on_themeChange_currentIndexChanged(int index);
    void on_languageChange_currentTextChanged(const QString &arg1);
};

#endif // SETTINGS_H
