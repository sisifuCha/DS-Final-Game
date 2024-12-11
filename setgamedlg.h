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
    int gameMode;//游戏模式选择，0代表默认模式，1代表平衡模式

private:
    Ui::setGameDlg *ui;

private slots:
    void on_chooseMusicFileButton_clicked();
    void on_volumeSlider_sliderMoved(int position);
    void on_pushButton_clicked();

    void on_startButton_clicked();
    void on_modeChoseButton_clicked();
    void on_modeChoseButton_2_clicked();
};

#endif // SETGAMEDLG_H
