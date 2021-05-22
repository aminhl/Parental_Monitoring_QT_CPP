#include "fenetre_equip_course.h"
#include "ui_fenetre_equip_course.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include "exportexcelobject.h"
#include <QDateTime>
#include <QPixmap>
#include <QUrlQuery>
#include <QPrinter>
#include <QPainter>
#include <QNetworkReply>
#include "statistique.h"
#include <QJsonValue>
#include <QImage>
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
fenetre_equip_course::fenetre_equip_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre_equip_course)
{
    ui->setupUi(this);
    QPixmap pix("C:/projet-new/home1.png");
    QPixmap pix2("C:/projet-new/home1.png");
ui->label_pic->setPixmap(pix);
ui->label_pic2->setPixmap(pix2);
    proxy = new QSortFilterProxyModel();
    proxy->setSourceModel(p.afficher());
    ui->tabEquip->setModel(proxy);
    proxy2 = new QSortFilterProxyModel();
    proxy2->setSourceModel(f.afficher());
    ui->tabCourse->setModel(proxy2);



}


void fenetre_equip_course::recherche(QSqlQueryModel* model , QTableView * tab, QComboBox * indexColone, QLineEdit * le_recherche)
{
 proxy = new QSortFilterProxyModel();
 proxy->setSourceModel(model);
 proxy->setFilterFixedString(le_recherche->text());
 proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
 proxy->setFilterKeyColumn(indexColone->currentIndex()-1);// chercher dans la coloune ou donner le numero de la colone
 tab->setModel(proxy);
}

fenetre_equip_course::~fenetre_equip_course()
{
    delete ui;
}

void fenetre_equip_course::on_buttonAjouterEquip_clicked()
{
    int num=ui->spNumero->value();
    QString etat=ui->cbEtat->currentText();
    QString emp=ui->leEmp->text();
    QString nom=ui->leNom->text();
    QString desc=ui->textType->toPlainText();
    equipement p(num,etat,emp,nom,desc);
    QMessageBox msg;
    if(p.ajouter())
    {
        msg.setText("ajout avec succés");
        //show_tables(p.afficherProduit(),ui->tabProduits);
        proxy = new QSortFilterProxyModel();
        proxy->setSourceModel(p.afficher());
        ui->tabEquip->setModel(proxy);
        ui->spNumero->clear();
        ui->leEmp->clear();
        ui->leNom->clear();
        ui->textType->clear();
    }
    else
    {
        msg.setText("echec lors de l'ajout");
    }
    msg.exec();}

void fenetre_equip_course::on_tabEquip_doubleClicked(const QModelIndex &index)
{
    QSqlQuery query;
   query.prepare("select * from TAB_EQUIPEMENT where Numero= :num");
   query.bindValue(":num",EquipSelectionne);
   if(query.exec())
   {
       while(query.next())
       {

           ui->spNumero->setValue(query.value(0).toInt());
           ui->cbEtat->setCurrentIndex(0);
           ui->cbEtat->setCurrentIndex(ui->cbEtat->findText(query.value(1).toString(),Qt::MatchExactly));
           ui->leNom->setText(query.value(2).toString());
           ui->leEmp->setText(query.value(3).toString());
           ui->textType->setPlainText(query.value(4).toString());

       }
   }
}



void fenetre_equip_course::on_leRecherche_textChanged(const QString &arg1)
{
    recherche(p.afficher(),ui->tabEquip,ui->cbTri,ui->leRecherche);
}

