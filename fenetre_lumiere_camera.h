#ifndef FENETRE_LUMIERE_CAMERA_H
#define FENETRE_LUMIERE_CAMERA_H

#include <QDialog>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QMessageBox>
#include "lumiere.h"
#include "camera.h"
#include <QDialog>
#include <QFileDialog>

namespace Ui {
class lumCam;
}

class lumCam : public QDialog
{
    Q_OBJECT

public:
    explicit lumCam(QWidget *parent = nullptr);

    void recherche(QSqlQueryModel*,QTableView *, QComboBox * , QLineEdit * );
    ~lumCam();

private slots:
    void on_buttonAjouterlumiere_clicked();

    void on_tablumiere_doubleClicked(const QModelIndex &index);

    void on_leRecherche_textChanged(const QString &arg1);

    void on_buttonSupprimerlumiere_clicked();

    void on_tablumiere_clicked(const QModelIndex &index);

    void on_buttonModifererlumiere_clicked();

    void on_ButtonExcel_clicked();

    void on_buttonAjouterCamera_clicked();

    void on_ButtonExcelCamera_clicked();

    void on_leRechercheCamera_textChanged(const QString &arg1);

    void on_tabCamera_clicked(const QModelIndex &index);

    void on_tabCamera_doubleClicked(const QModelIndex &index);

    void on_buttonSupprimerCamera_clicked();

    void on_buttonModifererCamera_clicked();



    void on_buttonSupprimerCamera_2_clicked();

    void on_buttonSupprimerlumiere_2_clicked();

private:
    Ui::lumCam *ui;
    Lumiere p;
    Camera f;
    QSortFilterProxyModel *proxy;
    QSortFilterProxyModel *proxy2;
    QString lumiereSelectionne;
    QString cameraSelectionne;

};

#endif // FENETRE_LUMIERE_CAMERA_H
