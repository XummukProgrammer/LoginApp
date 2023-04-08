#ifndef USERSMODEL_H
#define USERSMODEL_H

#include <QString>
#include <QSqlDatabase>

class UsersModel final
{
public:
    struct DatabaseInfo
    {
        QString host;
        QString name;
        QString user;
        QString pass;
    };

public:
    UsersModel(const DatabaseInfo& databaseInfo);
    ~UsersModel();

public:
    void AddUser(const QString& login, const QString& password);
    bool HasUser(const QString& login) const;
    void RemoveUser(const QString& login);
    bool IsUserPasswordSuccessful(const QString& login, const QString& password) const;

public:
    bool IsSuccessConnect() const;

private:
    void InitDatabase();
    void CreateDatabaseTables();

private:
    QSqlDatabase _database;
    DatabaseInfo _databaseInfo;
};

#endif // USERSMODEL_H
