#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQueryModel>



class User
{
public:
    User();
    User(int,QString,QString,QString,QString);
    int getCode();
    QString getNom();
    QString getPrenom();
    QString getLocation();
    QString getRole();
    void setCode(int code);
    void setNom(QString nom);

    void setPrenom(QString prenom);
    void setLocation(QString location);
    void setRole(QString role);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    int code;
    QString nom,prenom,location,role;
};

#endif // USER_H
