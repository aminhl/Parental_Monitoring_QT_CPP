#include "statistique.h"
#include "ui_statistique.h"
//#include"ui_dialog.h"
#include<iostream>
#include<QPainter>
#include<QPrinter>
statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
/*int statistique::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from TAB_COURSE where STATUS ='done'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}*/

int statistique::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from TAB_COURSE where STATUS ='done'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}
int statistique::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from TAB_COURSE where  STATUS ='not done'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

void statistique::paintEvent(QPaintEvent *)
{

    //int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= d*100 ;
        float s3=c*100;
        float nb = d+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    //painter.setBrush(Qt::blue);
    //painter.drawPie(size,0,16*y);
  //  ui->label_2->setText(" Course done") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText(" Course done") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("Course not done") ;

}
void statistique::on_pushButton_clicked()
{
    hide();
}
