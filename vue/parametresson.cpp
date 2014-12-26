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

bool ParametresSon::isMusiqueInfinie()
{
    return ui->checkBoutonSonInfini->isChecked();
}

Difficulte ParametresSon::getDifficulte()
{
    if(ui->radioDifficulteNormal->isChecked())
        return Difficulte::NORMAL;
    else if(ui->radioDifficulteConnard->isChecked())
        return Difficulte::CONNARD;
    else
        return Difficulte::FACILE;
}

int ParametresSon::getNbVies()
{
    return ui->spinVies->value();
}

int ParametresSon::getVolume()
{
    return ui->sliderVolume->value();
}
