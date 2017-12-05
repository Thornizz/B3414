/*************************************************************************
                                 ElementListe
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---vopi- Interface de la classe <ElementListe> (fichier ElementListe.h) ----
#if ! defined ( ElementListe_H )
#define ElementListe_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <ElementListe>
// Cette classe permet d'implémenter les éléments de la classe liste.
//
//------------------------------------------------------------------------

class ElementListe
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur
	ElementListe (const Trajet* t);
    // Mode d'emploi : d le départ du trajet, a l'arrivée du trajet et mT le moyen de transport du trajet
    //
    // Contrat : aucun
    //

    virtual ~ElementListe ( );
    // Mode d'emploi : aucun
    //
    // Contrat : aucun
    //

//----------------------------------------------------- Attributs publiques
const Trajet * trajet;
ElementListe * suivant;
};

//-------------------------------- Autres définitions dépendantes de <ElementListe>

#endif // ElementListe_H

