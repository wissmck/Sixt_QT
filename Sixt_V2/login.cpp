#include "login.h"
#include "connexion.h"
#include <QPixmap>
#include <QTimer>
#include <QDate>
#include <QString>
#include "ui_login.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    /* The first step is to create an object for the database
         * and initialize the database connection
         * */
        db = new DataBase();
        db->connectToDataBase();
    ui->setupUi(this);


    QPixmap logo(":/src/img/src/img/logo.png");
    QPixmap shutdown(":/src/img/src/img/off.png");
    QPixmap restart(":/src/img/src/img/restart.png");



    ui->currentDateTime->setText(QDate::currentDate().toString());

    QTimer *timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(UpadateTime()));
        timer->start(1000);


    ui->restart->setFlat(true);
    ui->restart->setFocusPolicy(Qt::NoFocus);
    ui->restart->setIcon(restart);
    ui->restart->setIconSize(QSize(40,40));
    ui->restart->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    ui->shutDown->setFlat(true);
    ui->shutDown->setFocusPolicy(Qt::NoFocus);
    ui->shutDown->setIcon(shutdown);
    ui->shutDown->setIconSize(QSize(40,40));
    ui->shutDown->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    ui->logo->setPixmap(logo.scaled(150,150,Qt::KeepAspectRatio));
    ui->userPassword->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connexion_clicked()
{


    if(Login(ui->userName->text(), ui->userPassword->text()))
    {

        this->userName = ui->userName->text();
        this->password = ui->userPassword->text();
        this->loggedIn = true;
        close();
        mainwindow = new MainWindow(this);
        mainwindow->setNomAgent(userName);
        /*mainwindow->setWindowFlags(mainwindow->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
        mainwindow->setWindowState(mainwindow->windowState() | Qt::WindowFullScreen);*/
        mainwindow->setWindowState(Qt::WindowMaximized);
        mainwindow->show();


    }else
    {
        ui->userName->clear();
        ui->userPassword->clear();
        ui->loginLabel->setText("Authentification echoué : Invalide identifiant ou mot de passe !");
    }

}

bool login::Login(QString u, QString p)
{

    QString id,mdp;
    QSqlQuery* query = new QSqlQuery();


    if(u=="" || p=="")
    {
        return false;
    }
    query->exec("select ID,PASSWORD FROM AGENT");
    while (query->next())
    {
         id = query->value("ID").toString();
         mdp= query->value("PASSWORD").toString();
         if(u==id && p==mdp)
             return true;
    }
    return false;
}

void login::UpadateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    ui->time->setText(text);
}

void login::on_shutDown_clicked()
{
    close();
}

