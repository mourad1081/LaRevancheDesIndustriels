#ifndef PARAMETRESSON_H
#define PARAMETRESSON_H
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QRadioButton>
#include <QDialog>

namespace Ui {
class ParametresSon;
}
enum Difficulte {FACILE, NORMAL, CONNARD};
class ParametresSon : public QDialog
{
    Q_OBJECT

public:
    explicit ParametresSon(QWidget *parent = 0);
    ~ParametresSon();

    bool isSonActif();
    bool isMusiqueInfinie();
    Difficulte getDifficulte();
    int getNbVies();
    int getVolume();
private:
    Ui::ParametresSon *ui;
};

#endif // PARAMETRESSON_H
