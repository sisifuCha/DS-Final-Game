#include "rankdlg.h"
#include "ui_rankdlg.h"

RankDlg::RankDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RankDlg)
{
    ui->setupUi(this);
}

RankDlg::~RankDlg()
{
    delete ui;
}
