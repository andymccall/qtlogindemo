#include "qpasswordlineedit.h"

QPasswordLineEdit::QPasswordLineEdit(QWidget *parent):
    QLineEdit(parent)
{
    setEchoMode(QLineEdit::Password);
    QAction *action = addAction(QIcon(":/assets/eyeOff.png"), QLineEdit::TrailingPosition);
    button = qobject_cast<QToolButton *>(action->associatedObjects().last());
    button->show();
    button->setCursor(QCursor(Qt::PointingHandCursor));
    connect(button, &QToolButton::pressed, this, &QPasswordLineEdit::onPressed);
    connect(button, &QToolButton::released, this, &QPasswordLineEdit::onReleased);
}

void QPasswordLineEdit::onPressed(){
    QToolButton *button = qobject_cast<QToolButton *>(sender());
    button->setIcon(QIcon(":/assets/eyeOn.png"));
    setEchoMode(QLineEdit::Normal);
}

void QPasswordLineEdit::onReleased(){
    QToolButton *button = qobject_cast<QToolButton *>(sender());
    button->setIcon(QIcon(":/assets/eyeOff.png"));
    setEchoMode(QLineEdit::Password);
}

void QPasswordLineEdit::clear() {

    QLineEdit::clear();

    button->show();

}