void fenetre_equip_course::on_buttonSupprimerEquip_clicked()
{
    equipement p;
    QMessageBox msgBox;
    QMessageBox msg;
    if(EquipSelectionne=="")
    {
         msgBox.setText("Aucun Equip n'est selectionné!");
    }
    else
    {
        msgBox.setText("Voulez vous supprimer le Equip "
                       "numéro "+EquipSelectionne+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }

    int rep=msgBox.exec();
    switch(rep)
    {
          case QMessageBox::Yes:

            if (p.supprimer(EquipSelectionne.toInt()))
            {
            msg.setText("suppression avec succes.");
            msg.setIcon(QMessageBox::Information);
            proxy = new QSortFilterProxyModel();
            proxy->setSourceModel(p.afficher());
            ui->tabEquip->setModel(proxy);

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

void fenetre_equip_course::on_tabEquip_clicked(const QModelIndex &index)
{
    EquipSelectionne=ui->tabEquip->model()->data(index.sibling(index.row(),0)).toString();
    equipement p;
    p.setNumero(EquipSelectionne.toInt());


}


void fenetre_equip_course::on_buttonModifererEquip_clicked()
{
    int num=ui->spNumero->value();
    QString etat=ui->cbEtat->currentText();
    QString emp=ui->leEmp->text();
    QString nom=ui->leNom->text();
    QString desc=ui->textType->toPlainText();
    equipement p(num,etat,emp,nom,desc);

 bool test=p.modifier();
 QMessageBox msg;
 if(test)
 {
     msg.setText("modifier avec succés");
     proxy = new QSortFilterProxyModel();
     proxy->setSourceModel(p.afficher());
     ui->tabEquip->setModel(proxy);
 }
 else
 {
     msg.setText("echec lors du modification");
 }
 msg.exec();
}

void fenetre_equip_course::on_ButtonExcel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls, *.xlsx, *.xlsm, *.xlsb)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "TAB_EQUIPEMENT", ui->tabEquip);

    //colums to export
    obj.addField(0, "NUMERO", "char(50)");
    obj.addField(1, "ETAT", "char(50)");
    obj.addField(2, "NOM", "char(50)");
    obj.addField(3, "EMPLACEMENT", "char(50)");
    obj.addField(4, "TYPE", "char(50)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void fenetre_equip_course::on_buttonAjouterCourse_clicked()
{
    int num=ui->spNumeroCourse->value();
   // QString time=ui->timeEditCourse->time().toString("hh:mm");
    QString time=ui->cbTimeCourse->time().toString("hh:mm");
    QString status=ui->leStatusCourse->text();
    QString tache=ui->leTacheCourse->text();
    QString desc=ui->textDateCourse->date().toString("dd/MM/yyyy");
    course f(num,time,status,tache,desc);
    QMessageBox msg;
    if(f.ajouter())
    {
        msg.setText("ajout avec succés");
        //show_tables(p.afficherProduit(),ui->tabProduits);
        proxy2 = new QSortFilterProxyModel();
        proxy2->setSourceModel(f.afficher());
        ui->tabCourse->setModel(proxy2);
        ui->spNumeroCourse->clear();
        ui->leStatusCourse->clear();
        ui->leTacheCourse->clear();
        ui->textDateCourse->clear();
    }
    else
    {
        msg.setText("echec lors de l'ajout");
    }
    msg.exec();
}

void fenetre_equip_course::on_ButtonExcelCourse_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls, *.xlsx, *.xlsm, *.xlsb)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "TAB_COURSE", ui->tabEquip);

    //colums to export
    obj.addField(0, "NUMERO", "char(50)");
    obj.addField(1, "TIME", "char(50)");
    obj.addField(2, "TACHE", "char(50)");
    obj.addField(3, "STATUS", "char(50)");
    obj.addField(4, "DATE_C", "char(50)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }

}

void fenetre_equip_course::on_leRechercheCourse_textChanged(const QString &arg1)
{
    recherche(f.afficher(),ui->tabCourse,ui->cbTriCourse,ui->leRechercheCourse);

}

void fenetre_equip_course::on_tabCourse_clicked(const QModelIndex &index)
{
    courseSelectionne=ui->tabCourse->model()->data(index.sibling(index.row(),0)).toString();
    course f;
    f.setNumero(courseSelectionne.toInt());
}

void fenetre_equip_course::on_tabCourse_doubleClicked(const QModelIndex &index)
{
    QSqlQuery query;
   query.prepare("select * from TAB_COURSE where Numero= :num");
   query.bindValue(":num",courseSelectionne);
   if(query.exec())
   {
       while(query.next())
       {

           ui->spNumeroCourse->setValue(query.value(0).toInt());
           ui->cbTimeCourse->setCurrentSectionIndex(0);
           ui->cbTimeCourse->setTime(QTime::fromString(query.value(1).toString(),"hh:mm"));
           ui->leTacheCourse->setText(query.value(2).toString());
           ui->leStatusCourse->setText(query.value(3).toString());
         //  ui->textDateFenetre->setPlainText(query.value(4).toString());
           ui->textDateCourse->setCurrentSectionIndex(0);
           ui->textDateCourse->setDate(QDate::fromString(query.value(4).toString(),"dd/MM/yyyy"));

       }
   }

}

void fenetre_equip_course::on_buttonSupprimerCourse_clicked()
{
    course f;
    QMessageBox msgBox;
    QMessageBox msg;
    if(courseSelectionne=="")
    {
         msgBox.setText("Aucune Course n'est selectionné!");
    }
    else
    {
        msgBox.setText("Voulez vous supprimer la Course "
                       "numéro "+courseSelectionne+" ?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    }

    int rep=msgBox.exec();
    switch(rep)
    {
          case QMessageBox::Yes:

            if (f.supprimer(courseSelectionne.toInt()))
            {
            msg.setText("suppression avec succes.");
            msg.setIcon(QMessageBox::Information);
            proxy2 = new QSortFilterProxyModel();
            proxy2->setSourceModel(f.afficher());
            ui->tabCourse->setModel(proxy2);

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

void fenetre_equip_course::on_buttonModifererCourse_clicked()
{
    int num=ui->spNumeroCourse->value();
    QString time=ui->cbTimeCourse->time().toString("hh:mm");
    QString status=ui->leStatusCourse->text();
    QString tache=ui->leTacheCourse->text();
    QString desc=ui->textDateCourse->date().toString("dd/MM/yyyy");
    course f(num,time,status,tache,desc);

 bool test=f.modifier();
 QMessageBox msg;
 if(test)
 {
     msg.setText("modifier avec succés");
     proxy2 = new QSortFilterProxyModel();
     proxy2->setSourceModel(f.afficher());
     ui->tabCourse->setModel(proxy2);
 }
 else
 {
     msg.setText("echec lors du modification");
 }
 msg.exec();

}

void fenetre_equip_course::on_excel_clicked()
{
    QTableView *table;
                       table = ui->tabEquip;
                       QString filters("CSV files (.csv);;All files (.*)");
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
void fenetre_equip_course::on_PdfCourse_clicked()
{

    QString strStream;
        QTextStream out(&strStream);




        const int rowCount = ui->tabCourse->model()->rowCount();
        const int columnCount = ui->tabCourse->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Portes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabCourse->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabCourse->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabCourse->isColumnHidden(column)) {
                    QString data = ui->tabCourse->model()->data(ui->tabCourse->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
            "</body>\n"
            "</html>\n";

  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

   QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setPaperSize(QPrinter::A4);
  printer.setOutputFileName(fileName);
  QPainter painter;
QImage img("C:/projet-new/projet/logo.png");
painter.drawImage(20,20,img.scaled(325,259));
   QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
void fenetre_equip_course::on_PdfEquip_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabEquip->model()->rowCount();
        const int columnCount = ui->tabEquip->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Portes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabEquip->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabEquip->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabEquip->isColumnHidden(column)) {
                    QString data = ui->tabEquip->model()->data(ui->tabEquip->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
            "</body>\n"
            "</html>\n";

  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

   QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setPaperSize(QPrinter::A4);
  printer.setOutputFileName(fileName);

   QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
//traduction//////
void fenetre_equip_course::on_checkBox_traduction_arabe_clicked()
{
    if (ui->checkBox_traduction_arabe->isChecked())
        {

        ui->tabWidget->setTabText(0,"المعدات");
        ui->tabWidget->setTabText(1,"المهام");


        ui->label_num_course->setText( tr("رقم المهمة"));

ui->label_tem_course->setText( tr("وقت المهمة"));
ui->label_tache_course->setText( tr("محتوى المهمة"));
ui->label_status_course->setText( tr("حالة المهمة"));
ui->label_date_course->setText( tr("تاريخ المهمة"));
ui->buttonAjouterCourse->setText( tr("أضف"));
ui->buttonModifererCourse->setText( tr("تغيير"));
ui->buttonSupprimerCourse->setText( tr("حذف"));
//ui->PdfCourse->setText( tr("رقم المهمة"));
//ui->ButtonExcelCourse->setText( tr("رقم المهمة"));


    }

    else
    {
ui->tabWidget->setTabText(0,"equipement");

        ui->tabWidget->setTabText(1,"Course");



        ui->label_num_course->setText( tr("Numero de la course"));
        ui->label_tem_course->setText( tr("temp de la course"));
        ui->label_tache_course->setText( tr("tache de la course"));
        ui->label_status_course->setText( tr("status de la course"));
        ui->label_date_course->setText( tr("date"));
        ui->buttonAjouterCourse->setText( tr("ajouter"));
        ui->buttonModifererCourse->setText( tr("modifier"));
        ui->buttonSupprimerCourse->setText( tr("supprimer"));
        //ui->PdfCourse->setText( tr("رقم المهمة"));
        //ui->ButtonExcelCourse->setText( tr("رقم المهمة"));


    }

}

void fenetre_equip_course::on_pushButton_Stat_clicked()
{
    statistique s;
      s.exec();
}


