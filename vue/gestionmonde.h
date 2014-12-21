#ifndef GESTIONMONDE_H
#define GESTIONMONDE_H
#include "vue/monde.h"

class GestionMonde
{
private:
    Monde *monde;
public:
    GestionMonde();
    static void gererEvenements();
};

#endif // GESTIONMONDE_H
