#ifndef QPASSWORDLINEEDIT_H
#define QPASSWORDLINEEDIT_H

#include <QAction>
#include <QLineEdit>
#include <QToolButton>

class QPasswordLineEdit: public QLineEdit
{
public:
    QPasswordLineEdit(QWidget *parent=nullptr);
    void clear();
private slots:
    void onPressed();
    void onReleased();
private:
    QToolButton *button;
};

#endif // QPASSWORDLINEEDIT_H
