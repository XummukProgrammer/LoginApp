#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUsersModel();
}

MainWindow::~MainWindow()
{
    delete ui;

    if (_pUsersModel)
    {
        delete _pUsersModel;
    }
}

void MainWindow::InitUsersModel()
{
    if (_pUsersModel)
    {
        qDebug() << "The user model has already been initialized";
        return;
    }

    UsersModel::DatabaseInfo databaseInfo;
    databaseInfo.host = "127.0.0.1";
    databaseInfo.name = "users";
    databaseInfo.user = "user";
    databaseInfo.pass = "pass";

    _pUsersModel = new UsersModel(databaseInfo);
    if (!_pUsersModel->IsSuccessConnect())
    {
        // TODO: Show error window and program exit.
    }
}

void MainWindow::on_enterButton_clicked()
{
    if (_pUsersModel)
    {
        const auto login = ui->loginEdit->text();
        const auto password = ui->passwordEdit->text();

        if (!_pUsersModel->HasUser(login))
        {
            _pUsersModel->AddUser(login, password);
        }
    }
}
