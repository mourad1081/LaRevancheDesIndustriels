#include "parametresson.h"
#include "ui_parametresson.h"

ParametresSon::ParametresSon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParametresSon)
{
    ui->setupUi(this);
}

ParametresSon::~ParametresSon()
{
    delete ui;
}

bool ParametresSon::isSonActif()
{
    return ui->checkBoutonActiverSon->isChecked();
}



int ParametresSon::getVolume()
{
    return ui->sliderVolume->value();
}
