#include "fenetre_lumiere_camera.h"
#include "ui_fenetre_lumiere_camera.h"
#include <QComboBox>
#include "exportexcelobject.h"
#include <QUrlQuery>

#include <QNetworkReply>

#include <QJsonValue>

#include <QJsonValueRef>

#include <QJsonDocument>

#include <QJsonObject>

#include <QJsonArray>

#include <QString>

#include <QFileDialog>

#include <QtCore>

#include <QtGui>

#include <QDialog>

#include <QModelIndex>

#include <QGridLayout>

#include <QApplication>

#include <QIntValidator>

#include <QDateTime>

#include <QMediaPlayer>

#include <QRadioButton>

lumCam::lumCam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lumCam)
{
    ui->setupUi(this);

    proxy = new QSortFilterProxyModel();
    proxy->setSourceModel(p.afficher());
    ui->tabLumiere->setModel(proxy);
    proxy2 = new QSortFilterProxyModel();
    proxy2->setSourceModel(f.afficher());
    ui->tabCamera->setModel(proxy2);

}

void lumCam::recherche(QSqlQueryModel* model , QTableView * tab, QComboBox * indexColone, QLineEdit * le_recherche)
{
 proxy = new QSortFilterProxyModel();
 proxy->setSourceModel(model);
 proxy->setFilterFixedString(le_recherche->text());
 proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
 proxy->setFilterKeyColumn(indexColone->currentIndex()-1);// chercher dans la coloune ou donner le numero de la colone
 tab->setModel(proxy);
}

lumCam::~lumCam()
{
    delete ui;
}

void lumCam::on_buttonAjouterlumiere_clicked()
{
    int idlum=ui->idlum->value();
    QString etatlum=ui->cbEtatlumiere->currentText();
    QString piece=ui->lapiece->text();
    QString duree=ui->laDuree->text();

    Lumiere p(idlum,etatlum,piece,duree);
    QMessageBox msg;
    if(p.ajouter())
    {
        msg.setText("ajout avec succés");
        //show_tables(p.afficherProduit(),ui->tabProduits);
        proxy = new QSortFilterProxyModel();
        proxy->setSourceModel(p.afficher());
        ui->tabLumiere->setModel(proxy);
        ui->idlum->clear();
        ui->lapiece->clear();
        ui->laDuree->clear();

    }
    else
    {
        msg.setText("echec lors de l'ajout");
    }
    msg.exec();}

void lumCam::on_tablumiere_doubleClicked(const QModelIndex &index)
{
    QSqlQuery query;
   query.prepare("select * from lumiere where idlum= :idlum");
   query.bindValue(":idlum",lumiereSelectionne);
   if(query.exec())
   {
       while(query.next())
       {

           ui->idlum->setValue(query.value(0).toInt());
           ui->cbEtatlumiere->setCurrentIndex(0);
           ui->cbEtatlumiere->setCurrentIndex(ui->cbEtatlumiere->findText(query.value(1).toString(),Qt::MatchExactly));
           ui->lapiece->setText(query.value(2).toString());
           ui->laDuree->setText(query.value(3).toString());


       }
   }
}



void lumCam::on_leRecherche_textChanged(const QString &arg1)
{
    recherche(p.afficher(),ui->tabLumiere,ui->cbTri,ui->leRecherche);
}

