#include "tonenamewidget.h"
#include "ui_tonenamewidget.h"

#include <QPainter>

toneNameWidget::toneNameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toneNameWidget)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout;
    ui->imageLabel->setLayout(layout);
    text = new QLabel(ui->imageLabel);
    text->setAlignment(Qt::AlignCenter);
    ui->imageLabel->setText("");
    text->setText("c");
    layout->addWidget(text);

}

toneNameWidget::~toneNameWidget()
{
    delete ui;
}

void toneNameWidget::displayArrow(arrowDirection direction){
    if(direction == up) u = true;
    if(direction == down) d = true;
    if(direction == left) l = true;
    if(direction == right) r = true;
    setBackground();
}

void toneNameWidget::clearArrow(arrowDirection direction){
    if(direction == up) u = false;
    if(direction == down) d = false;
    if(direction == left) l = false;
    if(direction == right) r = false;
    setBackground();
}

void toneNameWidget::setBackground(){
    background = QPixmap(":/images/empty");
    QPainter painter(&background);
    if(u == true) painter.drawPixmap(0,0,background.width(),background.height(),QPixmap(":/images/up"));
    if(d == true) painter.drawPixmap(0,0,background.width(),background.height(),QPixmap(":/images/down"));
    if(l == true) painter.drawPixmap(0,0,background.width(),background.height(),QPixmap(":/images/left"));
    if(r == true) painter.drawPixmap(0,0,background.width(),background.height(),QPixmap(":/images/right"));
    ui->imageLabel->setPixmap(background);
}

void toneNameWidget::setNote(int note){
    if(note == 0) text->setText("C");
    if(note == 1) text->setText("C#");
    if(note == 2) text->setText("D");
    if(note == 3) text->setText("D#");
    if(note == 4) text->setText("E");
    if(note == 5) text->setText("F");
    if(note == 6) text->setText("F#");
    if(note == 7) text->setText("G");
    if(note == 8) text->setText("G#");
    if(note == 9) text->setText("A");
    if(note == 10) text->setText("A#");
    if(note == 11) text->setText("B");
}
