#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include "include.h"
#include <QFont>
#include <QTimer>
#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_table_cellClicked(int row, int column);

    void on_Solve_clicked();
    void on_New_Game_clicked();
    void on_Reset1_clicked();
    void on_Quit_clicked();

    void timerstart();
    void timeupdate();


private:
    Ui::MainWindow *ui;
    QTimer*Timer;
    QTime*Timerecord;
    int Column, Row;
    void click_on(int num);
};

#endif // MAINWINDOW_H

