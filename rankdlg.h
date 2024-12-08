#ifndef RANKDLG_H
#define RANKDLG_H

#include <QDialog>

namespace Ui {
class RankDlg;
}

class RankDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RankDlg(QWidget *parent = nullptr);
    ~RankDlg();

private:
    Ui::RankDlg *ui;
};

#endif // RANKDLG_H
