#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

namespace Ui {
class about;
}

class about : public QWidget
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private:
    Ui::about *ui;

signals:
    void BacktoMain();
    void AbouttoTeam();

private slots:
    void MaintoAbout();
    void TeamtoAbout();

    void on_backToMain_clicked();
    void on_ourTeam_clicked();
    void on_github_clicked();
};

#endif // ABOUT_H