void lumCam::on_buttonSupprimerlumiere_clicked()
{
    Lumiere p;
    QMessageBox msgBox;
    QMessageBox msg;
    if(lumiereSelectionne=="")
    {
         msgBox.setText("Aucun lumiere n'est selectionné!");
    }
    else
    {
        msgBox.setText("Voulez vous supprimer le lumiere "
                       "idlum "+lumiereSelectionne+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }

    int rep=msgBox.exec();
    switch(rep)
    {
          case QMessageBox::Yes:

            if (p.supprimer(lumiereSelectionne.toInt()))
            {
            msg.setText("suppression avec succes.");
            msg.setIcon(QMessageBox::Information);
            proxy = new QSortFilterProxyModel();
            proxy->setSourceModel(p.afficher());
            ui->tabLumiere->setModel(proxy);

            }
            else
            {
                msg.setText("echec de suppression");

            }
             msg.exec();
                break;;

           case QMessageBox::No:
        return;
            break;
     }
}

void lumCam::on_tablumiere_clicked(const QModelIndex &index)
{
    lumiereSelectionne=ui->tabLumiere->model()->data(index.sibling(index.row(),0)).toString();
    Lumiere p;
    p.setidlum(lumiereSelectionne.toInt());


}


void lumCam::on_buttonModifererlumiere_clicked()
{
    int idlum=ui->idlum->value();
    QString etatlum=ui->cbEtatlumiere->currentText();
    QString piece=ui->lapiece->text();
    QString duree=ui->laDuree->text();
    Lumiere p(idlum,etatlum,piece,duree);

 bool test=p.modifier();
 QMessageBox msg;
 if(test)
 {
     msg.setText("modifier avec succés");
     proxy = new QSortFilterProxyModel();
     proxy->setSourceModel(p.afficher());
     ui->tabLumiere->setModel(proxy);
 }
 else
 {
     msg.setText("echec lors du modification");
 }
 msg.exec();
}

/*void Dialog::on_ButtonExcel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "porte", ui->tabPorte);

    //colums to export
    obj.addField(0, "NUMERO", "char(50)");
    obj.addField(1, "ETAT", "char(50)");
    obj.addField(2, "DIMENSIONS", "char(50)");
    obj.addField(3, "MATIERE", "char(50)");
    obj.addField(4, "DESCRIPTION", "char(50)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}*/

void lumCam::on_buttonAjouterCamera_clicked()
{
    int idcam=ui->spNumeroCamera->value();
    QString etatcam=ui->cbEtatCamera->currentText();
    QString emplacement=ui->leDimensionsCamera->text();

    Camera f(idcam,etatcam,emplacement);
    QMessageBox msg;
    if(f.ajouter())
    {
        msg.setText("ajout avec succés");
        //show_tables(p.afficherProduit(),ui->tabProduits);
        proxy2 = new QSortFilterProxyModel();
        proxy2->setSourceModel(f.afficher());
        ui->tabCamera->setModel(proxy2);
        ui->spNumeroCamera->clear();
        ui->cbEtatCamera->clear();
        ui->leDimensionsCamera->clear();

    }
    else
    {
        msg.setText("echec lors de l'ajout");
    }
    msg.exec();
}

/*void Dialog::on_ButtonExcelCamera_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "Camera", ui->tabPorte);

    //colums to export
    obj.addField(0, "NUMERO", "char(50)");
    obj.addField(1, "ETAT", "char(50)");
    obj.addField(2, "DIMENSIONS", "char(50)");
    obj.addField(3, "MATIERE", "char(50)");
    obj.addField(4, "DESCRIPTION", "char(50)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }

}*/

void lumCam::on_leRechercheCamera_textChanged(const QString &arg1)
{
    recherche(f.afficher(),ui->tabCamera,ui->cbTriCamera,ui->leRechercheCamera);

}

void lumCam::on_tabCamera_clicked(const QModelIndex &index)
{
    cameraSelectionne=ui->tabCamera->model()->data(index.sibling(index.row(),0)).toString();
    Camera f;
    f.setidcam(cameraSelectionne.toInt());
}

void lumCam::on_tabCamera_doubleClicked(const QModelIndex &index)
{
    QSqlQuery query;
   query.prepare("select * from Camera where idcam= :idcam");
   query.bindValue(":num",cameraSelectionne);
   if(query.exec())
   {
       while(query.next())
       {

           ui->spNumeroCamera->setValue(query.value(0).toInt());
           ui->cbEtatCamera->setCurrentIndex(0);
           ui->cbEtatCamera->setCurrentIndex(ui->cbEtatCamera->findText(query.value(1).toString(),Qt::MatchExactly));
           ui->leDimensionsCamera->setText(query.value(2).toString());


       }
   }

}

void lumCam::on_buttonSupprimerCamera_clicked()
{
    Camera f;
    QMessageBox msgBox;
    QMessageBox msg;
    if(cameraSelectionne=="")
    {
         msgBox.setText("Aucune Camera n'est selectionné!");
    }
    else
    {
        msgBox.setText("Voulez vous supprimer la Camera "
                       "numéro "+cameraSelectionne+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }

    int rep=msgBox.exec();
    switch(rep)
    {
          case QMessageBox::Yes:

            if (f.supprimer(cameraSelectionne.toInt()))
            {
            msg.setText("suppression avec succes.");
            msg.setIcon(QMessageBox::Information);
            proxy2 = new QSortFilterProxyModel();
            proxy2->setSourceModel(f.afficher());
            ui->tabCamera->setModel(proxy2);

            }
            else
            {
                msg.setText("echec de suppression");

            }
             msg.exec();
                break;;

           case QMessageBox::No:
        return;
            break;
     }
}

void lumCam::on_buttonModifererCamera_clicked()
{
    int idcam=ui->spNumeroCamera->value();
    QString etatcam=ui->cbEtatCamera->currentText();

    QString emplacement=ui->leDimensionsCamera->text();

    Camera f(idcam,etatcam,emplacement);

 bool test=f.modifier();
 QMessageBox msg;
 if(test)
 {
     msg.setText("modifier avec succés");
     proxy2 = new QSortFilterProxyModel();
     proxy2->setSourceModel(f.afficher());
     ui->tabCamera->setModel(proxy2);
 }
 else
 {
     msg.setText("echec lors du modification");
 }
 msg.exec();

}


void lumCam::on_buttonSupprimerCamera_2_clicked()
{
    QTableView *table;
                       table = ui->tabCamera;
                       QString filters("CSV files (*.csv)");
                       QString defaultFilter("CSV files (*.csv)");
                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                          filters, &defaultFilter);
                       QFile file(fileName);
                       QAbstractItemModel *model =  table->model();
                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                           QTextStream data(&file);
                           QStringList strList;
                           for (int i = 0; i < model->columnCount(); i++) {
                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") << "\n";
                           for (int i = 0; i < model->rowCount(); i++) {
                               strList.clear();
                               for (int j = 0; j < model->columnCount(); j++) {
                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") + "\n";
                           }
                           file.close();
                           //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                       }
}

void lumCam::on_buttonSupprimerlumiere_2_clicked()
{
    QTableView *table;
                       table = ui->tabCamera;
                       QString filters("CSV files (*.csv)");
                       QString defaultFilter("CSV files (*.csv)");
                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                          filters, &defaultFilter);
                       QFile file(fileName);
                       QAbstractItemModel *model =  table->model();
                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                           QTextStream data(&file);
                           QStringList strList;
                           for (int i = 0; i < model->columnCount(); i++) {
                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") << "\n";
                           for (int i = 0; i < model->rowCount(); i++) {
                               strList.clear();
                               for (int j = 0; j < model->columnCount(); j++) {
                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") + "\n";
                           }
                           file.close();
                           //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                       }
}
