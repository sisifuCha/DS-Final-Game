#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Setgamedlg.h>
#include <signindlg.h>
#include <rankdlg.h>
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

    setGameDlg* setGameDialog;
    SignInDialog* signInDialog;
    RankDlg* rankDlg;

    bool hasSignIn;//是否完成登录


private slots:
    void on_signInButton_clicked();

    void on_startGameButton_clicked();

    void on_checkRankButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
