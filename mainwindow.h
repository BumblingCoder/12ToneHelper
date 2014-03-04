#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QSpinBox>


#include <tonenamewidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void pButtonPressed();
    void rButtonPressed();
    void iButtonPressed();
    void riButtonPressed();
    void generateButtonPressed();

private:
    Ui::MainWindow *ui;
    QVector<QPushButton*> pButtons;
    QVector<QPushButton*> rButtons;
    QVector<QPushButton*> iButtons;
    QVector<QPushButton*> riButtons;
    QVector<QSpinBox*> InputSpinBoxes;
    QVector<toneNameWidget*> grid;

    QVector<int> pPositions;
    QVector<int> rPositions;
    QVector<int> iPositions;
    QVector<int> riPositions;
};

#endif // MAINWINDOW_H
