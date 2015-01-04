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

/**
 * @brief Petite interface permettant de définir quelques options liées au son
 */
class ParametresSon : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Constructeur de l'interface graphique
     * @param parent Parent de l'interface
     */
    explicit ParametresSon(QWidget *parent = 0);

    /**
     * @brief Destructeur de l'interface graphique
     */
    ~ParametresSon();

    /**
     * @brief Permet de savoir si l'utilisateur a coché ou pas
     * l'option pour activer le son.
     * @return true = l'option est cochée, false = elle ne l'est pas.
     */
    bool isSonActif();

    /**
     * @brief Permet de savoir le volume choisi par l'utilisateur
     * @return Le volume
     */
    int getVolume();
private:
    Ui::ParametresSon *ui;
};

#endif // PARAMETRESSON_H
