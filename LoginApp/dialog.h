#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "compte.h"
#include "emissions.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setcompte(compte c);
    ~Dialog();

private slots:


    void on_emission_button_clicked();

    void on_pushButton_invite_clicked();

    void on_next_crud_clicked();

    void on_next_crud_2_clicked();

    void on_pushButton_next_crude_guest_clicked();

    void on_pushButton_previous_crud_guest_clicked();



    void on_pushButton_add_emission_clicked();

    void on_delete_emission_clicked();



    void on_refresh_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::Dialog *ui;
    EMISSIONS E3;
};

#endif // DIALOG_H
