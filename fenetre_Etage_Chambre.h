#ifndef FENETRE_ETAGE_CHAMBRE_H
#define FENETRE_ETAGE_CHAMBRE_H

#include <QDialog>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QMessageBox>
#include "Etages.h"
#include "chambres.h"
#include <QDialog>
#include <QFileDialog>

namespace Ui {
class EtageChambre;
}

class EtageChambre : public QDialog
{
    Q_OBJECT

public:
    explicit EtageChambre(QWidget *parent = nullptr);

    void recherche(QSqlQueryModel*,QTableView *, QComboBox * , QLineEdit * );
    ~EtageChambre();

private slots:
    void on_buttonAjouterEtages_clicked();

    void on_tabEtages_doubleClicked(const QModelIndex &index);

    void on_leRecherche_textChanged(const QString &arg1);

    void on_buttonSupprimerEtages_clicked();

    void on_tabEtages_clicked(const QModelIndex &index);

    void on_buttonModifererEtages_clicked();

    void on_ButtonExcel_clicked();

    void on_buttonAjouterChambres_clicked();

    void on_ButtonExcelChambres_clicked();

    void on_leRechercheChambres_textChanged(const QString &arg1);

    void on_tabChambres_clicked(const QModelIndex &index);

    void on_tabChambres_doubleClicked(const QModelIndex &index);

    void on_buttonSupprimerChambres_clicked();

    void on_buttonModifererChambres_clicked();

    void on_PDFChambre_clicked();

private:
    Ui::EtageChambre *ui;
    Etages p;
    Chambres f;
    QSortFilterProxyModel *proxy;
    QSortFilterProxyModel *proxy2;
    QString EtagesSelectionne;
    QString ChambresSelectionne;

};

#endif // FENETRE_ETAGE_CHAMBRE_H
