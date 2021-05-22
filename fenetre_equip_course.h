#ifndef FENETRE_EQUIP_COURSE_H
#define FENETRE_EQUIP_COURSE_H

#include <QDialog>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QMessageBox>
#include "equipement.h"
#include "course.h"
#include <QDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
namespace Ui {
class fenetre_equip_course;
}

class fenetre_equip_course : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre_equip_course(QWidget *parent = nullptr);

    void recherche(QSqlQueryModel*,QTableView *, QComboBox * , QLineEdit * );
    ~fenetre_equip_course();

private slots:
    void on_buttonAjouterEquip_clicked();

    void on_tabEquip_doubleClicked(const QModelIndex &index);

    void on_leRecherche_textChanged(const QString &arg1);

    void on_buttonSupprimerEquip_clicked();

    void on_tabEquip_clicked(const QModelIndex &index);

    void on_buttonModifererEquip_clicked();

    void on_ButtonExcel_clicked();

    void on_buttonAjouterCourse_clicked();

    void on_ButtonExcelCourse_clicked();

    void on_leRechercheCourse_textChanged(const QString &arg1);

    void on_tabCourse_clicked(const QModelIndex &index);

    void on_tabCourse_doubleClicked(const QModelIndex &index);

    void on_buttonSupprimerCourse_clicked();

    void on_buttonModifererCourse_clicked();
   void  on_excel_clicked();

   void on_leRecherche_cursorPositionChanged(int arg1, int arg2);

   void on_cbTri_textActivated(const QString &arg1);
   void on_PdfCourse_clicked();
void on_PdfEquip_clicked();
void on_checkBox_traduction_arabe_clicked();
void on_pushButton_Stat_clicked();



private:
    Ui::fenetre_equip_course *ui;
    equipement p;
    course f;
    QSortFilterProxyModel *proxy;
    QSortFilterProxyModel *proxy2;
    QString EquipSelectionne;
    QString courseSelectionne;

};

#endif // FENETRE_EQUIP_COURSE_H
