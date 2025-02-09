#include <iostream>

#include <QtWidgets>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    passwordLineEdit->setPlaceholderText("enter-you-password-here");
    connect(passwordLineEdit, &QLineEdit::textEdited, this, &MainWindow::on_passwordLineEdit_textEdited);

    ui->gridLayout->addWidget(passwordLineEdit,1,1);

    // Set the tab order:
    QWidget::setTabOrder(ui->usernameLineEdit, passwordLineEdit);
    QWidget::setTabOrder(passwordLineEdit,ui->rememberDetails);
    QWidget::setTabOrder(ui->rememberDetails, ui->loginButton);
    QWidget::setTabOrder(ui->loginButton, ui->clearButton);
    QWidget::setTabOrder(ui->clearButton, ui->usernameLineEdit);

    setFixedSize(width(),height());
    updateState();

    QString message = tr("Enter your login details to continue...");
    statusBar()->showMessage(message);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_action_Exit_triggered() {
    QApplication::quit();
}

void MainWindow::on_action_About_Login_triggered() {
    QMessageBox::about(this, tr("About Login"),
                       tr("The application is an example of a basic QT application."));
}

void MainWindow::on_clearButton_clicked() {
    QString message = tr("The login form has been cleared...");
    clear(message);
}

void MainWindow::on_action_Clear_triggered() {
    QString message = tr("The login form has been cleared...");
    clear(message);
}

void MainWindow::clear(QString message) {
    ui->usernameLineEdit->clear();
    passwordLineEdit->clear();
    usernameLineEditEdited = false;
    passwordLineEditEdited = false;
    updateState();

    statusBar()->showMessage(message);

}

void MainWindow::login() {

    QString message = tr("Logging in...");
    statusBar()->showMessage(message);

    std::cout << "Username: " << ui->usernameLineEdit->text().toStdString() << std::endl;
    std::cout << "Password: " << passwordLineEdit->text().toStdString() << std::endl;
    std::cout << "Remember details: " << ( ui->rememberDetails->isChecked() ? "true" : "false" ) << std::endl;
    std::cout << std::endl;

    // Lock out the buttons and menus until the next clear...
    ui->clearButton->setEnabled(false);
    ui->loginButton->setEnabled(false);
    ui->action_Clear->setEnabled(false);
    ui->action_Login->setEnabled(false);

    // Main login code would be here...

    QTimer::singleShot(3000, this, [this]() {
        QString message = tr("Logged in...");
        clear(message);
    });

}

void MainWindow::on_usernameLineEdit_textEdited(const QString &arg1) {
    usernameLineEditEdited = !ui->usernameLineEdit->text().isEmpty();
    updateState();
}

void MainWindow::on_passwordLineEdit_textEdited(const QString &arg1) {
    passwordLineEditEdited = !passwordLineEdit->text().isEmpty();
    updateState();
}

void MainWindow::updateState() {
    ui->clearButton->setEnabled(passwordLineEditEdited | usernameLineEditEdited);
    ui->loginButton->setEnabled(passwordLineEditEdited && usernameLineEditEdited);
    ui->action_Clear->setEnabled(passwordLineEditEdited | usernameLineEditEdited);
    ui->action_Login->setEnabled(passwordLineEditEdited && usernameLineEditEdited);

}

void MainWindow::on_loginButton_clicked() {
    login();
}


void MainWindow::on_action_Login_triggered() {
    login();
}

