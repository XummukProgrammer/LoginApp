#include "UsersModel.h"

#include <QDebug>
#include <QSqlQuery>

UsersModel::UsersModel(const DatabaseInfo& databaseInfo)
    : _database(QSqlDatabase::addDatabase("QSQLITE"))
    , _databaseInfo(databaseInfo)
{
    InitDatabase();
}

UsersModel::~UsersModel()
{

}

void UsersModel::AddUser(const QString& login, const QString& password)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO `users` (`login`, `password`) VALUES('%1', '%2')").arg(login).arg(password));
}

bool UsersModel::HasUser(const QString& login) const
{
    return false;
}

void UsersModel::RemoveUser(const QString& login)
{

}

bool UsersModel::IsUserPasswordSuccessful(const QString& login, const QString& password) const
{
    return true;
}

bool UsersModel::IsSuccessConnect() const
{
    return _database.isOpen();
}

void UsersModel::InitDatabase()
{
    qDebug() << "Connection to the database has started";

    _database.setHostName(_databaseInfo.host);
    _database.setDatabaseName(_databaseInfo.name);
    _database.setUserName(_databaseInfo.user);
    _database.setPassword(_databaseInfo.pass);
    _database.open();

    if (IsSuccessConnect())
    {
        qDebug() << "The connection to the database was successful";
        CreateDatabaseTables();
    }
    else
    {
        qDebug() << "The connection to the database has failed";
    }
}

void UsersModel::CreateDatabaseTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS `users` (`login` VARCHAR(64) NOT NULL PRIMARY KEY, `password` VARCHAR(128));");
}
