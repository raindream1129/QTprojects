#include "totalizer.h"
#include "ui_totalizer.h"

totalizer::totalizer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalizer)
{
    ui->setupUi(this);
}

totalizer::~totalizer()
{
    delete ui;
}
