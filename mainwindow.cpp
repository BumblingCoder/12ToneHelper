#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGridLayout"

#include <assert.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pPositions.fill(-1,12);
    rPositions.fill(-1,12);
    iPositions.fill(-1,12);
    riPositions.fill(-1,12);

    ui->setupUi(this);
    QGridLayout* layout = new QGridLayout(this);
    this->centralWidget()->setLayout(layout);

    for(int i = 0; i< 12; i++){
        QSpinBox* spinBox = new QSpinBox(this);
        spinBox->setRange(0,11);
        layout->addWidget(spinBox,0,i+1,1,1);
        InputSpinBoxes.push_back(spinBox);

        QPushButton* button = new QPushButton(this);
        button->connect(button,SIGNAL(clicked()), this, SLOT(pButtonPressed()));
        layout->addWidget(button,i+2,0,1,1);
        pButtons.push_back(button);

        button = new QPushButton(this);
        button->connect(button,SIGNAL(clicked()), this, SLOT(rButtonPressed()));
        layout->addWidget(button,i+2,13,1,1);
        rButtons.push_back(button);

        button = new QPushButton(this);
        button->connect(button,SIGNAL(clicked()), this, SLOT(iButtonPressed()));
        layout->addWidget(button,1,i+1,1,1);
        iButtons.push_back(button);

        button = new QPushButton(this);
        button->connect(button,SIGNAL(clicked()), this, SLOT(riButtonPressed()));
        layout->addWidget(button,14,i+1,1,1);
        riButtons.push_back(button);

        for(int j = 0; j<12; j++){
            toneNameWidget* tnw = new toneNameWidget(this);
            layout->addWidget(tnw, i+2, j+1,1,1);
            grid.push_back(tnw);
        }
    }

    QPushButton* generateButton = new QPushButton("Generate", this);
    layout->addWidget(generateButton,0,13,1,1);
    connect(generateButton, SIGNAL(clicked()),this,SLOT(generateButtonPressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pButtonPressed(){
    QObject* s = sender();
    int row = -1;
    for(int i = 0; i < 12; i++){
        if( s == pButtons[i]){
            row = i;
            break;
        }
    }
    int column = pPositions[row];
    if(column > -1) grid[row*12+column]->clearArrow(right);
    column+=1;
    if (column == 12){
        column = -1;
    } else {
        grid[row*12+column]->displayArrow(right);
    }
    pPositions[row] = column;


}

void MainWindow::rButtonPressed(){
    QObject* s = sender();
    int row = -1;
    for(int i = 0; i < 12; i++){
        if( s == rButtons[i]){
            row = i;
            break;
        }
    }
    assert (row > -1);
    int column = rPositions[row];
    if(column > -1) grid[row*12+column]->clearArrow(left);
    column-=1;
    if (column == -2){
        column = 11;
    }
    if( column != -1){
           grid[row*12+column]->displayArrow(left);
    }
    rPositions[row] = column;

}

void MainWindow::iButtonPressed(){
    QObject* s = sender();
    int column = -1;
    for(int i = 0; i < 12; i++){
        if( s == iButtons[i]){
            column = i;
            break;
        }
    }
    int row = iPositions[column];
    if(row > -1) grid[row*12+column]->clearArrow(down);
    row+=1;
    if (row == 12){
        row = -1;
    } else {
        grid[row*12+column]->displayArrow(down);
    }
    iPositions[column] = row;


}

void MainWindow::riButtonPressed(){
    QObject* s = sender();
    int column = -1;
    for(int i = 0; i < 12; i++){
        if( s == riButtons[i]){
            column = i;
            break;
        }
    }
    assert (column > -1);
    int row = riPositions[column];
    if(row > -1) grid[row*12+column]->clearArrow(up);
    row-=1;
    if (row == -2){
        row = 11;
    }
    if( row != -1){
           grid[row*12+column]->displayArrow(up);
    }
    riPositions[column] = row;

}

void MainWindow::generateButtonPressed(){
    int g[12][12];
    //copy the first row.
    for(int col = 0; col<12; col++){
        g[0][col] = InputSpinBoxes[col]->value();
    }
    //figure out the first column.
    for(int i = 1; i<12; i++){
        g[i][0] = (g[i-1][0] - (g[0][i] - g[0][i-1]) + 12)%12;
    }
    //figure out the rest of the rows.
    for(int row = 1; row<12; row++){
        for(int col = 1; col<12; col++){
            g[row][col] = (g[0][col] - (g[0][0] - g[row][0] ) + 12)%12;
        }
    }

    //set all the text
    for(int row = 0; row<12; row++){
        for(int col = 0; col<12; col++){
            grid[row*12+col]->setNote(g[row][col]);
        }
    }


}

