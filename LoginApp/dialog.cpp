#include<QMessageBox>
#include"mainwindow.h"
#include "emission.h"
#include<QMovie>
#include "emissions.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "QDate"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

//    QMovie *movie = new QMovie(":/img/profile.gif");
//   // QLabel *processLabel = new QLabel(this);
//   // ui->label_2->setGeometry(100,100,100,100);
//    ui->emission_button->setMovie(movie);
//    movie->start();

    QMovie *movie1 = new QMovie(":/img/giphy (2) (1).gif");
   // QLabel *processLabel = new QLabel(this);
   // ui->label_2->setGeometry(100,100,100,100);
    ui->label_8->setMovie(movie1);
    movie1->start();
    ui->tableView_emission->setModel(E3.afficher());


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_emission_button_clicked()
{
    ui->menu_stacked_widget->setCurrentIndex(1);
}

void Dialog::on_pushButton_invite_clicked()
{
     ui->menu_stacked_widget->setCurrentIndex(2);
}

void Dialog::setcompte(compte c)
{
    ui->lineEdit_compte->setText(c.getcompte());
}

void Dialog::on_next_crud_clicked()
{
    ui->stackedWidget_crud->setCurrentIndex(1);
}

void Dialog::on_next_crud_2_clicked()
{
    ui->stackedWidget_crud->setCurrentIndex(0);
}

void Dialog::on_pushButton_next_crude_guest_clicked()
{
     ui->stackedWidget_guest->setCurrentIndex(1);
}

void Dialog::on_pushButton_previous_crud_guest_clicked()
{
     ui->stackedWidget_guest->setCurrentIndex(0);
}


void Dialog::on_pushButton_add_emission_clicked()
{
    int ID_EMISSION=ui->add_emission_id->text().toInt();
    QString NOM_EMISSION=ui->add_emission_name->text();
//    QString TYPE_EMISSION=ui->type->text();
//    QString DUREE_EMISSION=ui->duree->text();
//    QString DATE_EMISSION=ui->date->text();

    QString TYPE_EMISSION;
    QString DUREE_EMISSION;


    if(ui->add_emission_type_fun->isChecked())
    {
     TYPE_EMISSION="fun";
    }
    else if(ui->add_emission_type_info->isChecked())
    {
     TYPE_EMISSION="info";
    }
    else if(ui->add_emission_type_sport->isChecked())
    {
    TYPE_EMISSION="sport";
    }


    if(ui->add_emission_duration_5->isChecked())
    {
     DUREE_EMISSION="5mn";
    }
    else if(ui->add_emission_duration_10->isChecked())
    {
     DUREE_EMISSION="10mn";
    }
    else if(ui->add_emission_duration_15->isChecked())
    {
     DUREE_EMISSION="15mn";
    }

    QDate date = ui->dateTimeEdit->date();
    QString DATE_EMISSION = date.toString();


  EMISSIONS E(ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION);


  bool test=E.ajouter();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("ajout effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("ajout non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



        ui->add_emission_id->setText("");
        ui->add_emission_name->setText("");
  }



void Dialog::on_delete_emission_clicked()
{
    EMISSIONS E1;

        E1.setid (ui->lineEdit_8->text().toInt());

        bool test=E1.supprimer(E1.getid());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }


void Dialog::on_refresh_clicked()
{
    ui->tableView_emission->setModel(E3.afficher());
}

void Dialog::on_pushButton_update_clicked()
{

    int ID_EMISSION=ui->update_id->text().toInt();
    QString NOM_EMISSION=ui->update_emission_name->text();
//    QString TYPE_EMISSION=ui->type->text();
//    QString DUREE_EMISSION=ui->duree->text();
//    QString DATE_EMISSION=ui->date->text();

    QString TYPE_EMISSION;
    QString DUREE_EMISSION;


    if(ui->update_fun->isChecked())
    {
     TYPE_EMISSION="fun";
    }
    else if(ui->update_info->isChecked())
    {
     TYPE_EMISSION="info";
    }
    else if(ui->update_sport->isChecked())
    {
    TYPE_EMISSION="sport";
    }


    if(ui->update_duration_5->isChecked())
    {
     DUREE_EMISSION="5mn";
    }
    else if(ui->update_duration_10->isChecked())
    {
     DUREE_EMISSION="10mn";
    }
    else if(ui->update_duration_15->isChecked())
    {
     DUREE_EMISSION="15mn";
    }

    QDate date = ui->dateTimeEdit_2->date();
    QString DATE_EMISSION = date.toString();


  EMISSIONS E1(ID_EMISSION,NOM_EMISSION,TYPE_EMISSION,DUREE_EMISSION,DATE_EMISSION);

  bool test=E1.update();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                       QObject::tr("update effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                       QObject::tr("update non effectue.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);




  }

