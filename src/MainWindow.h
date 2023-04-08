#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "UsersModel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void InitUsersModel();

private slots:
    void on_enterButton_clicked();

private:
    Ui::MainWindow *ui;
    UsersModel* _pUsersModel;
};
#endif // MAINWINDOW_H
