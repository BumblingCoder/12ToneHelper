#ifndef TONENAMEWIDGET_H
#define TONENAMEWIDGET_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class toneNameWidget;
}

enum arrowDirection{
    up,
    down,
    left,
    right
};

class toneNameWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit toneNameWidget(QWidget *parent = 0);
    void setNote(int note);
    void displayArrow(arrowDirection direction);
    void clearArrow(arrowDirection direction);
    ~toneNameWidget();
    
private:
    void setBackground();

private:
    Ui::toneNameWidget *ui;
    int note = 0;
    QLabel* text;
    bool u = false;
    bool d = false;
    bool l = false;
    bool r = false;
    QPixmap background;
};

#endif // TONENAMEWIDGET_H
