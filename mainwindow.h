#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Exit_triggered();
    void on_action_About_Login_triggered();
    void on_clearButton_clicked();
    void on_usernameLineEdit_textEdited(const QString &arg1);
    void on_passwordLineEdit_textEdited(const QString &arg1);
    void on_action_Clear_triggered();

    void on_loginButton_clicked();

    void on_action_Login_triggered();

private:
    Ui::MainWindow *ui;
private:
    bool usernameLineEditEdited = false;
    bool passwordLineEditEdited = false;
    void updateState();
    void clear(QString message);
    void login();
};
#endif // MAINWINDOW_H
