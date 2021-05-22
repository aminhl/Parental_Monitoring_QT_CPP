/********************************************************************************
** Form generated from reading UI file 'LoisirDevoir.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOISIRDEVOIR_H
#define UI_LOISIRDEVOIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoisirDevoir
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QLabel *NumDevoir;
    QLabel *DiffDevoir;
    QLineEdit *StatutDev;
    QLabel *StatutDevoir;
    QLabel *DateDevoir;
    QLabel *TacheDevoir;
    QLineEdit *TacheDev;
    QSpinBox *NumeroDev;
    QComboBox *DiffDev;
    QTextEdit *DateDev;
    QLineEdit *leRecherche;
    QPushButton *buttonAjouterDevoir;
    QPushButton *buttonSupprimerDevoir;
    QTableView *tabDevoir;
    QPushButton *buttonModifererDevoir;
    QComboBox *cbTriDevoir;
    QPushButton *DevoirVideo;
    QLabel *label_date_time;
    QRadioButton *TradEngDev;
    QRadioButton *TradFrDev;
    QRadioButton *TradGerDev;
    QPushButton *DvExl;
    QWidget *tab_2;
    QStackedWidget *stackedWidget_2;
    QWidget *afficherCarteFid;
    QTableView *tabCarteFid;
    QLineEdit *le_recherche_carteFid;
    QComboBox *cb_colone_carteFid;
    QPushButton *button_ajouter_carteFid;
    QPushButton *button_supprimer_carteFid;
    QPushButton *pushButton_4;
    QWidget *ajoutClient_2;
    QDialogButtonBox *validerAjout_cf;
    QWidget *modifierClient_2;
    QDialogButtonBox *validerModif_cf;
    QComboBox *cbTriLoisir;
    QGroupBox *groupBox_7;
    QLabel *NumLoisir;
    QLabel *TypeLoisir;
    QLineEdit *DateLois;
    QLabel *DateLoisir;
    QLabel *label_46;
    QLabel *DureeLoisir;
    QLabel *LieuLoisir;
    QLineEdit *LieuLois;
    QSpinBox *NumeroLois;
    QComboBox *TypeLois;
    QTextEdit *DureeLois;
    QPushButton *buttonModifererLoisir;
    QPushButton *buttonSupprimerLoisir;
    QLineEdit *leRechercheLoisir;
    QPushButton *buttonAjouterLoisir;
    QTableView *tabLoisir;
    QPushButton *PdfLoisir;
    QPushButton *ImprimerLoisir;
    QRadioButton *TradEngLois;
    QRadioButton *TradFrLois;
    QRadioButton *TradGerLois;
    QPushButton *LoisXl;

    void setupUi(QDialog *LoisirDevoir)
    {
        if (LoisirDevoir->objectName().isEmpty())
            LoisirDevoir->setObjectName(QString::fromUtf8("LoisirDevoir"));
        LoisirDevoir->resize(799, 513);
        tabWidget = new QTabWidget(LoisirDevoir);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 761, 481));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 351, 351));
        NumDevoir = new QLabel(groupBox_4);
        NumDevoir->setObjectName(QString::fromUtf8("NumDevoir"));
        NumDevoir->setGeometry(QRect(30, 30, 111, 51));
        DiffDevoir = new QLabel(groupBox_4);
        DiffDevoir->setObjectName(QString::fromUtf8("DiffDevoir"));
        DiffDevoir->setGeometry(QRect(30, 100, 171, 20));
        StatutDev = new QLineEdit(groupBox_4);
        StatutDev->setObjectName(QString::fromUtf8("StatutDev"));
        StatutDev->setGeometry(QRect(160, 160, 121, 21));
        StatutDevoir = new QLabel(groupBox_4);
        StatutDevoir->setObjectName(QString::fromUtf8("StatutDevoir"));
        StatutDevoir->setGeometry(QRect(30, 160, 131, 16));
        DateDevoir = new QLabel(groupBox_4);
        DateDevoir->setObjectName(QString::fromUtf8("DateDevoir"));
        DateDevoir->setGeometry(QRect(30, 280, 81, 16));
        TacheDevoir = new QLabel(groupBox_4);
        TacheDevoir->setObjectName(QString::fromUtf8("TacheDevoir"));
        TacheDevoir->setGeometry(QRect(30, 220, 101, 20));
        TacheDev = new QLineEdit(groupBox_4);
        TacheDev->setObjectName(QString::fromUtf8("TacheDev"));
        TacheDev->setGeometry(QRect(160, 220, 121, 22));
        NumeroDev = new QSpinBox(groupBox_4);
        NumeroDev->setObjectName(QString::fromUtf8("NumeroDev"));
        NumeroDev->setGeometry(QRect(160, 50, 121, 21));
        NumeroDev->setMinimum(0);
        NumeroDev->setMaximum(9999);
        NumeroDev->setValue(0);
        DiffDev = new QComboBox(groupBox_4);
        DiffDev->addItem(QString());
        DiffDev->addItem(QString());
        DiffDev->addItem(QString());
        DiffDev->setObjectName(QString::fromUtf8("DiffDev"));
        DiffDev->setGeometry(QRect(160, 100, 121, 22));
        DateDev = new QTextEdit(groupBox_4);
        DateDev->setObjectName(QString::fromUtf8("DateDev"));
        DateDev->setGeometry(QRect(160, 280, 131, 31));
        leRecherche = new QLineEdit(tab);
        leRecherche->setObjectName(QString::fromUtf8("leRecherche"));
        leRecherche->setGeometry(QRect(600, 10, 111, 22));
        buttonAjouterDevoir = new QPushButton(tab);
        buttonAjouterDevoir->setObjectName(QString::fromUtf8("buttonAjouterDevoir"));
        buttonAjouterDevoir->setGeometry(QRect(10, 370, 81, 31));
        buttonSupprimerDevoir = new QPushButton(tab);
        buttonSupprimerDevoir->setObjectName(QString::fromUtf8("buttonSupprimerDevoir"));
        buttonSupprimerDevoir->setGeometry(QRect(200, 370, 71, 31));
        tabDevoir = new QTableView(tab);
        tabDevoir->setObjectName(QString::fromUtf8("tabDevoir"));
        tabDevoir->setGeometry(QRect(370, 50, 341, 301));
        tabDevoir->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabDevoir->setSortingEnabled(true);
        buttonModifererDevoir = new QPushButton(tab);
        buttonModifererDevoir->setObjectName(QString::fromUtf8("buttonModifererDevoir"));
        buttonModifererDevoir->setGeometry(QRect(110, 370, 75, 31));
        cbTriDevoir = new QComboBox(tab);
        cbTriDevoir->addItem(QString());
        cbTriDevoir->addItem(QString());
        cbTriDevoir->addItem(QString());
        cbTriDevoir->addItem(QString());
        cbTriDevoir->addItem(QString());
        cbTriDevoir->addItem(QString());
        cbTriDevoir->setObjectName(QString::fromUtf8("cbTriDevoir"));
        cbTriDevoir->setGeometry(QRect(480, 10, 111, 22));
        DevoirVideo = new QPushButton(tab);
        DevoirVideo->setObjectName(QString::fromUtf8("DevoirVideo"));
        DevoirVideo->setGeometry(QRect(10, 410, 81, 28));
        label_date_time = new QLabel(tab);
        label_date_time->setObjectName(QString::fromUtf8("label_date_time"));
        label_date_time->setGeometry(QRect(420, 360, 331, 81));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_date_time->setFont(font);
        TradEngDev = new QRadioButton(tab);
        TradEngDev->setObjectName(QString::fromUtf8("TradEngDev"));
        TradEngDev->setGeometry(QRect(110, 410, 95, 20));
        TradFrDev = new QRadioButton(tab);
        TradFrDev->setObjectName(QString::fromUtf8("TradFrDev"));
        TradFrDev->setGeometry(QRect(190, 410, 95, 20));
        TradGerDev = new QRadioButton(tab);
        TradGerDev->setObjectName(QString::fromUtf8("TradGerDev"));
        TradGerDev->setGeometry(QRect(270, 410, 95, 20));
        DvExl = new QPushButton(tab);
        DvExl->setObjectName(QString::fromUtf8("DvExl"));
        DvExl->setGeometry(QRect(280, 370, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        stackedWidget_2 = new QStackedWidget(tab_2);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(20, 0, 771, 531));
        afficherCarteFid = new QWidget();
        afficherCarteFid->setObjectName(QString::fromUtf8("afficherCarteFid"));
        tabCarteFid = new QTableView(afficherCarteFid);
        tabCarteFid->setObjectName(QString::fromUtf8("tabCarteFid"));
        tabCarteFid->setGeometry(QRect(10, 80, 741, 361));
        tabCarteFid->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabCarteFid->setSortingEnabled(true);
        le_recherche_carteFid = new QLineEdit(afficherCarteFid);
        le_recherche_carteFid->setObjectName(QString::fromUtf8("le_recherche_carteFid"));
        le_recherche_carteFid->setGeometry(QRect(560, 40, 191, 22));
        cb_colone_carteFid = new QComboBox(afficherCarteFid);
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->addItem(QString());
        cb_colone_carteFid->setObjectName(QString::fromUtf8("cb_colone_carteFid"));
        cb_colone_carteFid->setGeometry(QRect(360, 40, 191, 22));
        button_ajouter_carteFid = new QPushButton(afficherCarteFid);
        button_ajouter_carteFid->setObjectName(QString::fromUtf8("button_ajouter_carteFid"));
        button_ajouter_carteFid->setGeometry(QRect(10, 470, 131, 31));
        button_supprimer_carteFid = new QPushButton(afficherCarteFid);
        button_supprimer_carteFid->setObjectName(QString::fromUtf8("button_supprimer_carteFid"));
        button_supprimer_carteFid->setGeometry(QRect(160, 470, 131, 31));
        pushButton_4 = new QPushButton(afficherCarteFid);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(620, 470, 131, 31));
        stackedWidget_2->addWidget(afficherCarteFid);
        ajoutClient_2 = new QWidget();
        ajoutClient_2->setObjectName(QString::fromUtf8("ajoutClient_2"));
        validerAjout_cf = new QDialogButtonBox(ajoutClient_2);
        validerAjout_cf->setObjectName(QString::fromUtf8("validerAjout_cf"));
        validerAjout_cf->setGeometry(QRect(570, 500, 193, 28));
        validerAjout_cf->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget_2->addWidget(ajoutClient_2);
        modifierClient_2 = new QWidget();
        modifierClient_2->setObjectName(QString::fromUtf8("modifierClient_2"));
        validerModif_cf = new QDialogButtonBox(modifierClient_2);
        validerModif_cf->setObjectName(QString::fromUtf8("validerModif_cf"));
        validerModif_cf->setGeometry(QRect(570, 500, 193, 28));
        validerModif_cf->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        cbTriLoisir = new QComboBox(modifierClient_2);
        cbTriLoisir->addItem(QString());
        cbTriLoisir->addItem(QString());
        cbTriLoisir->addItem(QString());
        cbTriLoisir->addItem(QString());
        cbTriLoisir->addItem(QString());
        cbTriLoisir->addItem(QString());
        cbTriLoisir->setObjectName(QString::fromUtf8("cbTriLoisir"));
        cbTriLoisir->setGeometry(QRect(450, 20, 111, 22));
        groupBox_7 = new QGroupBox(modifierClient_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 20, 351, 351));
        NumLoisir = new QLabel(groupBox_7);
        NumLoisir->setObjectName(QString::fromUtf8("NumLoisir"));
        NumLoisir->setGeometry(QRect(30, 30, 111, 51));
        TypeLoisir = new QLabel(groupBox_7);
        TypeLoisir->setObjectName(QString::fromUtf8("TypeLoisir"));
        TypeLoisir->setGeometry(QRect(30, 100, 171, 20));
        DateLois = new QLineEdit(groupBox_7);
        DateLois->setObjectName(QString::fromUtf8("DateLois"));
        DateLois->setGeometry(QRect(160, 160, 121, 21));
        DateLoisir = new QLabel(groupBox_7);
        DateLoisir->setObjectName(QString::fromUtf8("DateLoisir"));
        DateLoisir->setGeometry(QRect(30, 160, 131, 16));
        label_46 = new QLabel(groupBox_7);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(30, 300, 55, 21));
        DureeLoisir = new QLabel(groupBox_7);
        DureeLoisir->setObjectName(QString::fromUtf8("DureeLoisir"));
        DureeLoisir->setGeometry(QRect(30, 280, 91, 16));
        LieuLoisir = new QLabel(groupBox_7);
        LieuLoisir->setObjectName(QString::fromUtf8("LieuLoisir"));
        LieuLoisir->setGeometry(QRect(30, 220, 111, 20));
        LieuLois = new QLineEdit(groupBox_7);
        LieuLois->setObjectName(QString::fromUtf8("LieuLois"));
        LieuLois->setGeometry(QRect(160, 220, 121, 22));
        NumeroLois = new QSpinBox(groupBox_7);
        NumeroLois->setObjectName(QString::fromUtf8("NumeroLois"));
        NumeroLois->setGeometry(QRect(160, 50, 121, 21));
        NumeroLois->setMinimum(0);
        NumeroLois->setMaximum(9999);
        NumeroLois->setValue(0);
        TypeLois = new QComboBox(groupBox_7);
        TypeLois->addItem(QString());
        TypeLois->addItem(QString());
        TypeLois->setObjectName(QString::fromUtf8("TypeLois"));
        TypeLois->setGeometry(QRect(160, 100, 121, 22));
        DureeLois = new QTextEdit(groupBox_7);
        DureeLois->setObjectName(QString::fromUtf8("DureeLois"));
        DureeLois->setGeometry(QRect(160, 280, 131, 31));
        buttonModifererLoisir = new QPushButton(modifierClient_2);
        buttonModifererLoisir->setObjectName(QString::fromUtf8("buttonModifererLoisir"));
        buttonModifererLoisir->setGeometry(QRect(100, 380, 75, 31));
        buttonSupprimerLoisir = new QPushButton(modifierClient_2);
        buttonSupprimerLoisir->setObjectName(QString::fromUtf8("buttonSupprimerLoisir"));
        buttonSupprimerLoisir->setGeometry(QRect(190, 380, 71, 31));
        leRechercheLoisir = new QLineEdit(modifierClient_2);
        leRechercheLoisir->setObjectName(QString::fromUtf8("leRechercheLoisir"));
        leRechercheLoisir->setGeometry(QRect(570, 20, 111, 22));
        buttonAjouterLoisir = new QPushButton(modifierClient_2);
        buttonAjouterLoisir->setObjectName(QString::fromUtf8("buttonAjouterLoisir"));
        buttonAjouterLoisir->setGeometry(QRect(0, 380, 81, 31));
        tabLoisir = new QTableView(modifierClient_2);
        tabLoisir->setObjectName(QString::fromUtf8("tabLoisir"));
        tabLoisir->setGeometry(QRect(360, 60, 341, 301));
        tabLoisir->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabLoisir->setSortingEnabled(true);
        PdfLoisir = new QPushButton(modifierClient_2);
        PdfLoisir->setObjectName(QString::fromUtf8("PdfLoisir"));
        PdfLoisir->setGeometry(QRect(0, 420, 81, 31));
        ImprimerLoisir = new QPushButton(modifierClient_2);
        ImprimerLoisir->setObjectName(QString::fromUtf8("ImprimerLoisir"));
        ImprimerLoisir->setGeometry(QRect(100, 420, 71, 31));
        TradEngLois = new QRadioButton(modifierClient_2);
        TradEngLois->setObjectName(QString::fromUtf8("TradEngLois"));
        TradEngLois->setGeometry(QRect(190, 425, 95, 20));
        TradFrLois = new QRadioButton(modifierClient_2);
        TradFrLois->setObjectName(QString::fromUtf8("TradFrLois"));
        TradFrLois->setGeometry(QRect(270, 425, 95, 20));
        TradGerLois = new QRadioButton(modifierClient_2);
        TradGerLois->setObjectName(QString::fromUtf8("TradGerLois"));
        TradGerLois->setGeometry(QRect(350, 425, 95, 20));
        LoisXl = new QPushButton(modifierClient_2);
        LoisXl->setObjectName(QString::fromUtf8("LoisXl"));
        LoisXl->setGeometry(QRect(270, 380, 93, 31));
        stackedWidget_2->addWidget(modifierClient_2);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(LoisirDevoir);

        tabWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(LoisirDevoir);
    } // setupUi

    void retranslateUi(QDialog *LoisirDevoir)
    {
        LoisirDevoir->setWindowTitle(QCoreApplication::translate("LoisirDevoir", "Dialog", nullptr));
        groupBox_4->setTitle(QString());
        NumDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Num\303\251ro Devoir :", nullptr));
        DiffDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Difficult\303\251 Devoir :", nullptr));
        StatutDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Statut Devoir :", nullptr));
        DateDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Date Devoir :", nullptr));
        TacheDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Tache Devoir :", nullptr));
        DiffDev->setItemText(0, QCoreApplication::translate("LoisirDevoir", "Facile", nullptr));
        DiffDev->setItemText(1, QCoreApplication::translate("LoisirDevoir", "Moyen", nullptr));
        DiffDev->setItemText(2, QCoreApplication::translate("LoisirDevoir", "Difficile", nullptr));

        leRecherche->setPlaceholderText(QCoreApplication::translate("LoisirDevoir", "recherche", nullptr));
        buttonAjouterDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Ajouter", nullptr));
        buttonSupprimerDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Supprimer", nullptr));
        buttonModifererDevoir->setText(QCoreApplication::translate("LoisirDevoir", "Modifer", nullptr));
        cbTriDevoir->setItemText(0, QCoreApplication::translate("LoisirDevoir", "Tous", nullptr));
        cbTriDevoir->setItemText(1, QCoreApplication::translate("LoisirDevoir", "Numero Devoir", nullptr));
        cbTriDevoir->setItemText(2, QCoreApplication::translate("LoisirDevoir", "Difficult\303\251 Devoir", nullptr));
        cbTriDevoir->setItemText(3, QCoreApplication::translate("LoisirDevoir", "Statut Devoir", nullptr));
        cbTriDevoir->setItemText(4, QCoreApplication::translate("LoisirDevoir", "Tache Devoir", nullptr));
        cbTriDevoir->setItemText(5, QCoreApplication::translate("LoisirDevoir", "Date Devoir", nullptr));

        DevoirVideo->setText(QCoreApplication::translate("LoisirDevoir", "Video", nullptr));
        label_date_time->setText(QString());
        TradEngDev->setText(QCoreApplication::translate("LoisirDevoir", "English", nullptr));
        TradFrDev->setText(QCoreApplication::translate("LoisirDevoir", "French", nullptr));
        TradGerDev->setText(QCoreApplication::translate("LoisirDevoir", "Deutsch", nullptr));
        DvExl->setText(QCoreApplication::translate("LoisirDevoir", "Excel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoisirDevoir", "Devoir", nullptr));
        le_recherche_carteFid->setPlaceholderText(QCoreApplication::translate("LoisirDevoir", "recherche", nullptr));
        cb_colone_carteFid->setItemText(0, QCoreApplication::translate("LoisirDevoir", "Tous", nullptr));
        cb_colone_carteFid->setItemText(1, QCoreApplication::translate("LoisirDevoir", "NUM_CARTE", nullptr));
        cb_colone_carteFid->setItemText(2, QCoreApplication::translate("LoisirDevoir", "DATE_DE_CREATION", nullptr));
        cb_colone_carteFid->setItemText(3, QCoreApplication::translate("LoisirDevoir", "POINTS", nullptr));
        cb_colone_carteFid->setItemText(4, QCoreApplication::translate("LoisirDevoir", "TOTAL_ACHATS", nullptr));
        cb_colone_carteFid->setItemText(5, QCoreApplication::translate("LoisirDevoir", "STATUT", nullptr));
        cb_colone_carteFid->setItemText(6, QCoreApplication::translate("LoisirDevoir", "REMISE", nullptr));
        cb_colone_carteFid->setItemText(7, QCoreApplication::translate("LoisirDevoir", "MATRICULE_FISCALE", nullptr));

        button_ajouter_carteFid->setText(QCoreApplication::translate("LoisirDevoir", "Ajouter", nullptr));
        button_supprimer_carteFid->setText(QCoreApplication::translate("LoisirDevoir", "Supprimer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LoisirDevoir", "Retour", nullptr));
        cbTriLoisir->setItemText(0, QCoreApplication::translate("LoisirDevoir", "Tous", nullptr));
        cbTriLoisir->setItemText(1, QCoreApplication::translate("LoisirDevoir", "Num\303\251ro Loisir", nullptr));
        cbTriLoisir->setItemText(2, QCoreApplication::translate("LoisirDevoir", "Type Loisir", nullptr));
        cbTriLoisir->setItemText(3, QCoreApplication::translate("LoisirDevoir", "Date Loisir", nullptr));
        cbTriLoisir->setItemText(4, QCoreApplication::translate("LoisirDevoir", "Lieu Loisir", nullptr));
        cbTriLoisir->setItemText(5, QCoreApplication::translate("LoisirDevoir", "Duree Loisir", nullptr));

        groupBox_7->setTitle(QString());
        NumLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Num\303\251ro Loisir :", nullptr));
        TypeLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Type Loisir :", nullptr));
        DateLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Date Loisir :", nullptr));
        label_46->setText(QString());
        DureeLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Duree Loisir  : ", nullptr));
        LieuLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Lieu Loisir :", nullptr));
        TypeLois->setItemText(0, QCoreApplication::translate("LoisirDevoir", "Ouverte", nullptr));
        TypeLois->setItemText(1, QCoreApplication::translate("LoisirDevoir", "Fermee", nullptr));

        buttonModifererLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Modifer", nullptr));
        buttonSupprimerLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Supprimer", nullptr));
        leRechercheLoisir->setPlaceholderText(QCoreApplication::translate("LoisirDevoir", "recherche", nullptr));
        buttonAjouterLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Ajouter", nullptr));
        PdfLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Pdf Loisir", nullptr));
        ImprimerLoisir->setText(QCoreApplication::translate("LoisirDevoir", "Imp", nullptr));
        TradEngLois->setText(QCoreApplication::translate("LoisirDevoir", "English", nullptr));
        TradFrLois->setText(QCoreApplication::translate("LoisirDevoir", "Fran\303\247ais", nullptr));
        TradGerLois->setText(QCoreApplication::translate("LoisirDevoir", "Deutsch", nullptr));
        LoisXl->setText(QCoreApplication::translate("LoisirDevoir", "Excel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoisirDevoir", "Loisir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoisirDevoir: public Ui_LoisirDevoir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOISIRDEVOIR_H
