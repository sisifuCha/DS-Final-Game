#ifndef SETGAMEDLG_H
#define SETGAMEDLG_H

#include <QDialog>

namespace Ui {
class setGameDlg;
}

class setGameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit setGameDlg(QWidget *parent = nullptr);
    ~setGameDlg();

private:
    Ui::setGameDlg *ui;

private slots:
    void on_chooseMusicFileButton_clicked();
    void on_volumeSlider_sliderMoved(int position);
    void on_pushButton_clicked();

};

#endif // SETGAMEDLG_H
