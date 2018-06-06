#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->userResult->setVisible(false);
    ui->countryResult->setVisible(false);
    ui->pwResult->setVisible(false);
    ui->reasonResult->setVisible(false);
    ui->registerResult->setVisible(false);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::on_pushButton_clicked()
{
    int counter=0;
    QString username="";
    username=ui->lineEdit_2->text();
    QStringRef qsr(&username, username.length()-16, 16);
    if(qsr!="@sabanciuniv.edu")
    {
          ui->userResult->setVisible(true);
    }
    else
    {
        counter+=25;
        on_progressBar_valueChanged(counter);
    }
    QString pw1="",pw2="";
    pw1=ui->lineEdit->text();
    pw2=ui->lineEdit_3->text();
    if(pw1!=pw2)
    {
        ui->pwResult->setVisible(true);
    }
    else
    {
        counter+=25;
        on_progressBar_valueChanged(counter);
    }
    if(ui->comboBox->currentText()==false)
    {
        ui->countryResult->setVisible(true);
    }
    else
    {
        counter+=25;
        on_progressBar_valueChanged(counter);
    }
    if(ui->checkBox_3->isChecked()&&ui->checkBox->isChecked()&&ui->checkBox_2->isChecked())
    {
        ui->reasonResult->setVisible(true);
    }
    else
    {
        counter+=25;
        on_progressBar_valueChanged(counter);
    }
    if( ui->userResult->isVisible()==false && ui->countryResult->isVisible()==false && ui->pwResult->isVisible()==false && ui->reasonResult->isVisible()==false)
    {
        ui->registerResult->setVisible(true);
    }






}


