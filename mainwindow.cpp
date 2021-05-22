#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fenetre_equip_course.h"
#include "ui_fenetre_equip_course.h"
#include "fenetre_Etage_Chambre.h"
#include "ui_fenetre_Etage_Chambre.h"
#include "CameraLumiere.h"
#include "ui_CameraLumiere.h"
#include "LoisirDevoir.h"
#include "ui_LoisirDevoir.h"
#include "fenetre_Porte_Fenetre.h"
#include "ui_fenetre_Porte_Fenetre.h"

#include "login.h"
#include <QSqlQuery>
#include "connexion.h"
#include <QMessageBox>
#include <QIntValidator>
#include "profil.h"
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QComboBox>
#include "duscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    profile P;
    ui->setupUi(this);
    mScene = new DuScene(this);

    ui->graphicsView_2->setScene(mScene);

  //  this->setStyleSheet("{background-image: url(:C:/projet-new/projet/background.jpeg);}");
  //  this->centralWidget()->setStyleSheet(
             //"background-image:url(\"C:/projet-new/projet/background.jpeg\"); background-position: center;" );
        QPixmap pix("C:/projet-new/projet/logo.png");
           ui->label_logo->setPixmap(pix.scaled(161,141));
         QPixmap pix2("C:/projet-new/projet/background.jpeg");
            ui->label_acceuil->setPixmap(pix2.scaled(811,441));

        QPixmap pix4("C:/projet-new/projet/register-icon-blue.png");
           ui->label_register_icon->setPixmap(pix4.scaled(230,228));
        QPixmap pix3("C:/projet-new/projet/login.png");
           ui->loginicon->setPixmap(pix3.scaled(381,311));
            //background



            QPixmap bkgnd("C:/projet-new/projet/background.jpeg");
                bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
                QPalette palette;
                palette.setBrush(QPalette::Background, bkgnd);
                this->setPalette(palette);




            //background
    Connexion t;
    t.ouvrirConnexion();
    ui->registID->setValidator(new QIntValidator(0,99999,this));
    ui->tab_login->setModel(L.afficher());
    //ui->tab_users_2->setModel(P.afficherprof());
ui->tab_profile->setModel(P.afficherprof());

    proxy = new QSortFilterProxyModel();
    proxy->setSourceModel(P.afficherprof());
    ui->tab_profile->setModel(proxy);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registbtn_clicked()
{
    int id=ui->registID->text().toInt();
    QString username=ui->usernamereg->text();
    QString password=ui->passwordreg->text();
    QString email=ui->emailreg->text();
    QString phone=ui->phonereg->text();

    Login L(id,username,password,email,phone);
    bool test=L.ajouterL();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout Effectué\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
    }
ui->tab_profile->setModel(L.afficher());
}

