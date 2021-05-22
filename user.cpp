#include "user.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

User::User()
{
    code=0;
    nom="";
    prenom="";
    location="";
    role="";




}

User::User(int code , QString nom,QString prenom,QString location,QString role)
{
this->code=code;
this->nom=nom ;
this->prenom= prenom;
this->location=location ;
this->role = role;

}
int User::getCode(){return code;}
QString User::getNom(){return nom;}
QString User::getPrenom(){return prenom;}
QString User::getLocation()    {return location;}
QString User::getRole(){return role;}
void User::setCode(int code){this->code=code;}
void User::setNom(QString nom){this->nom=nom;}

void User::setPrenom(QString prenom){this->prenom=prenom;}

void User::setLocation(QString Location){this->location=Location;}
void User::setRole(QString phone){this->role=phone;}
bool User::ajouter(){
    QSqlQuery query;
    QString code_string= QString::number(code);
    QString res= QString::number(code);
    query.prepare("INSERT INTO User (code,nom,prenom,location,phone""VALUES(:code,:nom,:prenom,:location,:phone");
    query.bindValue(":code",code_string);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
       query.bindValue(":location",location);
        query.bindValue(":role",role);
          return  query.exec();

}
QSqlQueryModel* User::afficher(){
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT * FROM User");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));

model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("location"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("role"));

return model;

}

bool User::supprimer(int code)
{

    QSqlQuery query;
    query.prepare("Delete FROM  user (code=:code)");
    query.bindValue(0,code);

    return query.exec();

}
