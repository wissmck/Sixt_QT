#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QString>
#include "popup.h"
#include "agence.h"
#include "personnel.h"
#include "smtp.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*bool isCharacter(const char Character);
    bool isNumber(const char Character);
    bool isValidEmailAddress(const char * EmailAddress);*/
    QString text;

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_table_personnel_activated(const QModelIndex &index);

    void on_pushButton_supprimer_clicked();

    void on_pushButton_afficher_clicked();

    void on_id_2_textEdited();

    void on_id_3_textEdited();

    void on_pushButton_triasc_clicked();

    void on_pushButton_trides_clicked();

    void on_pushButton_ajouter2_clicked();

    void on_pushButton_modifier2_clicked();

    void on_pushButton_supprimer2_clicked();

    void on_pushButton_afficher2_clicked();

    void on_pushButton_rechercher2_clicked();

    void on_pushButton_triasc2_clicked();

    void on_pushButton_trides2_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_actualiser2_clicked();

private:
    Ui::MainWindow *ui;
    popup *popUp;
    Agence agence;
    Personnel personnel;
    QDate dateSystem;
};

#endif // MAINWINDOW_H
