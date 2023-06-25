#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QWidget>

namespace Ui {
class HistoryWindow;
}

class HistoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();

private:
    Ui::HistoryWindow *ui;

private slots:
    void MaintoHistory();
};

#endif // HISTORYWINDOW_H
