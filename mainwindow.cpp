#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTimer>

sudoku::matrix matx;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Timer = new QTimer;
    Timerecord = new QTime(0,0,0,0);
    ui->timer->setDigitCount(8);
    ui->timer->setSegmentStyle(QLCDNumber::Flat);
    ui->timer->display(Timerecord->toString("hh:mm:ss"));
    connect(Timer,SIGNAL(timeout()),this,SLOT(timeupdate()));
    timerstart();

    matx.new_puzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(128, 128, 128);
                Cell->setBackgroundColor(c);

            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_table_cellClicked(int row, int column)
{
    Row = row;
    Column = column;
    QString str = "";
}

void MainWindow::click_on(int num)
{
    QTableWidgetItem* Cell = ui->table->item(Row, Column);
    matx.write(Row, Column, num);
    QString str = "";
    str += '0' + matx.read(Row, Column);
    const QString cstr = str;
    Cell->setText(cstr);
    if (matx.you_win())
    {
       Timer->stop();
       QMessageBox msgBox;
       msgBox.setText("You Win!!");
       msgBox.exec();
    }
}


void MainWindow::on_pushButton_1_clicked()
{
   click_on(1);

}

void MainWindow::on_pushButton_2_clicked()
{
    click_on(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    click_on(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    click_on(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    click_on(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    click_on(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    click_on(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    click_on(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    click_on(9);
}

void MainWindow::on_Solve_clicked()
{
    matx.reset();
    matx.solve();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i,j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}

void MainWindow::on_New_Game_clicked()
{
    matx.new_puzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
            if (matx.read(i, j))
            {
                QColor c(128, 128, 128);
                Cell->setBackgroundColor(c);
            }
            else
            {
                QColor c(255,255,255);
                Cell->setBackgroundColor(c);
            }
        }
    }
    ui->timer->display(Timerecord->toString("hh:mm:ss"));
    timerstart();

}

void MainWindow::on_Reset1_clicked()
{
    matx.reset();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->table->item(i, j);
            QString str = "";
            str += '0' + matx.read(i, j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}

void MainWindow::on_Quit_clicked()
{
   QCoreApplication::quit();
}

void MainWindow::timerstart()
{
    Timerecord->setHMS(0,0,0,0);
    ui->timer->display(Timerecord->toString("hh:mm:ss"));
    Timer->start(1000);
}


void MainWindow::timeupdate()
{

    *Timerecord=Timerecord->addSecs(1);
    ui->timer->display(Timerecord->toString("hh:mm:ss"));
}
