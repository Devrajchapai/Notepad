#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()      //new
{
    file_path_ = "";
    ui->textEdit->setText("");

}


void MainWindow::on_actionOpen_triggered()       //open
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","file not open");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);

    file.close();
}


void MainWindow::on_actionSave_triggered()      //save
{

    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()           //save_as
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.flush();
    file.close();
}


void MainWindow::on_actionCopy_triggered()          //copy
{
    ui->textEdit->copy();
}


void MainWindow::on_actioncut_triggered()           //cut
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPast_triggered()          //paste
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()      //redo
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()      //undo
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()     //about
{

    QMessageBox::about(this,"About","This Notepad is created by: \n\nKrikita Bhatta\nKripa Sherestha\nSamikshya Sherestha\nSpriha Sharma\nRakshya Aryal\nRojina Adhikari" );
}


