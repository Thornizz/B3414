/*************************************************************************
                                  Liste
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---vopi- Interface de la classe <Liste> (fichier Liste.h) ----
#if ! defined ( Liste_H )
#define Liste_H

//--------------------------------------------------- Interfaces utilisées
#include "ElementListe.h"

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
// Cette classe permet d'implémenter une liste chaine d'ElementsListe
//
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Add(Trajet* t);
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

	void Affiche();
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //
//-------------------------------------------- Constructeurs - destructeur
	Liste ();
    // Mode d'emploi : d le départ du ElementListe, a l'arrivée du ElementListe et mT le moyen de transport du ElementListe
    //
    // Contrat : aucun
    //

    virtual ~Liste ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

//----------------------------------------------------- Attributs publiques
	ElementListe * first;
};

#endif // Liste_H

