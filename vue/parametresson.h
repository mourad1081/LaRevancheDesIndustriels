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
class ParametresSon : public QDialog
{
    Q_OBJECT

public:
    explicit ParametresSon(QWidget *parent = 0);
    ~ParametresSon();

    bool isSonActif();
    int getVolume();
private:
    Ui::ParametresSon *ui;
};

#endif // PARAMETRESSON_H
