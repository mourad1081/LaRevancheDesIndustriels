#include "niveau.h"

Niveau::Niveau(int numeroDuNiveau) throw (ExceptionGame)
{
   ostringstream nomFichier;
   nomFichier << NOM_FICHIER << numeroDuNiveau << EXTENSION_FICHIER;
   // ouvre en lecture
   ifstream fichier(nomFichier.str().c_str(), ios::in);
   if ( !fichier ) {
       throw new ExceptionGame("Erreur d'ouverture du fichier de niveau");
   }
   chargerNiveauDepuisFichier(fichier);
   fichier.close();
}
int Niveau::getNbrLigne() const {
    return _nbrLigne;
}

int Niveau::getNbrColonne() const {
    return _nbrColonne;
}

vector<SDL_Rect> Niveau::getListPosMonstres() {
    return _listePosMonstres;
}

vector<vector<int>> Niveau::getNiveau()
{
    return _niveau;
}

void Niveau::chargerNiveauDepuisFichier(ifstream& fichier)
                                        throw (ExceptionGame)
{
    string baliseLigne, baliseNiveau, baliseColonne, baliseNombre;
    int numTuile;

    fichier >> baliseNiveau;
    if (baliseNiveau.compare(BALISE_FICHIER_NIVEAU)){
        throw new
        ExceptionGame("Votre fichier ne contient pas la balise #NIVEAU");
    }

    fichier >> baliseNombre;
    if (baliseNombre.compare(BALISE_NOMBRE_MONSTRE) ) {
        throw new
        ExceptionGame("Votre fichier ne contient pas la balise #NOMBRE_MONSTRE");
    } else {
        fichier >> _nbrMonstres;
    }

    _listePosMonstres.resize(_nbrMonstres);

    SDL_Rect posMonstre;
    int val;
    for ( int i=0; i < _nbrMonstres ; i++){
        fichier >> val;
        posMonstre.x = val;
        fichier >> val;
        posMonstre.y = val;
        fichier >> val;
        posMonstre.w = val;
        fichier >> val;
        posMonstre.h = val;
        _listePosMonstres[i] = posMonstre;
    }

    fichier >> baliseLigne;
    if (baliseLigne.compare(BALISE_LIGNE_NIVEAU) ) {
        throw new
        ExceptionGame("Votre fichier ne contient pas la balise #LIGNE");
    } else {
        fichier >> _nbrLigne;
    }

    fichier >> baliseColonne;
    if ( baliseColonne.compare(BALISE_COLONNE_NIVEAU)) {
        throw new
        ExceptionGame("Votre fichier ne contient pas la balise #COLONNE");
    } else {
        fichier >> _nbrColonne;
    }
    _niveau.resize(_nbrLigne
                   ,std::vector<int>(_nbrColonne));

    for ( int i=0; i < _nbrLigne ; i++){
        for ( int j=0; j < _nbrColonne ; j++){
            fichier >> numTuile;
            _niveau[i][j] = numTuile;
        }
    }
}