void MainWindow::on_suppbtn_clicked()
{
    Login lc;
    int test=0;
    QMessageBox msgBox;


    //lc.supprimer(selected2);

       ui->tab_login->setModel(lc.afficher());

       if(lc.supprimer(selected2))
       {
           msgBox.setText("suppression avec succés");
                     ui->tab_login->setModel(lc.afficher());
       }




}
void MainWindow::on_logbtn_clicked()
{
    QString username = ui->usernamlog->text();
     QString password = ui->passwordlog->text();
     QSqlQuery query ;

        query.prepare("SELECT * FROM LOGIN WHERE USERNAME=\'"+username+"\' AND PASSWORD=\'"+password+"\' ");
    int test=0;
        if(query.exec()){
            while(query.next())
                        { if (test==1){   QMessageBox::information(nullptr, QObject::tr("MDP"),
                                                                  QObject::tr("Mot De Passe correcte"), QMessageBox::Cancel);


                }

                                    test=1;

                                    ui->stackedWidget->setCurrentIndex(3);



        }}

        if(test!=1){
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                          QObject::tr("Veuillez saisir de nouveau.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }


       if(test!=1){
           QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                         QObject::tr("Veuillez saisir de nouveau.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
       }


}
void MainWindow::fill_form2(int selected2 ) {
QSqlQuery query;
    query.prepare("select * from LOGIN where ID= :sell");
    query.bindValue(":sell", selected2);
    query.exec();
    while(query.next()){
        ui->IDupd->setText(query.value(0).toString());
    ui->usernameupd->setText(query.value(1).toString());
    ui->passwordupd->setText(query.value(2).toString());
    ui->emailupd->setText(query.value(3).toString());//text edit
     ui->phoneupd->setText(query.value(4).toString()); //line edit
   //ui->comboBoxPoids->setCurrentText(query.value(5).toString());

    }
}
QString MainWindow::getid() const { //date
   return ui->registID->text();
}
QString MainWindow::getPassword() const { //date
   return ui->passwordreg->text();
}
QString MainWindow::getUsername() const { //date
    return ui->usernamereg->text();
}
QString MainWindow::getEmail() const { //date
    return ui->emailreg->text();
}
QString MainWindow::getPhone() const { //date
    return ui->phonereg->text();
}
void MainWindow::on_logupdatebtn_clicked()
{
    Login L;
    QString s1=getUsername();
    QString s2=getPassword();
    QString s3=getEmail();
    QString s4=getPhone();


   // QString s5=get_poids();
     Login lm(selected2,s1,s2,s3,s4);
        lm.modifierL(selected2);
        ui->tab_login->setModel(lm.afficher());
}
void MainWindow::on_registerProf_clicked()
{
    int  code=ui->CodeProf->text().toInt();
    QString nom=ui->NomProf->text();
    QString prenom=ui->PrenomProf->text();
    QString location=ui->LocProf->text();
    QString role=ui->RoleProf->currentText();

    profile P(code,nom,prenom,location,role);
   bool test=P.ajouterutil();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout Effectué\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
        ui->tab_profile->setModel(P.afficherprof());
    }



}
void MainWindow::fill_form(int selected ) {
QSqlQuery query;
    query.prepare("select * from USE where CODE= :sel");
    query.bindValue(":sel", selected);
    query.exec();
    while(query.next()){
        ui->Code2->setText(query.value(0).toString());//date
 ui->Nom2->setText(query.value(1).toString());
 ui->Prenom2->setText(query.value(2).toString());//text edit
  ui->Location2->setText(query.value(3).toString()); //line edit
   ui->Role2->setCurrentText(query.value(4).toString()); //combobox
   //ui->comboBoxPoids->setCurrentText(query.value(5).toString());

    }
}
QString MainWindow::get_Nom() const { //date
   return ui->NomProf->text();
}
QString MainWindow::get_Prenom() const { //date
    return ui->PrenomProf->text();
}
QString MainWindow::get_Location() const { //date
    return ui->LocProf->text();
}
QString MainWindow::get_Role() const { //date
    return ui->RoleProf->currentText();
}
void MainWindow::on_updateprof_clicked()
{

    QString s1=get_Nom();
    QString s2=get_Prenom();
    QString s3=get_Location();
    QString s4=get_Role();

    profile mc(selected,s1,s2,s3,s4);
        mc.modifier(selected);
        ui->tab_profile->setModel(mc.afficherprof());

}

void MainWindow::on_tab_profile_clicked(const QModelIndex &index)
{
      selected=ui->tab_profile->model()->data(index).toInt();
}
void MainWindow::on_tab_login_clicked(const QModelIndex &index)
{
      selected2=ui->tab_login->model()->data(index).toInt();
}

void MainWindow::on_tab_profile_doubleClicked(const QModelIndex &index)
{
     fill_form(selected);
}

void MainWindow::on_suppbtnProf_clicked()
{

    profile mc;
      mc.supprimer(selected);
       ui->tab_profile->setModel(mc.afficherprof());
}

void MainWindow::on_commandLinkButton_clicked()
{

}

void MainWindow::on_gestionprofil_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_Nexthome_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

    void MainWindow::recherche(QSqlQueryModel* model , QTableView * tab, QComboBox * indexColone, QLineEdit * le_recherche)
    {
     proxy = new QSortFilterProxyModel();
     proxy->setSourceModel(model);
     proxy->setFilterFixedString(le_recherche->text());
     proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
     proxy->setFilterKeyColumn(indexColone->currentIndex()-1);// chercher dans la coloune ou donner le numero de la colone
     tab->setModel(proxy);
    }

    void MainWindow::on_searchprof_textChanged(const QString &arg1)
    {
    recherche(P.afficherprof(),ui->tab_profile,ui->profilTri,ui->searchprof);
    }



void MainWindow::on_searchlog_textChanged(const QString &arg1)
{
    recherche(P.afficherprof(),ui->tab_login,ui->logTri,ui->searchlog);
}

void MainWindow::on_returnlog_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Createbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_forgetPW_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
   QString username = ui->usernamlog->text();
   QString password = ui->passwordlog->text();
   QSqlQuery query ;
   int test=0;

      query.prepare("SELECT * FROM LOGIN WHERE USERNAME=\'"+username+"\' AND PASSWORD=\'"+password+"\' ");

      if(query.exec()){
          while(query.next())
                      {
              test=1;
              QString password_new = ui->newPw->text();
              QSqlQuery query1 ;

              query1.prepare( "UPDATE LOGIN SET PASSWORD=\'"+password_new+"\'WHERE USERNAME=\'"+username+"\'");
               query1.exec();
                   QMessageBox::information(nullptr, QObject::tr("MDP"),
                             QObject::tr("Mot De Passe modifié"), QMessageBox::Cancel);






      }}
      if(test!=1){
          QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                        QObject::tr("Veuillez saisir de nouveau.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_returnPW_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_GestProfils_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}





void MainWindow::on_tab_login_doubleClicked(const QModelIndex &index)
{
    fill_form2(selected2);

}


void MainWindow::on_GestCourses_Equip_clicked()
{

    fenetre_equip_course hassen;
    hassen.setModal(true);
    hassen.exec();
}

void MainWindow::on_GestDevoirs_Loisir_clicked()
{
    LoisirDevoir amin;
        amin.setModal(true);
        amin.exec();
}

void MainWindow::on_GestCamera_Lum_clicked()
{
    CameraLumiere mazlout;
        mazlout.setModal(true);
        mazlout.exec();
}

void MainWindow::on_GestEtage_Chambre_clicked()
{
    EtageChambre nabil;
       nabil.setModal(true);
       nabil.exec();
}

void MainWindow::on_GestPorte_Fenetre_clicked()
{
    Dialog bechir;
       bechir.setModal(true);
       bechir.exec();
}



void MainWindow::on_return_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_return_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_startbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
