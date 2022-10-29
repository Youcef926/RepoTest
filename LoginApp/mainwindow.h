#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "sign_in.h"
#include <QPropertyAnimation>
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();
    void on_sign_in_push_button_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    sign_in *sign;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
