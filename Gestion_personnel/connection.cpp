#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A5");
db.setUserName("SYSTEM");//inserer nom de l'utilisateur
db.setPassword("13072001");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
