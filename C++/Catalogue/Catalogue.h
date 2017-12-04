
/*************************************************************************
                                  Catalogue
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Liste.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe permet de gérer plusieurs trajets
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Affiche() const;
    // Mode d'emploi : affiche les trajets du contexte appelant
    //
    // Contrat : aucun
    //
    
	void Add(Trajet* t);
    // Mode d'emploi : ajoute un trajet possible
    //
    // Contrat : aucun
    //
    
	unsigned int RechercheParcours(const char* depart, const char* arrivee);
    // Mode d'emploi : recherche de trajets qui vont de depart à arrivee et renvoie le nombre de solution
    //
    // Contrat : aucun
    //
    
	unsigned int RechercheParcoursAvancee(const char* depart, const char* arrivee);
    // Mode d'emploi : recherche de compositions de trajets qui vont de depart à arrivee et renvoie le nombre de solution
    //
    // Contrat : aucun
    //

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

    virtual ~Catalogue ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

//---------------------------------------------------------------- PROTEGE

protected:
//----------------------------------------------------- Attributs protégés
	Liste* liste;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

