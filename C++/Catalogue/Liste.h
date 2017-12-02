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
// Cette classe permet d'implémenter une liste chainée d'ElementsListe
//
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Add(Trajet* t);
    // Mode d'emploi : ajoute un trajet à la liste
    //
    // Contrat : aucun
    //

	void Affiche(const char * texte);
    // Mode d'emploi : affiche l'ensemble des trajets de la liste
    //
    // Contrat : aucun
    //
//-------------------------------------------- Constructeurs - destructeur
	Liste ();
    // Mode d'emploi : aucun
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

